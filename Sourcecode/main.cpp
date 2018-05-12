#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QLoggingCategory>
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
    QObject * item = engine.rootObjects().value(0);
    if(item == NULL)
    {
         qCDebug(categrory) << "item == NULL ";
    }
    QObject * myObject= item->findChild<QObject*>("sidebaralarm");
    if(myObject == NULL)
    {
        qCDebug(categrory) << "myObject == NULL ";
    }

    QObject * myclock= item->findChild<QObject*>("sidebar");
    if(myclock == NULL)
    {
        qCDebug(categrory) << "myclock == NULL ";
    }

    Thread1 thread1;
    Thread2 thread2;

    thread1.init();
    thread1.setClockObject(myclock);

    QObject::connect(myObject, SIGNAL(sidbarsignal(int)), thread1.getObject(), SLOT(receiveSwitch(int)), Qt::QueuedConnection);  
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


    return 1;
}
