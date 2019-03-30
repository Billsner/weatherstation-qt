#ifndef DATAPOOLTHREAD_HPP
#define DATAPOOLTHREAD_HPP

#include <QThread>
#include "Utils/logging.hpp"
#include "GUIQML/QMLObjects/qmlstatusline.hpp"
#include "GUIQML/QMLObjects/qmlsettings.hpp"
#include "Datapool/datapoolcontroll.hpp"
#include <QTimer>


class DatapoolThread : public QThread
{
    Q_OBJECT
public:
    DatapoolThread(QObject *parent = nullptr);
    ~DatapoolThread();

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
    QMLStatusLine mQMLStatusLine;
    QMLSettings mQMLSettings;
    QTimer mtimer;
    DatapoolControll mDatapoolControll;
};

#endif // DATAPOOLTHREAD_HPP
