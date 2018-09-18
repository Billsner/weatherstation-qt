#include "LoggingServer.hpp"
#include <QMutex>

static LoggingServer *mpLoggingServer = NULL;

LoggingServer::LoggingServer()
{
    mpLoggingServer = this;
}

LoggingServer::~LoggingServer()
{
    mpLoggingServer = NULL;
}

LoggingServer *LoggingServer::getInstance()
{
    return mpLoggingServer;
}

void LoggingServer::init()
{
    m_mutexlogfile.lock();
    mLogfile.openFile();
    mLogINI.openFile();
    m_mutexlogfile.unlock();
}

void LoggingServer::finish()
{
    m_mutexlogfile.lock();
    mLogfile.closeFile();
    mLogINI.closeFile();
    m_mutexlogfile.unlock();
}

void LoggingServer::getGlobalLogLevel(LogLevel &level)
{
    m_mutex.lock();
    mLogINI.getGlobalLogLevel(level);
    m_mutex.unlock();
}

void LoggingServer::getGlobalLogMode(LogMode &mode)
{
    m_mutex.lock();
    mLogINI.getGlobalLogMode(mode);
    m_mutex.unlock();
}

//Loggerfuntions
void LoggingServer::getLoggerID(const char *category, int &ID)
{
    m_mutex.lock();
    mLogINI.getLoggerID(category,ID);
    mLogINI.writeLoggerList(category);
    m_mutex.unlock();
}

void LoggingServer::getLoggerLevel(int loggerID, LogLevel &level)
{
    m_mutex.lock();
    mLogINI.getLogLevel(loggerID,level);
    m_mutex.unlock();
}

void LoggingServer::getLoggerMode(int loggerID, LogMode &mode)
{
    m_mutex.lock();
    mLogINI.getLogMode(loggerID,mode);
    m_mutex.unlock();
}

void LoggingServer::getLoggerActive(int loggerID, bool &active)
{
    m_mutex.lock();
    mLogINI.getLogActive(loggerID,active);
    m_mutex.unlock();
}

void LoggingServer::getLoggerCreate(int loggerID, bool &create)
{
    m_mutex.lock();
    mLogINI.getLogConstr(loggerID,create);
    m_mutex.unlock();
}

void LoggingServer::writeLogMsg(const char *msg)
{
    m_mutexlogfile.lock();
    mLogfile.writeLogMsg(msg);
    m_mutexlogfile.unlock();
}
