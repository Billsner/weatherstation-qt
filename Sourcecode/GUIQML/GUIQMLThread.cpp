#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "GUIQMLThread.hpp"
#include <QTimer>
#include <QTime>

GUIQMLThread::GUIQMLThread(QObject *parent): QThread(parent), m_categrory("GUIQMLThread")
{
    qCDebug(m_categrory) << "Constructer";
}

GUIQMLThread::~GUIQMLThread()
{
    qCDebug(m_categrory) << "Destructer";
}

void GUIQMLThread::init(void)
{

}

void GUIQMLThread::run()
{
    qCDebug(m_categrory) << "Hello GUIQMLThread TID: " << this->currentThreadId();

//    QQmlApplicationEngine engine;
//    qCDebug(m_categrory) << "Load engine";
//    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
//    int size =  engine.rootObjects().size();
//    qCDebug(m_categrory) << "size " << size;
//    QObject * item = engine.rootObjects().value(0);

    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(1000);
    timer.start();   

    int code = exec();
    qCDebug(m_categrory) << "EXEC.Code " << code;
}

void GUIQMLThread::timerHit()
{
    qCDebug(m_categrory) << QTime::currentTime() << " timerHit TID: " << this->currentThreadId();
}
