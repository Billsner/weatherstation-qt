#ifndef GUIQMLTHREAD_HPP
#define GUIQMLTHREAD_HPP

#include <QThread>
#include <QLoggingCategory>

#include "GUIQMLThread.hpp"


class GUIQMLThread : public QThread
{
    Q_OBJECT
public:
    GUIQMLThread(QObject *parent = NULL);
    ~GUIQMLThread();

    void init(void);

signals:


public slots:
    void timerHit();

private:
    void run();
    QLoggingCategory m_categrory;

};

#endif // GUIQMLTHREAD_HPP
