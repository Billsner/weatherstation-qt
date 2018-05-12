#ifndef DATAPOOLTHREAD_HPP
#define DATAPOOLTHREAD_HPP

#include <QThread>
#include <QLoggingCategory>

#include "DatapoolThread.hpp"


class DatapoolThread : public QThread
{
    Q_OBJECT
public:
    DatapoolThread(QObject *parent = NULL);
    ~DatapoolThread();

    void init(void);

signals:


public slots:
    void timerHit();

private:
    void run();
    QLoggingCategory m_categrory;

};

#endif // DATAPOOLTHREAD_HPP
