#ifndef LOGINI_HPP
#define LOGINI_HPP

#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>
#include <QMutex>
#include <QString>
#include "Utils/LoggingDef.hpp"


class LogINI
{
public:
    LogINI();
    ~LogINI();

    void openFile();
    void closeFile();

    void loadINI(void);

    void getGlobalLogLevel(LogLevel &level){level = mGlobalLogLevel;}
    void getGlobalLogMode(LogMode &mode){mode = mGlobalLogMode;}

    void writeLoggerList(const char *msg);

private:

    void processReadLine(QString line);
    LogLevel getLogLevelFromString(QString level);
    LogMode getLogModFromString(QString mod);



    QFile mfileINI;
    QFile mfileLogger;
    QMutex m_mutex;
    bool mfileopen;
    QLoggingCategory m_categrory;

    LogLevel mGlobalLogLevel;
    LogMode mGlobalLogMode;
};

#endif // LOGINI_HPP
