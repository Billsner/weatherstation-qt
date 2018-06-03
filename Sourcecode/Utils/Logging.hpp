#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <QLoggingCategory>
#include <ostream>
#include <sstream>

enum LogLevel
{
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo
};


class Logging
{
public:
    Logging(const char *category, bool active, bool logcreate);
    Logging(const char *category, bool active);
    Logging(const char *category);

    ~Logging();

    void setLoggingActive(bool active) {misActive = active;}

    static void setLogLevelGlobal(LogLevel loglevel);    

    Logging &operator<<(const LogLevel &loglevel)
    {
        mLogLevelLocal = loglevel;
        if((true == misActive)&&(mLogLevelLocal <= mLogLevelGlobal))
        {
            if(mLogLevelLocal == LLcritical)
            {
                m_Stream << "[LLcritical]: ";
            }
            else if(mLogLevelLocal == LLwarning)
            {
                m_Stream << "[LLwarning]: ";
            }
            else if(mLogLevelLocal == LLdebug)
            {
                m_Stream << "[LLdebug]: ";
            }
            else if(mLogLevelLocal == LLinfo)
            {
                m_Stream << "[LLinfo]: ";
            }
            else
            {
                m_Stream << "[LLall]: ";
            }
        }
        return *this;
    }

    template<class T>  Logging &operator<<(const T &msg)
    {
        if(true == misActive)
        {
            m_Stream << msg;
        }
        return *this;
    }

    template<class T>  Logging &operator<=(const T &msg)
    {
        if((true == misActive)&&(mLogLevelLocal <= mLogLevelGlobal))
        {
            m_Stream << msg;
            if(mLogLevelLocal == LLcritical)
            {
                qCCritical(m_categrory) << m_Stream.str().c_str();
            }
            else if(mLogLevelLocal == LLwarning)
            {
                qCWarning(m_categrory) << m_Stream.str().c_str();
            }
            else if(mLogLevelLocal == LLdebug)
            {
                qCDebug(m_categrory) << m_Stream.str().c_str();
            }
            else if(mLogLevelLocal == LLinfo)
            {
                qCInfo(m_categrory) << m_Stream.str().c_str();
            }
            else
            {
                qCInfo(m_categrory) << m_Stream.str().c_str();
            }
            std::stringstream emptyStream;
            m_Stream.swap(emptyStream);
            if(mLogLevelLocal == LLcritical)
            {
                m_Stream << "[LLcritical]: ";
            }
            else if(mLogLevelLocal == LLwarning)
            {
                m_Stream << "[LLwarning]: ";
            }
            else if(mLogLevelLocal == LLdebug)
            {
                m_Stream << "[LLdebug]: ";
            }
            else if(mLogLevelLocal == LLinfo)
            {
                m_Stream << "[LLinfo]: ";
            }
            else
            {
                m_Stream << "[LLall]: ";
            }
        }
        return *this;
    }

private:
    QLoggingCategory m_categrory;
    bool misActive;
    bool mlogcreate;
    static LogLevel mLogLevelGlobal;
    bool msetlocallevel;
    LogLevel mLogLevelLocal;
    std::stringstream m_Stream;

};

#endif // LOGGING_HPP
