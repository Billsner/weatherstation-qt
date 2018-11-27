#include "QMLWeather.hpp"
#include "GUIQML/GetQMLObject.hpp"
#include "Datapool/DatapoolInterface.hpp"

QMLWeather::QMLWeather() :
    mLogging("GUIQML.QMLObjects.QMLWeather"),
    mweather(NULL)
{

}

QMLWeather::~QMLWeather()
{

}

void QMLWeather::init()
{
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(NULL != pGetQMLObject)
    {
        mweather = pGetQMLObject->GetSpcificQMLObject("WeatherWindow");
        if(NULL != mweather)
        {

        }
        else
        {
            mLogging << LLcritical <= "init: NULL == mweather ";
        }
    }
    connect();
}

void QMLWeather::connect()
{
    if(NULL != mweather)
    {
        //QObject::connect(mweather, SIGNAL(signaldateformat(QString)), this, SLOT(receiveDateformate(QString)), Qt::QueuedConnection);
        //QObject::connect(mSettingsObject, SIGNAL(signaldateformatid(int)), this, SLOT(receiveDateformateIndex(int)), Qt::QueuedConnection);
    }
    else
    {
        mLogging << LLcritical <= "connect: NULL == mweather ";
    }
}

void QMLWeather::triggertimer(void)
{
    static int count = 0;

     mLogging << LLinfo <= "triggertimer ";
     if(0 == count)
     {
         count = 10;
         setToday();
     }
     else
     {
         count--;
     }
}

void QMLWeather::setToday()
{
    static int picid = 0;
    QString picpath;
    switch(picid)
    {
    case 0:
        picpath = "Data-Pic-Images/Pictures/WetterIcons/0-8.png";
        break;
    case 1:
        picpath = "Data-Pic-Images/Pictures/WetterIcons/2-8.png";
        break;
    case 2:
        picpath = "Data-Pic-Images/Pictures/WetterIcons/5-8.png";
        break;

    default:
        picpath = "Data-Pic-Images/Pictures/WetterIcons/eis.png";
        picid = -1;
        break;
    }
    picid++;


    QVariant today(picpath);
    DatapoolInterface cDatapoolInterface;
    QMetaObject::invokeMethod(mweather, "setToday", Qt::QueuedConnection,
            Q_ARG(QVariant, today));
}
