#ifndef WEATHERPICWARNING_HPP
#define WEATHERPICWARNING_HPP

#include <QStringList>
#include "weatherdef.hpp"

const QStringList pathImageWarning2PICID =
{
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_no_warning.png",  //ww_no_warning,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_eis_1.png",  //ww_eis_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_eis_2.png",  //ww_eis_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_eis_3.png",  //ww_eis_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_eis_4.png",  //ww_eis_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_frost_1.png",  //ww_frost_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_frost_2.png",  //ww_frost_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_frost_3.png",  //ww_frost_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_frost_4.png",  //ww_frost_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_gewitter_1.png",  //ww_gewitter_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_gewitter_2.png",  //ww_gewitter_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_gewitter_3.png",  //ww_gewitter_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_gewitter_4.png",  //ww_gewitter_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_nebel_1.png",  //ww_nebel_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_nebel_2.png",  //ww_nebel_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_nebel_3.png",  //ww_nebel_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_nebel_4.png",  //ww_nebel_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_regen_1.png",  //ww_regen_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_regen_2.png",  // ww_regen_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_regen_3.png",  //ww_regen_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_regen_4.png",  //ww_regen_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_tau_1.png",  //ww_tau_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_tau_2.png",  //ww_tau_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_tau_3.png",  //ww_tau_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_tau_4.png",  //ww_tau_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_wind_1.png",  //ww_wind_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_wind_2.png",  //ww_wind_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_wind_3.png",  //ww_wind_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_wind_4.png",  //ww_wind_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_uv.png",  //ww_uv_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_uv.png",  //ww_uv_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_uv.png",  //ww_uv_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_uv.png",  //ww_uv_level4,
    "",  //ww_hagel_level1,
    "",  //ww_hagel_level2,
    "",  // ww_hagel_level3,
    "",  //ww_hagel_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_hitze.png",  //ww_hitze_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_hitze.png",  //ww_hitze_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_hitze.png",  //ww_hitze_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_hitze.png",  //ww_hitze_level4,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_schnee_1.png",  //ww_schnee_level1,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_schnee_2.png",  //ww_schnee_level2,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_schnee_3.png",  //ww_schnee_level3,
    "Data-Pic-Images/Pictures/WarningIcons_Big/warn_icons_schnee_4.png",  //ww_schnee_level4,

};

class WeatherPicWarning
{
public:
    WeatherPicWarning();
    ~WeatherPicWarning();

    QString getPicPath(eWeatherWarning id);
};

#endif // WEATHERPICWARNING_HPP
