#include "QMLDateTime.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>

QMLDateTime::QMLDateTime() : m_categrory("QMLDateTime")
{
    mClockObject = NULL;
}

QMLDateTime::~QMLDateTime()
{

}

void QMLDateTime::conncet()
{

}

void QMLDateTime::setClockObject(QObject *ClockObject)
{
    if(mClockObject == NULL)
    {
        mClockObject = ClockObject;
    }
}


void QMLDateTime::triggertimer(void)
{
    qCDebug(m_categrory) << "triggertimer TID: " << QThread::currentThreadId();
    QTime time = QTime::currentTime();
    setClockTime(time.toString());
}

void QMLDateTime::setClockTime(QString time)
{
    QVariant cpptime(time);
    QMetaObject::invokeMethod(mClockObject, "setclock", Qt::QueuedConnection,
            Q_ARG(QVariant, cpptime));
}
