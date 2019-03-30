#ifndef ONLINESERVICETHREAD_HPP
#define ONLINESERVICETHREAD_HPP

#include <QThread>
#include "Utils/logging.hpp"
#include <QTimer>
#include <stdint.h>

class OnlineServiceThread : public QThread
{
    Q_OBJECT
public:
    OnlineServiceThread(QObject *parent = nullptr);
    ~OnlineServiceThread();

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

};

#endif // ONLINESERVICETHREAD_HPP
