#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <QLoggingCategory>
#include <ostream>
#include <sstream>
#include "FileAccess/LogFile.hpp"

enum LogLevel
{
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo
};

enum LogMode
{
    LMoutput,
    LMfile,
    LMall
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
    static void setLogMode(LogMode logmode);

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
            if((LMoutput == mLogMode)||(LMall == mLogMode))
            {
                qCDebug(m_categrory) << m_Stream.str().c_str();
            }
            if((LMfile == mLogMode)||(LMall == mLogMode))
            {
                bool ret = false;
                Logfile *pLogfile = Logfile::getInstance();
                if(pLogfile != NULL)
                {
                    m_Stream << "\n";
                    pLogfile->writeLogMsg(m_Stream.str().c_str(),ret);
                }
                if(((pLogfile == NULL)||(false == ret))&&(LMall == LMfile))
                {
                    qCInfo(m_categrory) << m_Stream.str().c_str();
                }
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
                m_Stream << mLoggername << " [LLcritical]: ";
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

 private:
    QLoggingCategory m_categrory;
    const char *mLoggername;
    bool misActive;
    bool mlogcreate;
    static LogLevel mLogLevelGlobal;
    static LogMode mLogMode;
    LogLevel mLogLevelLocal;
    LogLevel mCurrentLogLevelLocal;
    bool mwritelocallevel;
    std::stringstream m_Stream;

};

#endif // LOGGING_HPP
