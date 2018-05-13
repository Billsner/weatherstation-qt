#include "QMLDateTime.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>
#include "GUIQML/GetQMLObject.hpp"


QMLDateTime::QMLDateTime() : m_categrory("QMLDateTime")
{
    mClockObject = NULL;
}

QMLDateTime::~QMLDateTime()
{

}

void QMLDateTime::init()
{
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(NULL != pGetQMLObject)
    {
        QObject::connect(pGetQMLObject->GetSpcificQMLObject("sidebaralarm"), SIGNAL(sidbarsignal(int)), this, SLOT(receiveSwitch(int)), Qt::QueuedConnection);
        mClockObject = pGetQMLObject->GetSpcificQMLObject("sidebar");
        if(NULL != mClockObject)
        {

        }
        else
        {
            qCDebug(m_categrory) << "init: NULL == mClockObject ";
        }
    }
}


void QMLDateTime::triggertimer(void)
{
    qCDebug(m_categrory) << "triggertimer TID: " << QThread::currentThreadId();
    QTime time = QTime::currentTime();
    setClockTime(time.toString());
    static int count = 0;
    if(0 == count)
    {
        QDate date = QDate::currentDate();
        setClockDate(date.toString("dd.MM.yyyy"));
        count = 300;
    }
    else
    {
        count--;
    }
}

void QMLDateTime::setClockTime(QString time)
{
    QVariant cpptime(time);
    QMetaObject::invokeMethod(mClockObject, "setclock", Qt::QueuedConnection,
            Q_ARG(QVariant, cpptime));
}

void QMLDateTime::setClockDate(QString date)
{
    QVariant cppdate(date);
    QMetaObject::invokeMethod(mClockObject, "setdate", Qt::QueuedConnection,
            Q_ARG(QVariant, cppdate));
}

void QMLDateTime::receiveSwitch(int count)
{
    qCDebug(m_categrory) << "receiveSwitch: " << count << " TID: " << QThread::currentThreadId();
}


