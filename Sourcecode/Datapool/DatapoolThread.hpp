#ifndef DATAPOOLTHREAD_HPP
#define DATAPOOLTHREAD_HPP

#include <QThread>
#include <QLoggingCategory>

#include "DatapoolThread.hpp"
#include "Datapool/QMLObjects/QMLDateTime.hpp"


class DatapoolThread : public QThread
{
    Q_OBJECT
public:
    DatapoolThread(QObject *parent = NULL);
    ~DatapoolThread();    

signals:


public slots:
    void timerHit();

private:
    void run();
    void init(void);
    QLoggingCategory m_categrory;
    QMLDateTime mQMLDateTime;

};

#endif // DATAPOOLTHREAD_HPP
