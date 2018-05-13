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

    void init();

    void triggertimer(void);

signals:   
    void setClock(QString time);


public slots:
    void receiveSwitch(int count);

private:
    QLoggingCategory m_categrory;
    QObject *mClockObject;

    void setClockTime(QString time);
    void setClockDate(QString date);

};

#endif // QMLDATETIME_HPP
