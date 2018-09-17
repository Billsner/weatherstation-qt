#ifndef LOGINI_HPP
#define LOGINI_HPP

#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>
#include <QMutex>
#include <QString>
#include "Utils/LoggingDef.hpp"
#include <vector>

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

    void getLoggerID(QString LoggerName, int &loggerid);
    void getLogLevel(int Loggerid, LogLevel &level);
    void getLogMode(int Loggerid, LogMode &mod);
    void getLogActive(int Loggerid, bool &active);
    void getLogConstr(int Loggerid, bool &constr);

    void writeLoggerList(const char *msg);

private:

    void processReadLine(QString line);
    void setLogger(QString LoggerEntry);

    LogLevel getLogLevelFromString(QString level);
    LogMode getLogModFromString(QString mod);
    bool getLogActiveFromString(QString active);
    bool getLogContrFromString(QString constr);

    QFile mfileINI;
    QFile mfileLogger;
    QMutex m_mutex;
    bool mfileopen;
    QLoggingCategory m_categrory;

    LogLevel mGlobalLogLevel;
    LogMode mGlobalLogMode;
    int LoggerArraySIze;
    std::vector<slogger> mvLogger;
    
};

#endif // LOGINI_HPP
