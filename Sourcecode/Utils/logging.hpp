#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <QLoggingCategory>
#include "Utils/loggingdef.hpp"
#include "loggingserver.hpp"
#include <ostream>
#include <sstream>
#include "FileAccess/logfile.hpp"


class Logging
{
public:
    Logging(const char *category);

    ~Logging();

    void getLoggingSettings();

    Logging &operator<<(const LogLevel &loglevel)
    {
        mCurrentLogLevelLocal = loglevel;
        if(((true == misActive)&&(mCurrentLogLevelLocal <= mLogLevelLocal))
                ||(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
        }
        return *this;
    }

    template<class T>  Logging &operator<<(const T &msg)
    {
        if(((true == misActive)&&(mCurrentLogLevelLocal <= mLogLevelLocal))
                ||(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
            m_Stream << msg;
        }
        return *this;
    }

    template<class T>  Logging &operator<=(const T &msg)
    {
        if(((true == misActive)&&(mCurrentLogLevelLocal <= mLogLevelLocal))
                ||(mCurrentLogLevelLocal <= mLogLevelGlobal))
        {
            createLogHeader();
            m_Stream << msg;
            if((LMoutput == mLogMode)||(LMall == mLogMode))
            {
                qCInfo(m_categrory) << m_Stream.str().c_str();
            }
            if((LMfile == mLogMode)||(LMall == mLogMode))
            {                
                if(mpLoggingServer != NULL)
                {
                    m_Stream << "\n";
                    mpLoggingServer->writeLogMsg(m_Stream.str().c_str());
                }
            }
            m_Stream.str().clear();
            mCurrentLogLevelLocal = mLogLevelLocal;
            mwritelocallevel = false;
        }
        return *this;
    }

    void createLogHeader(void);

 private:
    QLoggingCategory m_categrory;
    const char *mLoggername;
    bool misActive;
    bool mlogcreate;
    LogLevel mLogLevelGlobal;
    LogMode mLogMode;
    LogLevel mLogLevelLocal;
    LogLevel mCurrentLogLevelLocal;
    bool mwritelocallevel;
    std::stringstream m_Stream;
    LoggingServer *mpLoggingServer;

};

#endif // LOGGING_HPP
