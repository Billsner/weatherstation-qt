#ifndef THREAD2_HPP
#define THREAD2_HPP

#include <QThread>
#include <QLoggingCategory>

class Thread2 : public QThread
{
     Q_OBJECT
public:
    Thread2(QObject *parent = NULL);
    ~Thread2();

signals:
    void sendtoThread1(int count);


public slots:
    void timerHit();
    void receiveThread1Count(int count);

private:
    void run();

    QLoggingCategory m_categrory;
};

#endif // THREAD2_HPP
