#ifndef QMLDATETIME_HPP
#define QMLDATETIME_HPP

#include <QObject>
#include "Utils/Logging.hpp"

class QMLDateTime: public QObject
{
    Q_OBJECT
public:
    QMLDateTime();
    ~QMLDateTime();

    void init();

    void triggertimer(void);

signals:   
    void setClock(QString time);


public slots:
    void receiveDateformate(QString format);
    void receiveDateformateIndex(int formatid);

private:
    Logging mLogging;
    QObject *mClockObject;
    QString mdateformate;

    void setClockTime(QString time);
    void setClockDate(QString date);
    void setClockDay(QString day);
    void setClockDateDay(QString date,QString day);

    void connect();

};

#endif // QMLDATETIME_HPP
