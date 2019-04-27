#ifndef WEATHERDATAINTERPRETER_HPP
#define WEATHERDATAINTERPRETER_HPP

#include "Utils/logging.hpp"
#include "Datapool/datapoolinterface.hpp"
#include <QString>

class WeatherDataInterpreter
{
public:
    WeatherDataInterpreter();
    ~WeatherDataInterpreter();

    void triggerTimertick();


private:
    bool checkLastDataSync(void);
    bool checkActualWeatherData(void);


    Logging mLogging;
    DatapoolInterface mDatapoolInterface;
    bool mDownloadDataActual;
    bool mNeedCheckDownload;
    QString mCheckDate;

};

#endif // WEATHERDATAINTERPRETER_HPP
