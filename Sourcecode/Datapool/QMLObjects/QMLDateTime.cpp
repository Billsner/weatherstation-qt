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
}

void QMLDateTime::setClockTime(QString time)
{
    QVariant cpptime(time);
    QMetaObject::invokeMethod(mClockObject, "setclock", Qt::QueuedConnection,
            Q_ARG(QVariant, cpptime));
}

void QMLDateTime::receiveSwitch(int count)
{

}

