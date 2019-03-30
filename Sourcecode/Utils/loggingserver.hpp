#ifndef LOGGINGSERVER_HPP
#define LOGGINGSERVER_HPP

#include <QMutex>
#include "FileAccess/logfile.hpp"
#include "FileAccess/logini.hpp"
#include "Utils/loggingdef.hpp"
#include <stdint.h>

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
    void getLoggerID(const char *category, uint32_t &ID);
    void getLoggerLevel(uint32_t loggerID, LogLevel &level);
    void getLoggerMode(uint32_t loggerID, LogMode &mode);
    void getLoggerActive(uint32_t loggerID, bool &active);
    void getLoggerCreate(uint32_t loggerID, bool &create);

    void writeLogMsg(const char *msg);

private:
    QMutex m_mutex;
    QMutex m_mutexlogfile;
    Logfile mLogfile;
    LogINI mLogINI;
};

#endif // LOGGINGSERVER_HPP
