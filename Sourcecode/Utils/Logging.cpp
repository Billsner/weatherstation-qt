#include "Logging.hpp"

static LogLevel mLogLevelGlobal = LLcritical;

Logging::Logging(const char *category, bool active) :
    m_categrory(category),
    misActive(active)
{

}

Logging::~Logging()
{

}


void Logging::setLogLevelGlobal(LogLevel loglevel)
{
    mLogLevelGlobal = loglevel;
}
