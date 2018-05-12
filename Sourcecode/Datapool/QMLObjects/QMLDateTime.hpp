#ifndef QMLDATETIME_HPP
#define QMLDATETIME_HPP

#include <QObject>
#include <QLoggingCategory>

class QMLDateTime: public QObject
{
    Q_OBJECT
public:
    QMLDateTime();
    ~QMLDateTime();

    void triggertimer(void);
    void setClockObject(QObject *ClockObject);

signals:   
    void setClock(QString time);


public slots:
    void receiveSwitch(int count);

private:
    QLoggingCategory m_categrory;
    QObject *mClockObject;

    void setClockTime(QString time);

};

#endif // QMLDATETIME_HPP
