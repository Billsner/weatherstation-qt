#include "DatapoolThread.hpp"
#include "Datapool/DatapoolInterface.hpp"
#include <QTimer>
#include <QTime>

DatapoolThread::DatapoolThread(QObject *parent):
    QThread(parent),
    mLogging("thread.DatapoolThread",false,true)
{

}

DatapoolThread::~DatapoolThread()
{

}

void DatapoolThread::initthread()
{
    mQMLDateTime.moveToThread(this);
}

void DatapoolThread::initobjects(void)
{
    mLogging << "initobjects TID: " <= this->currentThreadId();    
    mDatapoolControll.loadDatapool();
    mQMLDateTime.init();
    mQMLDateTime.setDataformat2GUI();

}

void DatapoolThread::run()
{
    mLogging << "Hello DatapoolThread TID: " <= this->currentThreadId();
    initobjects();

    mQMLDateTime.triggertimer();

    //Timer
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(1000);
    timer.start();    
    int code = exec();
    mLogging << "EXEC.Code " <= code;
}

void DatapoolThread::timerHit()
{
    mLogging << QTime::currentTime().toString().toStdString() << " timerHit TID: " <= this->currentThreadId();
    mQMLDateTime.triggertimer();

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
