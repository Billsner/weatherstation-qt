#include "thread2.hpp"
#include <QTimer>

Thread2::Thread2(QObject *parent):QThread(parent), m_categrory("Thread2")
{
    qCDebug(m_categrory) << "Constructer";
}

Thread2::~Thread2()
{
    qCDebug(m_categrory) << "Destructer";
}

void Thread2::run()
{
    qCDebug(m_categrory) << "Hello TID: " << this->currentThreadId();
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(1000);
    timer.start();
    int code = exec();
    qCDebug(m_categrory) << "EXEC.Code " << code;
}

void Thread2::timerHit()
{
    qCDebug(m_categrory) << "timerHit TID: " << this->currentThreadId();
    static int counter = 10;
    counter++;
    sendtoThread1(counter);
}

void Thread2::receiveThread1Count(int count)
{
    qCDebug(m_categrory) << "receiveThread1Count count: " << count << " TID: " << this->currentThreadId();
}
