#include "Logging.hpp"

LogLevel Logging::mLogLevelGlobal = LLdebug;


Logging::Logging(const char *category, bool active, bool logcreate, LogLevel loglevellocal) :
    m_categrory(category),
    misActive(active),
    mlogcreate(logcreate),
    mLogLevelLocal(loglevellocal),
    mCurrentLogLevelLocal(loglevellocal),
    mwritelocallevel(false)
{
    if((true == mlogcreate)&&(this != NULL))
    {
        *this << "Constructer  this: " <= this;
    }
}

Logging::Logging(const char *category, bool active/* = false*/, bool logcreate /*= false*/) :
    m_categrory(category),
    misActive(active),
    mlogcreate(logcreate),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false)
{
    if((true == mlogcreate)&&(this != NULL))
    {
        *this << "Constructer  this: " <= this;
    }
}

Logging::Logging(const char *category, bool active/* = false*/) :
    m_categrory(category),
    misActive(active),
    mlogcreate(false),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false)
{

}

Logging::Logging(const char *category) :
    m_categrory(category),
    misActive(false),
    mlogcreate(false),
    mLogLevelLocal(LLinfo),
    mCurrentLogLevelLocal(LLinfo),
    mwritelocallevel(false)
{

}

Logging::~Logging()
{
    if(true == mlogcreate)
    {
        *this << "Destructer this: " <= this ;
    }
}


void Logging::setLogLevelGlobal(LogLevel loglevel)
{
    Logging::mLogLevelGlobal = loglevel;
}
