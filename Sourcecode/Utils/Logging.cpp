#include "Logging.hpp"

LogLevel Logging::mLogLevelGlobal = LLdebug;

Logging::Logging(const char *category, bool active/* = false*/, bool logcreate /*= false*/) :
    m_categrory(category),
    misActive(active),
    mlogcreate(logcreate),
    mLogLevelLocal(LLcritical)
{
    if((true == mlogcreate)&&(this != NULL))
    {
        *this <= "Constructer";
    }
}

Logging::Logging(const char *category, bool active/* = false*/) :
    m_categrory(category),
    misActive(active),
    mlogcreate(false),
    mLogLevelLocal(LLcritical)
{

}

Logging::Logging(const char *category) :
    m_categrory(category),
    misActive(false),
    mlogcreate(false),
    mLogLevelLocal(LLcritical)
{

}

Logging::~Logging()
{
    if(true == mlogcreate)
    {
        *this <= "Destructer";
    }
}


void Logging::setLogLevelGlobal(LogLevel loglevel)
{
    Logging::mLogLevelGlobal = loglevel;
}
