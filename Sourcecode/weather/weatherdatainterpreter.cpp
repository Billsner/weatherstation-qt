#include "weatherdatainterpreter.hpp"
#include <QDate>

WeatherDataInterpreter::WeatherDataInterpreter() :
    mLogging("weather.WeatherDataInterpreter"),
    mDownloadDataActual(false),
    mNeedCheckDownload(false),
    mCheckDate("")

{

}

WeatherDataInterpreter::~WeatherDataInterpreter()
{

}

void WeatherDataInterpreter::triggerTimertick()
{
    mLogging <= "ctriggerTimertick";
    static uint32_t timercountcheckLastDataSync = 5;
    if(timercountcheckLastDataSync == 0)
    {
        timercountcheckLastDataSync = 60;
        checkLastDataSync();
    }
    else
    {
        timercountcheckLastDataSync--;
    }

    static uint32_t timercountCheckWeaterData = 0;
    if(timercountCheckWeaterData == 0)
    {
        checkActualWeatherData();
        timercountCheckWeaterData = 10;
    }
    else
    {
        timercountCheckWeaterData--;
    }
}

bool WeatherDataInterpreter::checkLastDataSync(void)
{
    bool ret = false;
    QString currentdate = QDate::currentDate().toString(defaultformate);
    if(currentdate !=  mCheckDate)
    {
        ret = true;
        mNeedCheckDownload = true;
        mLogging <= "checkLastDataSync: need new data";
    }
    else
    {
        ret = false;
        mNeedCheckDownload = false;
        mLogging <= "checkLastDataSync: Data actual";
    }
    return ret;
}

bool WeatherDataInterpreter::checkActualWeatherData()
{
    bool ret = false;
    if(mNeedCheckDownload)
    {
        QString currentdate = QDate::currentDate().toString(defaultformate);
        QString dpdate("");
        mDatapoolInterface.getDatapoolQString(DIWaetherDownloadDate,dpdate);
        if(currentdate == dpdate)
        {
            ret = true;
            mCheckDate = currentdate;
            mLogging <= "checkActualWeatherData: date is correct";
        }
        else
        {
            ret = false;
            mDatapoolInterface.setDatapoolInt(DIWeatherDownloadRequest,1);

            (mLogging << "checkActualWeatherData: date is not correct currentdate: " << currentdate.toStdString().size() << " dpdate: ") <= dpdate.toStdString().size();
        }
    }
    return ret;
}
