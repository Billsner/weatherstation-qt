#include "objectthread1.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>

ObjectThread1::ObjectThread1() : m_categrory("ObjectThread1")
{
    mClockObject = NULL;
}

ObjectThread1::~ObjectThread1()
{

}

void ObjectThread1::setClockObject(QObject *ClockObject)
{
    if(mClockObject == NULL)
    {
        mClockObject = ClockObject;
    }
}


void ObjectThread1::triggertimer(void)
{
    qCDebug(m_categrory) << "triggertimer TID: " << QThread::currentThreadId();
    static int counter = 0;
    counter++;
    sendtoThread2(counter);
    QTime time = QTime::currentTime();
    setClockTime(time.toString());
}

void ObjectThread1::receiveThread2Count(int count)
{
    qCDebug(m_categrory) << "receiveThread2Count count: " << count << " TID: " << QThread::currentThreadId();
}

void ObjectThread1::receiveSwitch(int count)
{
    qCDebug(m_categrory) << "receiveSwitch count: " << count << " TID: " << QThread::currentThreadId();
}

void ObjectThread1::setClockTime(QString time)
{
    QVariant cpptime(time);
    QMetaObject::invokeMethod(mClockObject, "setclock", Qt::QueuedConnection,
            Q_ARG(QVariant, cpptime));
}
