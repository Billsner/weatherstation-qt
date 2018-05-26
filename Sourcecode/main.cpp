#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QLoggingCategory>
#include "Threads/DatapoolThread.hpp"
#include "GUIQML/GetQMLObject.hpp"

int main(int argc, char *argv[])
{
    QLoggingCategory categrory("main");    
    QLoggingCategory::setFilterRules(QStringLiteral("thread.DatapoolThread=false"));
    qCDebug(categrory) << "Start TID " << QThread::currentThreadId();   


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qCDebug(categrory) << "Load engine";
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    int size =  engine.rootObjects().size();
    qCDebug(categrory) << "size " << size;

    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();

    if(NULL != pGetQMLObject)
    {
        pGetQMLObject->SetQMLEngineRootObject(engine.rootObjects().value(0));
    }
    else
    {
        qCDebug(categrory) << "No Object";
    }

    DatapoolThread mDatapoolThread;
    mDatapoolThread.initthread();
    mDatapoolThread.start(QThread::HighPriority);

    app.exec();
    qCDebug(categrory) << "app.exec";

    qCDebug(categrory) << "thread exit";
    mDatapoolThread.quit();
    mDatapoolThread.wait(100);
    GetQMLObject::DestroyGetQMLObject();

    return 1;
}
