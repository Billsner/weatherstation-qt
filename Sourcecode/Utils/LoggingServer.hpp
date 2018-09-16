#ifndef LOGGINGSERVER_HPP
#define LOGGINGSERVER_HPP

#include <QMutex>
#include "FileAccess/LogFile.hpp"
#include "FileAccess/LogINI.hpp"
#include "Utils/LoggingDef.hpp"

class LoggingServer
{
public:
    LoggingServer();
    ~LoggingServer();

    static LoggingServer *getInstance();

    void init();
    void finish();

    void getGlobalLogLevel(LogLevel &level);
    void getGlobalLogMode(LogMode &mode);

    //Loggerfuntions
    void getLoggerID(const char *category, int &ID);
    void getLoggerLevel(int loggerID, LogLevel &level);
    void getLoggerMode(int loggerID, LogMode &mode);
    void getLoggerActive(int loggerID, bool &active);
    void getLoggerCreate(int loggerID, bool &create);

    void writeLogMsg(const char *msg);

private:
    QMutex m_mutex;
    QMutex m_mutexlogfile;
    Logfile mLogfile;
    LogINI mLogINI;
};

#endif // LOGGINGSERVER_HPP
