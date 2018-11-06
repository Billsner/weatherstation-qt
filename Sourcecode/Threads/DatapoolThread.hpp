#ifndef DATAPOOLTHREAD_HPP
#define DATAPOOLTHREAD_HPP

#include <QThread>
#include "Utils/Logging.hpp"
#include "GUIQML/QMLObjects/QMLStatusLine.hpp"
#include "GUIQML/QMLObjects/QMLSettings.hpp"
#include "Datapool/DatapoolControll.hpp"


class DatapoolThread : public QThread
{
    Q_OBJECT
public:
    DatapoolThread(QObject *parent = NULL);
    ~DatapoolThread();

    void initthread();

signals:


public slots:
    void timerHit();

private:
    void run();
    void initobjects(void);
    Logging mLogging;
    QMLStatusLine mQMLStatusLine;
    QMLSettings mQMLSettings;
    DatapoolControll mDatapoolControll;

};

#endif // DATAPOOLTHREAD_HPP
