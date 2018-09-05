#include "QMLDateTime.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>
#include "GUIQML/GetQMLObject.hpp"
#include "Datapool/DatapoolInterface.hpp"


QMLDateTime::QMLDateTime() :
    mLogging("GUIQML.QMLObjects.QMLDateTime",true,false),
    mdateformate("dd.MM.yyyy")
{
    mClockObject = NULL;
    mSettingsObject = NULL;
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
            mLogging << LLcritical <= "init: NULL == mClockObject ";
        }
        mSettingsObject = pGetQMLObject->GetSpcificQMLObject("Settings");
        if(NULL != mSettingsObject)
        {

        }
        else
        {
            mLogging << LLcritical <= "init: NULL == mSettingsObject ";
        }
    }
    connect();
}

void QMLDateTime::connect()
{
    if(NULL != mSettingsObject)
    {
        QObject::connect(mSettingsObject, SIGNAL(signaldateformat(QString)), this, SLOT(receiveDateformate(QString)), Qt::QueuedConnection);
        QObject::connect(mSettingsObject, SIGNAL(signaldateformatid(int)), this, SLOT(receiveDateformateIndex(int)), Qt::QueuedConnection);
    }
    else
    {
        mLogging << LLcritical <= "connect: NULL == pConnectObject ";
    }
}


void QMLDateTime::triggertimer(void)
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

void QMLDateTime::setDataformat2GUI(void)
{
    int datapoolret = 0;
    DatapoolInterface cDatapoolInterface;
    if(cDatapoolInterface.getDatapoolInt(DIdataformatId, datapoolret) == true)
    {
        mLogging << "setDataformat2GUI: DIdataformatId: " <= datapoolret;
        QVariant dateformat(datapoolret);
        QString retstring;
        DatapoolInterface cDatapoolInterface;
        QMetaObject::invokeMethod(mSettingsObject, "setDateFormat", Qt::QueuedConnection,
                Q_ARG(QVariant, dateformat));
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
        mLogging <= "setDataformat2GUI: ErrorLoading";
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


void QMLDateTime::receiveDateformate(QString format)
{
    mLogging << "receiveDateformate: " << format.toStdString().c_str() << " TID: " <= QThread::currentThreadId();
    mdateformate = format;
    QDate date = QDate::currentDate();
    setClockDateDay(date.toString(mdateformate),date.toString("dddd"));
}

void QMLDateTime::receiveDateformateIndex(int formatid)
{
    mLogging << "receiveDateformateIndex: " << formatid << " TID: " <= QThread::currentThreadId();
    DatapoolInterface cDatapoolInterface;
    cDatapoolInterface.setDatapoolInt(DIdataformatId,formatid);
    int datapoolret = 0;
    if(cDatapoolInterface.getDatapoolInt(DIdataformatId, datapoolret) == true)
    {
        mLogging << "receiveDateformateIndex: datapoolret " <= datapoolret;
    }
    else
    {
        mLogging << LLcritical <= "receiveDateformateIndex: datapoolret getError";
    }

}



