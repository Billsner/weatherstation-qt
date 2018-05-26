#ifndef DATAPOOLTHREAD_HPP
#define DATAPOOLTHREAD_HPP

#include <QThread>
#include <QLoggingCategory>

#include "DatapoolThread.hpp"
#include "GUIQML/QMLObjects/QMLDateTime.hpp"
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
    QLoggingCategory m_categrory;
    QMLDateTime mQMLDateTime;
    DatapoolControll mDatapoolControll;

};

#endif // DATAPOOLTHREAD_HPP
