#include "onlineservicethread.hpp"


OnlineServiceThread::OnlineServiceThread(QObject *parent /*= NULL*/) :
    QThread(parent),
    mLogging("thread.OnlineServiceThread")
{

}

OnlineServiceThread::~OnlineServiceThread()
{

}

void OnlineServiceThread::initthread()
{  
    mtimer.moveToThread(this);
}

void OnlineServiceThread::initobjects(void)
{

}

void OnlineServiceThread::run()
{
    mLogging << "Hello OnlineServiceThread TID: " <= this->currentThreadId();
    initobjects();
    startTimer(1000);
    int code = exec();
    stopTimer();
    mLogging << "run: exit code: " <= code;
}

void OnlineServiceThread::timerHit()
{
    mLogging <= "timerHit ";
}

void OnlineServiceThread::startTimer(int32_t ms)
{
    connect(&mtimer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    mtimer.setInterval(ms);
    mtimer.start();
}

void OnlineServiceThread::stopTimer()
{
    mtimer.stop();
}
