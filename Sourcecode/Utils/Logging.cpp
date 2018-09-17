#include "Logging.hpp"

Logging::Logging(const char *category, bool active, bool logcreate, LogLevel loglevellocal) :
    m_categrory("QLog"),
    mLoggername(category),
    misActive(active),
    mlogcreate(logcreate),
    mLogLevelGlobal(LLdebug),
    mLogMode(LMoutput),
    mLogLevelLocal(loglevellocal),
    mCurrentLogLevelLocal(loglevellocal),
    mwritelocallevel(false),
    mpLoggingServer(NULL)
{
    getLoggingSettings();
    if(true == mlogcreate)
    {
        *this << "Constructer  this: " <= this;
    }
}

Logging::Logging(const char *category, bool active/* = false*/, bool logcreate /*= false*/) :
    m_categrory("QLog"),
    mLoggername(category),
    misActive(active),    
    mlogcreate(logcreate),
    mLogLevelGlobal(LLdebug),
    mLogMode(LMoutput),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false),
    mpLoggingServer(NULL)
{
    getLoggingSettings();
    if(true == mlogcreate)
    {
        *this << "Constructer  this: " <= this;
    }
}

Logging::Logging(const char *category, bool active/* = false*/) :
    m_categrory("QLog"),
    mLoggername(category),
    misActive(active),
    mlogcreate(false),
    mLogLevelGlobal(LLdebug),
    mLogMode(LMoutput),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false),
    mpLoggingServer(NULL)
{
    getLoggingSettings();
}

Logging::Logging(const char *category) :
    m_categrory("QLog"),
    mLoggername(category),
    misActive(false),
    mlogcreate(false),
    mLogLevelGlobal(LLdebug),
    mLogMode(LMoutput),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false),
    mpLoggingServer(NULL)
{
    getLoggingSettings();
}

Logging::~Logging()
{
    if(true == mlogcreate)
    {
        *this << "Destructer this: " <= this ;
    }
}

void Logging::getLoggingSettings()
{
    mpLoggingServer = LoggingServer::getInstance();
    if(NULL != mpLoggingServer)
    {
        int loggerid = invalidLogID;
        mpLoggingServer->getGlobalLogLevel(mLogLevelGlobal);
        mpLoggingServer->getGlobalLogMode(mLogMode);
        mpLoggingServer->getLoggerID(mLoggername,loggerid);
        if(loggerid != invalidLogID)
        {
            mpLoggingServer->getLoggerActive(loggerid,misActive);
            mpLoggingServer->getLoggerCreate(loggerid,mlogcreate);
            mpLoggingServer->getLoggerLevel(loggerid,mLogLevelLocal);
            mpLoggingServer->getLoggerMode(loggerid,mLogMode);
        }
        else
        {
            misActive = false;
            mlogcreate = false;
            mLogLevelLocal = LLOFF;
            mLogMode = LMoutput;
        }
        qCInfo(m_categrory) << "log config: " << mLoggername << misActive << mlogcreate << mLogLevelLocal << mLogMode << loggerid;
    }
}
