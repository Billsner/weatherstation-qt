#ifndef OBJECTTHREAD1_HPP
#define OBJECTTHREAD1_HPP

#include <QObject>
#include <QLoggingCategory>

class ObjectThread1: public QObject
{
    Q_OBJECT
public:
    ObjectThread1();
    ~ObjectThread1();

    void triggertimer(void);
    void setClockObject(QObject *ClockObject);

signals:
    void sendtoThread2(int count);
    void setClock(QString time);


public slots:
    void receiveThread2Count(int count);
    void receiveSwitch(int count);

private:
    QLoggingCategory m_categrory;
    QObject *mClockObject;

    void setClockTime(QString time);

};

#endif // OBJECTTHREAD1_HPP
