#ifndef LOGGINGSERVER_HPP
#define LOGGINGSERVER_HPP

#include <QMutex>
#include "FileAccess/LogFile.hpp"
#include "FileAccess/LogINI.hpp"

enum LogLevel
{
    LLOFF,
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo,
    LLALL
};

enum LogMode
{
    LMoutput,
    LMfile,
    LMall
};

const int invalidLogID = -1;

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
    LogLevel mGlobalLogLevel;
    LogMode mGlobalLogMode;
    QMutex m_mutex;
    QMutex m_mutexlogfile;
    Logfile mLogfile;
    LogINI mLogINI;
};

#endif // LOGGINGSERVER_HPP
