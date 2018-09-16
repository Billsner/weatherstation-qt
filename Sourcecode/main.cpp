#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "Threads/DatapoolThread.hpp"
#include "GUIQML/GetQMLObject.hpp"
#include "Utils/Logging.hpp"
#include "Utils/LoggingServer.hpp"

int main(int argc, char *argv[])
{
    LoggingServer cLoggingServer;
    cLoggingServer.init();

    Logging logger("main",true,false,LLdebug);
    logger << LLcritical << "Start TID " <= QThread::currentThreadId();


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    logger <= "Load engine";
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    int size =  engine.rootObjects().size();
    logger << "size " <= size;

    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();

    if(NULL != pGetQMLObject)
    {
        pGetQMLObject->SetQMLEngineRootObject(engine.rootObjects().value(0));
    }
    else
    {
        logger <= "No Object";
    }

    DatapoolThread mDatapoolThread;
    mDatapoolThread.initthread();
    mDatapoolThread.start(QThread::HighPriority);

    app.exec();
    logger <= "app.exec";

    logger <= "thread exit";
    mDatapoolThread.quit();
    mDatapoolThread.wait(100);
    GetQMLObject::DestroyGetQMLObject();
    cLoggingServer.finish();
    return 1;
}
