#include "LoggingServer.hpp"
#include <QMutex>

static LoggingServer *mpLoggingServer = NULL;

LoggingServer::LoggingServer() :
    mGlobalLogLevel(LLOFF),
    mGlobalLogMode(LMall)
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
    level = mGlobalLogLevel;
    m_mutex.unlock();
}

void LoggingServer::getGlobalLogMode(LogMode &mode)
{
    m_mutex.lock();
    mode = mGlobalLogMode;
    m_mutex.unlock();
}

//Loggerfuntions
void LoggingServer::getLoggerID(const char *category, int &ID)
{
    m_mutex.lock();
    mLogINI.writeLoggerList(category);
    ID = invalidLogID;
    m_mutex.unlock();
}

void LoggingServer::getLoggerLevel(int loggerID, LogLevel &level)
{
    m_mutex.lock();

    m_mutex.unlock();
}

void LoggingServer::getLoggerMode(int loggerID, LogMode &mode)
{
    m_mutex.lock();

    m_mutex.unlock();
}

void LoggingServer::getLoggerActive(int loggerID, bool &active)
{
    m_mutex.lock();

    m_mutex.unlock();
}

void LoggingServer::getLoggerCreate(int loggerID, bool &create)
{
    m_mutex.lock();

    m_mutex.unlock();
}

void LoggingServer::writeLogMsg(const char *msg)
{
    m_mutexlogfile.lock();
    mLogfile.writeLogMsg(msg);
    m_mutexlogfile.unlock();
}
