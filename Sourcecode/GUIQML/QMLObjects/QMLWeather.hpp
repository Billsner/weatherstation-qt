#ifndef QMLWEATHER_HPP
#define QMLWEATHER_HPP

#include <QObject>
#include "Utils/Logging.hpp"


class QMLWeather : public QObject
{
    Q_OBJECT
public:
    QMLWeather();
    ~QMLWeather();

    void init();

    void triggertimer(void);

signals:

public slots:

private:
    Logging mLogging;
    QObject *mweather;


    void connect();

};

#endif // QMLWEATHER_HPP
