#include "QMLDateTime.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>
#include "GUIQML/GetQMLObject.hpp"


QMLDateTime::QMLDateTime() : m_categrory("QMLDateTime"),mdateformate("dd.MM.yyyy")
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
        mClockObject = pGetQMLObject->GetSpcificQMLObject("statusbar");
        if(NULL != mClockObject)
        {

        }
        else
        {
            qCDebug(m_categrory) << "init: NULL == mClockObject ";
        }
    }
    connect();
}

void QMLDateTime::connect()
{
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(NULL != pGetQMLObject)
    {
        QObject *pConnectObject = pGetQMLObject->GetSpcificQMLObject("Settings");
        if(NULL != pConnectObject)
        {
            QObject::connect(pConnectObject, SIGNAL(signaldateformat(QString)), this, SLOT(receiveDateformate(QString)), Qt::QueuedConnection);
            QObject::connect(pConnectObject, SIGNAL(signaldateformatid(int)), this, SLOT(receiveDateformateIndex(int)), Qt::QueuedConnection);


        }
        else
        {
            qCDebug(m_categrory) << "connect: NULL == pConnectObject ";
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
        setClockDateDay(date.toString(mdateformate),date.toString("dddd"));
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

void QMLDateTime::setClockDay(QString day)
{
    QVariant cppday(day);
    QMetaObject::invokeMethod(mClockObject, "setday", Qt::QueuedConnection,
            Q_ARG(QVariant, cppday));
}

void QMLDateTime::setClockDateDay(QString date, QString day)
{
    QVariant cppdate(date);
    QVariant cppday(day);
    QMetaObject::invokeMethod(mClockObject, "setdateday", Qt::QueuedConnection,
            Q_ARG(QVariant, cppdate),Q_ARG(QVariant, cppday));
}


void QMLDateTime::receiveDateformate(QString format)
{
    qCDebug(m_categrory) << "receiveDateformate: " << format << " TID: " << QThread::currentThreadId();
    mdateformate = format;
    QDate date = QDate::currentDate();
    setClockDateDay(date.toString(mdateformate),date.toString("dddd"));
}

void QMLDateTime::receiveDateformateIndex(int formatid)
{
    qCDebug(m_categrory) << "receiveDateformateIndex: " << formatid << " TID: " << QThread::currentThreadId();
}



