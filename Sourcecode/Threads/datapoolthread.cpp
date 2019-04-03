#include "datapoolthread.hpp"
#include <QTimer>

DatapoolThread::DatapoolThread(QObject *parent):
    QThread(parent),
    mLogging("thread.DatapoolThread")
{

}

DatapoolThread::~DatapoolThread()
{

}

void DatapoolThread::initthread()
{
    mQMLSettings.moveToThread(this);
    mQMLStatusLine.moveToThread(this);
    mtimer.moveToThread(this);
}

void DatapoolThread::initobjects(void)
{
    (mLogging << "initobjects TID: ") <= this->currentThreadId();
    mDatapoolControll.loadDatapool();
    mQMLSettings.init();
    mQMLStatusLine.init();    
    mQMLSettings.setDataformat2GUI();

}

void DatapoolThread::run()
{
    (mLogging << "Hello DatapoolThread TID: ") <= this->currentThreadId();
    initobjects();

    mQMLStatusLine.triggertimer();

    startTimer(1000);
    int code = exec();
    stopTimer();
    (mLogging << "EXEC.Code ") <= code;
}

void DatapoolThread::startTimer(int32_t ms)
{
    connect(&mtimer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    mtimer.setInterval(ms);
    mtimer.start();
}

void DatapoolThread::stopTimer()
{
    mtimer.stop();
}

void DatapoolThread::timerHit()
{
    (mLogging << " timerHit TID: ") <= this->currentThreadId();
    mQMLStatusLine.triggertimer();
    mQMLSettings.triggertimer();

    static int count = 10;
    if(0 == count)
    {
        count = 10;
        mDatapoolControll.saveDatapool();
    }
    else
    {
        count--;
    }

}
