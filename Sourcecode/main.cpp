#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "Threads/datapoolthread.hpp"
#include "Threads/weatherthread.hpp"
#include "GUIQML/getqmlobject.hpp"
#include "Utils/logging.hpp"
#include "Utils/loggingserver.hpp"

int main(int argc, char *argv[])
{
    LoggingServer cLoggingServer;
    cLoggingServer.init();

    Logging logger("main");
    logger << LLcritical << "Start TID " <= QThread::currentThreadId();


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //Create QQmlApplicationEngine
    QQmlApplicationEngine engine;
    logger <= "Load engine";
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    int size =  engine.rootObjects().size();
    logger << "size " <= size;

    //Forward rootobject to Object-class
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(NULL != pGetQMLObject)
    {
        pGetQMLObject->SetQMLEngineRootObject(engine.rootObjects().value(0));
    }
    else
    {
        logger <= "No Object";
    }

    //start DatapoolThread
    DatapoolThread mDatapoolThread;
    mDatapoolThread.initthread();
    mDatapoolThread.start(QThread::HighPriority);

    //start WeatherThread
    WeatherThread mWeatherThread;
    mWeatherThread.initthread();
    mWeatherThread.start(QThread::NormalPriority);

    app.exec();
    logger <= "app.exec";

    logger <= "thread exit";
    mDatapoolThread.quit();
    mDatapoolThread.wait(10); // todo check if it is valid to call wait after quit
    mWeatherThread.quit();
    mWeatherThread.wait(10);
    GetQMLObject::DestroyGetQMLObject();
    cLoggingServer.finish();
    return 1;
}
