#ifndef WEATHERTHREAD_HPP
#define WEATHERTHREAD_HPP

#include <QThread>
#include "Utils/logging.hpp"
#include "GUIQML/QMLObjects/qmlweather.hpp"
#include <QTimer>
#include <stdint.h>

class WeatherThread : public QThread
{
    Q_OBJECT
public:
    WeatherThread(QObject *parent = NULL);
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

};

#endif // WEATHERTHREAD_HPP
