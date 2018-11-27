#include "WeatherThread.hpp"


WeatherThread::WeatherThread(QObject *parent /*= NULL*/) :
    QThread(parent),
    mLogging("thread.WeatherThread")
{

}

WeatherThread::~WeatherThread()
{

}

void WeatherThread::initthread()
{
    mQMLWeather.moveToThread(this);
    mtimer.moveToThread(this);
}

void WeatherThread::initobjects(void)
{
    mQMLWeather.init();
}

void WeatherThread::run()
{
    mLogging << "Hello WeatherThread TID: " <= this->currentThreadId();
    initobjects();
    startTimer(1000);
    int code = exec();
    mLogging << "run: exit code: " <= code;
}

void WeatherThread::timerHit()
{
    mQMLWeather.triggertimer();
    mLogging << "timerHit ";
}

void WeatherThread::startTimer(int ms)
{
    connect(&mtimer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    mtimer.setInterval(ms);
    mtimer.start();
}
