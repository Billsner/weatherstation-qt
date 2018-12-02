#include "WeatherPicWarning.hpp"

WeatherPicWarning::WeatherPicWarning()
{

}

WeatherPicWarning::~WeatherPicWarning()
{

}

QString WeatherPicWarning::getPicPath(eWeatherWarning id)
{
    QString ret = "";
    if(id < pathImageWarning2PICID.size())
    {
        ret = pathImageWarning2PICID.at(id);
    }
    return ret;
}
