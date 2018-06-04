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
    Logging(const char *category, bool active, bool logcreate, LogLevel loglevellocal);
    Logging(const char *category, bool active, bool logcreate);
    Logging(const char *category, bool active);
    Logging(const char *category);

    ~Logging();

    void setLoggingActive(bool active) {misActive = active;}
    void setLogLevelLocal(LogLevel loglevel){mLogLevelLocal = loglevel;};

    static void setLogLevelGlobal(LogLevel loglevel);    

    Logging &operator<<(const LogLevel &loglevel)
    {
        mCurrentLogLevelLocal = loglevel;
        if(((true == misActive)||(mCurrentLogLevelLocal == LLcritical))
                &&(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
        }
        return *this;
    }

    template<class T>  Logging &operator<<(const T &msg)
    {
        if(((true == misActive)||(mCurrentLogLevelLocal == LLcritical))
                &&(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
            m_Stream << msg;
        }
        return *this;
    }

    template<class T>  Logging &operator<=(const T &msg)
    {
        if(((true == misActive)||(mCurrentLogLevelLocal == LLcritical))
            &&(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
            m_Stream << msg;
            if(mCurrentLogLevelLocal == LLcritical)
            {
                qCCritical(m_categrory) << m_Stream.str().c_str();
            }
            else if(mCurrentLogLevelLocal == LLwarning)
            {
                qCWarning(m_categrory) << m_Stream.str().c_str();
            }
            else if(mCurrentLogLevelLocal == LLdebug)
            {
                qCDebug(m_categrory) << m_Stream.str().c_str();
            }
            else if(mCurrentLogLevelLocal == LLinfo)
            {
                qCInfo(m_categrory) << m_Stream.str().c_str();
            }
            else
            {
                qCInfo(m_categrory) << m_Stream.str().c_str();
            }
            std::stringstream emptyStream;
            m_Stream.swap(emptyStream);
            mCurrentLogLevelLocal = mLogLevelLocal;
            mwritelocallevel = false;
        }
        return *this;
    }

    void createLogHeader(void)
    {
        if(false == mwritelocallevel)
        {
            if(mCurrentLogLevelLocal == LLcritical)
            {
                m_Stream << "[LLcritical]: ";
            }
            else if(mCurrentLogLevelLocal == LLwarning)
            {
                m_Stream << "[LLwarning]: ";
            }
            else if(mCurrentLogLevelLocal == LLdebug)
            {
                m_Stream << "[LLdebug]: ";
            }
            else if(mCurrentLogLevelLocal == LLinfo)
            {
                m_Stream << "[LLinfo]: ";
            }
            else
            {
                m_Stream << "[LLall]: ";
            }
            mwritelocallevel = true;
        }
    }

 private:
    QLoggingCategory m_categrory;
    bool misActive;
    bool mlogcreate;
    static LogLevel mLogLevelGlobal;    
    LogLevel mLogLevelLocal;
    LogLevel mCurrentLogLevelLocal;
    bool mwritelocallevel;
    std::stringstream m_Stream;

};

#endif // LOGGING_HPP
