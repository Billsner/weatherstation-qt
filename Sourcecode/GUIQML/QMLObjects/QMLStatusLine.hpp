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
    void setDataformat2GUI(void);

signals:   
    void setClock(QString time);


public slots:
    void receiveDateformate(QString format);
    void receiveDateformateIndex(int formatid);

private:
    Logging mLogging;
    QObject *mClockObject;
    QObject *mSettingsObject;
    QString mdateformate;

    void setClockTime(QString time);
    void setClockDate(QString date);
    void setClockDay(QString day);
    void setClockDateDay(QString date,QString day);

    void connect();

};

#endif // QMLSTATUSLINE_HPP
