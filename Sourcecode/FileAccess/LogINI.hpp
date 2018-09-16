#ifndef LOGINI_HPP
#define LOGINI_HPP

#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>
#include <QMutex>

class LogINI
{
public:
    LogINI();
    ~LogINI();

    void openFile();
    void closeFile();
    void writeLoggerList(const char *msg);



private:
    QFile mfileINI;
    QFile mfileLogger;
    QMutex m_mutex;
    bool mfileopen;
    QLoggingCategory m_categrory;
};

#endif // LOGINI_HPP
