#ifndef THREAD1_HPP
#define THREAD1_HPP

#include <QThread>
#include <QLoggingCategory>

#include "objectthread1.hpp"


class Thread1 : public QThread
{
    Q_OBJECT
public:
    Thread1(QObject *parent = NULL);
    ~Thread1();

    void init(void);

    QObject *getObject(void){return &m_ObjectThread1;}
    void setClockObject(QObject *ClockObject){m_ObjectThread1.setClockObject(ClockObject);}



signals:
    void sendtoThread2(int count);


public slots:
    void timerHit();
    void receiveThread2Count(int count);

private:
    void run();
    QLoggingCategory m_categrory;
    ObjectThread1 m_ObjectThread1;

};

#endif // THREAD1_HPP
