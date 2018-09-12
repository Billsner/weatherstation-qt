#ifndef LOGGINGSERVER_HPP
#define LOGGINGSERVER_HPP

#include <QMutex>

enum LogLevel
{
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo,
    LLOFF
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

    LoggingServer *getInstance() {return mpLoggingServer;}

    void init();

    void getGlobalLogLevel(LogLevel &level);
    void getGlobalLogMode(LogMode &mode);

    //Loggerfuntions
    void getLoggerID(const char *category, int &ID);
    void getLoggerLevel(int loggerID, LogLevel &level);
    void getLoggerMode(int loggerID, LogMode &mode);
    void getLoggerActive(int loggerID, bool &active);
    void getLoggerCreate(int loggerID, bool &create);

private:
    LoggingServer *mpLoggingServer;
    LogLevel mGlobalLogLevel;
    LogMode mGlobalLogMode;
    QMutex m_mutex;
};

#endif // LOGGINGSERVER_HPP
