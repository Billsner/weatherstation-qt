#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "Threads/DatapoolThread.hpp"
#include "Threads/WeatherThread.hpp"
#include "GUIQML/GetQMLObject.hpp"
#include "Utils/Logging.hpp"
#include "Utils/LoggingServer.hpp"

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
    //mWeatherThread.start(QThread::NormalPriority);

    app.exec();
    logger <= "app.exec";

    logger <= "thread exit";
    mDatapoolThread.quit();
    //mWeatherThread.quit();
    mDatapoolThread.wait(100); // todo check if it is valid to call wait after quit
    GetQMLObject::DestroyGetQMLObject();
    cLoggingServer.finish();
    return 1;
}
