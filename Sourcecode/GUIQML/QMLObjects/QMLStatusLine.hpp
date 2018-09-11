#ifndef QMLSTATUSLINE_HPP
#define QMLSTATUSLINE_HPP

#include <QObject>
#include "Utils/Logging.hpp"

class QMLStatusLine: public QObject
{
    Q_OBJECT
public:
    QMLStatusLine();
    ~QMLStatusLine();

    void init();

    void triggertimer(void);

signals:   
    void setClock(QString time);

private:
    Logging mLogging;
    QObject *mClockObject;
    QString mdateformate;

    void setClockTime(QString time);
    void setClockDateDay(QString date,QString day);

    void getDateFormat(void);

    void connect();

};

#endif // QMLSTATUSLINE_HPP
