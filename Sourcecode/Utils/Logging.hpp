#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <QLoggingCategory>

enum LogLevel
{
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo,
    LLall
};

class Logging
{
public:
    Logging(const char *category, bool active);
    ~Logging();

    void setLoggingActive(bool active) {misActive = active;}

    static void setLogLevelGlobal(LogLevel loglevel);

private:
    QLoggingCategory m_categrory;
    bool misActive;
};

#endif // LOGGING_HPP
