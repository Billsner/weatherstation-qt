#include "onlineservicethread.hpp"
#include "Datapool/datapoolinterface.hpp"
#include <QDate>


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
    //mLogging <= "timerHit ";
    static uint32_t time = 0;
    if(time == 10)
    {
        startDownload();
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

void OnlineServiceThread::startDownload()
{
    int32_t requeststate = 0;
    mDatapoolInterface.getDatapoolInt(DIWeatherDownloadRequest,requeststate);
    if(requeststate == 1)
    {
        QUrl myurl("https://opendata.dwd.de/weather/local_forecasts/mos/MOSMIX_L/single_stations/10488/kml/MOSMIX_L_LATEST_10488.kmz");
        mDownloadManager.doDownload(myurl);
        mDatapoolInterface.setDatapoolInt(DIWeatherDownloadRequest,0);
        QString date = QDate::currentDate().toString(defaultformate);
        mDatapoolInterface.setDatapoolQString(DIWaetherDownloadDate,date);
        mLogging <= "startDownload";
    }
}
