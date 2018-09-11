#include "QMLStatusLine.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>
#include "GUIQML/GetQMLObject.hpp"
#include "Datapool/DatapoolInterface.hpp"


QMLStatusLine::QMLStatusLine() :
    mLogging("GUIQML.QMLObjects.QMLStatusLine",true,false),
    mdateformate("dd.MM.yyyy")
{
    mClockObject = NULL;
}

QMLStatusLine::~QMLStatusLine()
{

}

void QMLStatusLine::init()
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
            mLogging << LLcritical <= "init: NULL == mClockObject ";
        }
    }
    connect();
}

void QMLStatusLine::connect()
{

}


void QMLStatusLine::triggertimer(void)
{
    mLogging << "triggertimer TID: " <= QThread::currentThreadId();
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

void QMLStatusLine::setClockTime(QString time)
{
    QVariant cpptime(time);
    QMetaObject::invokeMethod(mClockObject, "setclock", Qt::QueuedConnection,
            Q_ARG(QVariant, cpptime));
}

void QMLStatusLine::setClockDate(QString date)
{
    QVariant cppdate(date);    
    QMetaObject::invokeMethod(mClockObject, "setdate", Qt::QueuedConnection,
            Q_ARG(QVariant, cppdate));    
}

void QMLStatusLine::setClockDay(QString day)
{
    QVariant cppday(day);
    QMetaObject::invokeMethod(mClockObject, "setday", Qt::QueuedConnection,
            Q_ARG(QVariant, cppday));

}

void QMLStatusLine::setClockDateDay(QString date, QString day)
{
    QVariant cppdate(date);
    QVariant cppday(day);
    QString retstring;
    DatapoolInterface cDatapoolInterface;
    QMetaObject::invokeMethod(mClockObject, "setdateday", Qt::QueuedConnection,
            Q_ARG(QVariant, cppdate),Q_ARG(QVariant, cppday));
    cDatapoolInterface.setDatapoolQString(DIdate,date);
    cDatapoolInterface.getDatapoolQString(DIdate,retstring);
    if(strcmp(date.toStdString().c_str(),retstring.toStdString().c_str()) == 0)
    {
        mLogging <= "setClockDateDay: datapool correct";
    }
    else
    {
        mLogging << LLcritical << "setClockDateDay: datapool error " << date.toStdString().c_str() << " retdate " <= retstring.toStdString().c_str();
    }
}

void QMLStatusLine::getDateFormat(void)
{
    DatapoolInterface cDatapoolInterface;
    int datapoolret = 0;
    if(cDatapoolInterface.getDatapoolInt(DIdataformatId, datapoolret) == true)
    {
        mLogging << "receiveDateformateIndex: datapoolret " <= datapoolret;
        switch(datapoolret)
        {
        case 0:
            mdateformate = "dd.MM.yyyy";
            break;
        case 1:
            mdateformate = "yyyy.MM.dd";
            break;
        case 2:
            mdateformate = "yyyy.dd.MM";
            break;
        default:
            mdateformate = "dd.MM.yyyy";
            break;
        }
    }
    else
    {
        mLogging << LLcritical <= "receiveDateformateIndex: datapoolret getError";
    }
}



