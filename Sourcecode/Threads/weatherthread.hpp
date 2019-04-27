#ifndef WEATHERTHREAD_HPP
#define WEATHERTHREAD_HPP

#include <QThread>
#include "Utils/logging.hpp"
#include "GUIQML/QMLObjects/qmlweather.hpp"
#include "weather/weatherdatainterpreter.hpp"
#include <QTimer>
#include <stdint.h>

class WeatherThread : public QThread
{
    Q_OBJECT
public:
    WeatherThread(QObject *parent = nullptr);
    ~WeatherThread();

    void initthread();
signals:


public slots:
    void timerHit();

private:
    void run();
    void initobjects(void);
    void startTimer(int32_t ms);
    void stopTimer();

    Logging mLogging;
    QTimer mtimer;
    QMLWeather mQMLWeather;
    WeatherDataInterpreter mWeatherDataInterpreter;

};

#endif // WEATHERTHREAD_HPP
