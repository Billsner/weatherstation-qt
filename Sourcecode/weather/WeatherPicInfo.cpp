#include "WeatherPicInfo.hpp"

WeatherPicInfo::WeatherPicInfo()
{

}

WeatherPicInfo::~WeatherPicInfo()
{

}

QString WeatherPicInfo::getPicPath(eWeatherStatus id)
{
    QString ret = "";
    if( id < pathImage2PICID.size())
    {
        ret = pathImage2PICID.at(id);
    }
    return ret;
}
