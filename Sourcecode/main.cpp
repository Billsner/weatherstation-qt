#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QLoggingCategory>
#include "Datapool/DatapoolThread.hpp"
#include "GUIQML/GetQMLObject.hpp"
#include "thread1.hpp"
#include "thread2.hpp"

int main(int argc, char *argv[])
{
    QLoggingCategory categrory("main");
    qCDebug(categrory) << "Start TID " << QThread::currentThreadId();   


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qCDebug(categrory) << "Load engine";
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    int size =  engine.rootObjects().size();
    qCDebug(categrory) << "size " << size;

    DatapoolThread mDatapoolThread;
    mDatapoolThread.start(QThread::HighPriority);

    Thread1 thread1;
    Thread2 thread2;

    thread1.init();

    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();


    if(NULL != pGetQMLObject)
    {
        pGetQMLObject->SetQMLEngineRootObject(engine.rootObjects().value(0));
        thread1.setClockObject(pGetQMLObject->GetSpcificQMLObject("sidebar"));
        QObject::connect(pGetQMLObject->GetSpcificQMLObject("sidebaralarm"), SIGNAL(sidbarsignal(int)), thread1.getObject(), SLOT(receiveSwitch(int)), Qt::QueuedConnection);
    }
    else
    {
        qCDebug(categrory) << "No Object";
    }


    QObject::connect(thread1.getObject(), SIGNAL(sendtoThread2(int)), &thread2, SLOT(receiveThread1Count(int)), Qt::QueuedConnection);
    QObject::connect(&thread2, SIGNAL(sendtoThread1(int)), thread1.getObject(), SLOT(receiveThread2Count(int)), Qt::QueuedConnection);

    qCDebug(categrory) << "Start Thread1";
    thread1.start(QThread::NormalPriority);
    qCDebug(categrory) << "Start Thread2";
    thread2.start(QThread::LowPriority);

    qCDebug(categrory) << "Thread startet";

    app.exec();
    qCDebug(categrory) << "app.exec";

    thread1.quit();
    thread1.wait(10);
    thread2.quit();
    thread2.wait(10);

    qCDebug(categrory) << "thread exit";
    mDatapoolThread.quit();
    mDatapoolThread.wait(100);
    GetQMLObject::DestroyGetQMLObject();

    return 1;
}
