#include "thread1.hpp"
#include <QTimer>
#include <QTime>

Thread1::Thread1(QObject *parent): QThread(parent), m_categrory("Thread1")
{
    qCDebug(m_categrory) << "Constructer";
}

Thread1::~Thread1()
{
    qCDebug(m_categrory) << "Destructer";
}

void Thread1::init(void)
{
    m_ObjectThread1.moveToThread(this);
}

void Thread1::run()
{
    qCDebug(m_categrory) << "Hello Thread1 TID: " << this->currentThreadId();
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(1000);
    timer.start();
    int code = exec();
    qCDebug(m_categrory) << "EXEC.Code " << code;
}

void Thread1::timerHit()
{
    qCDebug(m_categrory) << QTime::currentTime() << " timerHit TID: " << this->currentThreadId();
    m_ObjectThread1.triggertimer();
    QTime time = QTime::currentTime();
    m_ObjectThread1.setClock(time.toString(""));
}

void Thread1::receiveThread2Count(int count)
{
    qCDebug(m_categrory) << "receiveThread2Count count: " << count << " TID: " << this->currentThreadId();
}
