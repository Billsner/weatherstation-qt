#include "qmlsettings.hpp"
#include <QThread>
#include <QMetaObject>
#include <QVariant>
#include <QTime>
#include "GUIQML/getqmlobject.hpp"
#include "Datapool/datapoolinterface.hpp"


QMLSettings::QMLSettings() :
    mLogging("GUIQML.QMLObjects.QMLSettings")
{
   mSettingsObject = nullptr;
}

QMLSettings::~QMLSettings()
{

}

void QMLSettings::init()
{
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(nullptr != pGetQMLObject)
    {        
        mSettingsObject = pGetQMLObject->GetSpcificQMLObject("Settings");
        if(nullptr != mSettingsObject)
        {

        }
        else
        {
            mLogging << LLcritical <= "init: NULL == mSettingsObject ";
        }
    }
    connect();
}

void QMLSettings::connect()
{
    if(nullptr != mSettingsObject)
    {
        QObject::connect(mSettingsObject, SIGNAL(signaldateformat(QString)), this, SLOT(receiveDateformate(QString)), Qt::QueuedConnection);
        QObject::connect(mSettingsObject, SIGNAL(signaldateformatid(int)), this, SLOT(receiveDateformateIndex(int)), Qt::QueuedConnection);
    }
    else
    {
        mLogging << LLcritical <= "connect: NULL == pConnectObject ";
    }
}


void QMLSettings::triggertimer(void)
{
    mLogging << "triggertimer TID: " <= QThread::currentThreadId();
    static int count = 0;
    if(0 == count)
    {

    }
    else
    {
        count--;
    }
}

void QMLSettings::setDataformat2GUI(void)
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
    }
    else
    {
        mLogging <= "setDataformat2GUI: ErrorLoading";
    }
}

void QMLSettings::receiveDateformate(QString format)
{
    mLogging << "receiveDateformate: " << format.toStdString().c_str() << " TID: " <= QThread::currentThreadId();
}

void QMLSettings::receiveDateformateIndex(int formatid)
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



