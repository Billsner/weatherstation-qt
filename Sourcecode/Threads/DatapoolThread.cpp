#include "DatapoolThread.hpp"
#include "Datapool/DatapoolInterface.hpp"
#include <QTimer>
#include <QTime>

DatapoolThread::DatapoolThread(QObject *parent): QThread(parent), m_categrory("thread.DatapoolThread")
{
    qCDebug(m_categrory) << "Constructer";
}

DatapoolThread::~DatapoolThread()
{
    qCDebug(m_categrory) << "Destructer";
}

void DatapoolThread::initthread()
{
    mQMLDateTime.moveToThread(this);
}

void DatapoolThread::initobjects(void)
{
    qCDebug(m_categrory) << "initobjects TID: " << this->currentThreadId();
    mQMLDateTime.init();
    mDatapoolControll.loadDatapool();
}

void DatapoolThread::run()
{
    qCDebug(m_categrory) << "Hello DatapoolThread TID: " << this->currentThreadId();
    initobjects();

    mQMLDateTime.triggertimer();

    //Timer
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(1000);
    timer.start();    
    int code = exec();
    qCDebug(m_categrory) << "EXEC.Code " << code;
}

void DatapoolThread::timerHit()
{
    qCDebug(m_categrory) << QTime::currentTime() << " timerHit TID: " << this->currentThreadId();
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
