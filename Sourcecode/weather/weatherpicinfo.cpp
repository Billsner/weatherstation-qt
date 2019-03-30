#include "weatherpicinfo.hpp"

WeatherPicInfo::WeatherPicInfo()
{

}

WeatherPicInfo::~WeatherPicInfo()
{

}

QString WeatherPicInfo::getPicPath(eWeatherStatus id)
{
    QString ret = "";
    if( id < pathImageStatus2PICID.size())
    {
        ret = pathImageStatus2PICID.at(id);
    }
    return ret;
}
