#ifndef WEATHERTHREAD_HPP
#define WEATHERTHREAD_HPP

#include <QThread>
#include "Utils/Logging.hpp"
#include "GUIQML/QMLObjects/QMLWeather.hpp"
#include <QTimer>

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
    void startTimer(int ms);
    void stopTimer();



    Logging mLogging;
    QTimer mtimer;
    QMLWeather mQMLWeather;

};

#endif // WEATHERTHREAD_HPP
