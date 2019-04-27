#ifndef ONLINESERVICETHREAD_HPP
#define ONLINESERVICETHREAD_HPP

#include <QThread>
#include "Utils/logging.hpp"
#include <QTimer>
#include <stdint.h>
#include "OnlineServices/downloadmanager.hpp"
#include "Datapool/datapoolinterface.hpp"

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
    void startDownload();

    Logging mLogging;
    QTimer mtimer;
    DownloadManager mDownloadManager;
    DatapoolInterface mDatapoolInterface;


};

#endif // ONLINESERVICETHREAD_HPP
