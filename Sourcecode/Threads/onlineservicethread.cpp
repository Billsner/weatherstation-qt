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
    mDownloadManager.moveToThread(this);
    mDownloadManager.movetoThread(this);
}

void OnlineServiceThread::initobjects(void)
{
    mDownloadManager.init();
}

void OnlineServiceThread::run()
{
    (mLogging << "Hello OnlineServiceThread TID: ") <= this->currentThreadId();
    initobjects();
    startTimer(1000);
    int code = exec();
    stopTimer();
    (mLogging << "run: exit code: ") <= code;
}

void OnlineServiceThread::timerHit()
{
    mLogging <= "timerHit ";
    static uint32_t time = 0;
    if(time == 10)
    {
        QUrl myurl("https://opendata.dwd.de/weather/text_forecasts/html/VHDL50_DWEG_030834_html");
        mDownloadManager.doDownload(myurl);
        time++;
    }
    else
    {
        time++;
    }

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
