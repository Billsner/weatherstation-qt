#ifndef WEATHERDATAINTERPRETER_HPP
#define WEATHERDATAINTERPRETER_HPP

#include "Utils/logging.hpp"
#include "Datapool/datapoolinterface.hpp"
#include <QString>
#include "FileAccess/interpretmosmixl.hpp"

class WeatherDataInterpreter
{
public:
    WeatherDataInterpreter();
    ~WeatherDataInterpreter();

    void triggerTimertick();


private:
    bool checkLastDataSync(void);
    bool checkActualWeatherData(void);
    void interpretData(void);


    Logging mLogging;
    DatapoolInterface mDatapoolInterface;
    bool mDownloadDataActual;
    bool mNeedCheckDownload;
    QString mCheckDate;
    InterpretMOSMIXL mInterpretMOSMIXL;

};

#endif // WEATHERDATAINTERPRETER_HPP
