#include "LoggingServer.hpp"


LoggingServer::LoggingServer() :
    mpLoggingServer(this),
    mGlobalLogLevel(LLcritical),
    mGlobalLogMode(LMoutput)
{

}

LoggingServer::~LoggingServer()
{

}

void LoggingServer::init()
{

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
