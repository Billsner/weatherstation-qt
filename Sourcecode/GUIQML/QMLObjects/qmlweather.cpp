#include "qmlweather.hpp"
#include "GUIQML/getqmlobject.hpp"
#include "Datapool/datapoolinterface.hpp"
#include "weather/weatherdef.hpp"
#include "weather/weatherpicinfo.hpp"
#include "weather/weatherpicwarning.hpp"

QMLWeather::QMLWeather() :
    mLogging("GUIQML.QMLObjects.QMLWeather"),
    mweather(nullptr)
{

}

QMLWeather::~QMLWeather()
{

}

void QMLWeather::init()
{
    GetQMLObject *pGetQMLObject = GetQMLObject::getInstance();
    if(nullptr != pGetQMLObject)
    {
        mweather = pGetQMLObject->GetSpcificQMLObject("WeatherWindow");
        if(nullptr != mweather)
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
    if(nullptr != mweather)
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
         count = 2;
         setToday();
         setWarning();
     }
     else
     {
         count--;
     }
}

void QMLWeather::setToday()
{
    static int picid = 0;
    WeatherPicInfo cPicInfo;
    QString picpath = cPicInfo.getPicPath(static_cast<eWeatherStatus>(picid));
    picid++;
    if(picid >= static_cast<int>(ws_count))
    {
        picid = 0;
    }

    if(!picpath.isEmpty())
    {
        QVariant today(picpath);
        DatapoolInterface cDatapoolInterface;
        QMetaObject::invokeMethod(mweather, "setToday", Qt::QueuedConnection,
                                  Q_ARG(QVariant, today));
    }
}

void QMLWeather::setWarning()
{
    static int picid = 0;
    WeatherPicWarning cPicInfo;
    QString picpath = cPicInfo.getPicPath(static_cast<eWeatherWarning>(picid));
    picid++;
    if(picid >= static_cast<int>(ww_count))
    {
        picid = 0;
    }

    if(!picpath.isEmpty())
    {
        QVariant today(picpath);
        DatapoolInterface cDatapoolInterface;
        QMetaObject::invokeMethod(mweather, "setWarning", Qt::QueuedConnection,
                                  Q_ARG(QVariant, today));
    }
}
