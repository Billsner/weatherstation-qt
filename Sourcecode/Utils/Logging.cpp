#include "Logging.hpp"
#include <QTime>

Logging::Logging(const char *Loggername) :
    m_categrory("CLog"),
    mLoggername(Loggername),
    misActive(false),
    mlogcreate(false),
    mLogLevelGlobal(LLOFF),
    mLogMode(LMnoLog),
    mLogLevelLocal(LLOFF),
    mCurrentLogLevelLocal(LLOFF),
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
            mLogLevelLocal = LLcritical;
            mLogMode = LMoutput;
            *this << LLcritical << "log config: default config " << mLoggername << misActive << mlogcreate << mLogLevelLocal << mLogMode << loggerid;
        }
        *this << LLinfo << "log config: " << mLoggername << misActive << mlogcreate << mLogLevelLocal << mLogMode << loggerid;
    }
}

void Logging::createLogHeader(void)
{
    if(false == mwritelocallevel)
    {
        m_Stream << QTime::currentTime().toString("hh:mm:ss.zzz").toStdString() << " ";
        if(mCurrentLogLevelLocal == LLcritical)
        {
            m_Stream << mLoggername << " [LLcritical]: " ;
        }
        else if(mCurrentLogLevelLocal == LLwarning)
        {
            m_Stream <<  mLoggername << " [LLwarning]: ";
        }
        else if(mCurrentLogLevelLocal == LLdebug)
        {
            m_Stream <<  mLoggername << " [LLdebug]: ";
        }
        else if(mCurrentLogLevelLocal == LLinfo)
        {
            m_Stream <<  mLoggername << " [LLinfo]: ";
        }
        else
        {
            m_Stream <<  mLoggername << " [LLall]: ";
        }
        mwritelocallevel = true;
    }
}
