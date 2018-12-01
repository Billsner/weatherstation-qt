#ifndef WEATHERPICINFO_HPP
#define WEATHERPICINFO_HPP

#include <QStringList>
#include "weatherdef.hpp"

const QStringList pathImage2PICID =
{
    "Data-Pic-Images/Pictures/WetterIcons/0-8.png", //wolkenlos,
    "Data-Pic-Images/Pictures/WetterIcons/2-8.png", //heiter,
    "Data-Pic-Images/Pictures/WetterIcons/2-8.png", //gering_bewölkt,
    "Data-Pic-Images/Pictures/WetterIcons/5-8.png", //bewölkt,
    "Data-Pic-Images/Pictures/WetterIcons/5-8.png", //stark_bewölkt,
    "Data-Pic-Images/Pictures/WetterIcons/8-8.png", //bedeckt,
    "Data-Pic-Images/Pictures/WetterIcons/40.png", //Dunst_flacher_Nebel,
    "Data-Pic-Images/Pictures/WetterIcons/40.png", //Nebel,
    "Data-Pic-Images/Pictures/WetterIcons/48.png", //gefrierender_Nebel,
    "Data-Pic-Images/Pictures/WetterIcons/66.png", //Glatteisbildung,
    "Data-Pic-Images/Pictures/WetterIcons/18.png", //Sandsturm,
    "Data-Pic-Images/Pictures/WetterIcons/18.png", //Sandsturm_Schneefegen,
    "Data-Pic-Images/Pictures/WetterIcons/7.png", //Niederschlag,
    "Data-Pic-Images/Pictures/WetterIcons/7.png", //Regen,
    "Data-Pic-Images/Pictures/WetterIcons/7.png", //leichter_Regen,
    "Data-Pic-Images/Pictures/WetterIcons/9.png", //kräftiger_Regen,
    "Data-Pic-Images/Pictures/WetterIcons/14.png", //Schneefall,
    "Data-Pic-Images/Pictures/WetterIcons/14.png", //leichter_Schneefall,
    "Data-Pic-Images/Pictures/WetterIcons/16.png", //kräftiger_Schneefall,
    "Data-Pic-Images/Pictures/WetterIcons/12.png", //Schneeregen,
    "Data-Pic-Images/Pictures/WetterIcons/13.png", //kräftiger_Schneeregen,
    "Data-Pic-Images/Pictures/WetterIcons/14.png", //Schneefegen,
    "Data-Pic-Images/Pictures/WetterIcons/14.png", //Schneegriesel,
    "Data-Pic-Images/Pictures/WetterIcons/80.png", //Schauer,
    "Data-Pic-Images/Pictures/WetterIcons/80.png", //Regenschauer,
    "Data-Pic-Images/Pictures/WetterIcons/82.png", //kräftiger_Regenschauer,
    "Data-Pic-Images/Pictures/WetterIcons/85.png", //Schneeschauer,
    "Data-Pic-Images/Pictures/WetterIcons/86.png", //kräftiger_Schneeschauer,
    "Data-Pic-Images/Pictures/WetterIcons/83.png", //Schneeregenschauer,
    "Data-Pic-Images/Pictures/WetterIcons/84.png", //kräftiger_Schneeregenschauer,
    "Data-Pic-Images/Pictures/WetterIcons/17.png", //Graupelschauer,
    "Data-Pic-Images/Pictures/WetterIcons/87.png", //Hagelschauer,
    "Data-Pic-Images/Pictures/WetterIcons/87.png", //kräftiger_Graupelschauer,
    "Data-Pic-Images/Pictures/WetterIcons/88.png", //kräftiger_Hagelschauer,
    "Data-Pic-Images/Pictures/WetterIcons/26.png", //Gewitter,
    "Data-Pic-Images/Pictures/WetterIcons/27.png", //starkes_Gewitter,
    "Data-Pic-Images/Pictures/WetterIcons/28.png" //schweres_Gewitter
};


class WeatherPicInfo
{
public:
    WeatherPicInfo();
    ~WeatherPicInfo();
    QString getPicPath(eWeatherStatus id);

};

#endif // WEATHERPICINFO_HPP
