#include "LogINI.hpp"

#include <QTextStream>
#include <QLoggingCategory>

LogINI::LogINI() :
    mfileINI("Log.ini"),
    mfileLogger("LogLogger.ini"),
    mfileopen(false),
    m_categrory("FileAccess.LogINI"),
    mGlobalLogLevel(LLOFF),
    mGlobalLogMode(LMoutput)

{

}

LogINI::~LogINI()
{

}

void LogINI::openFile()
{
    m_mutex.lock();
    if(true == mfileINI.open(QIODevice::ReadOnly))
    {
        mfileopen = true;
        //qCInfo(m_categrory) << "openFile mfileINI: success";
        loadINI();
    }
    else
    {
        mfileopen = false;
        qCInfo(m_categrory) << "openFile mfileINI: failed";
    }
    if(true == mfileLogger.open(QIODevice::ReadWrite))
    {
        //qCInfo(m_categrory) << "openFile mfileLogger: success";
    }
    else
    {
        qCInfo(m_categrory) << "openFile mfileLogger: failed";
    }
    m_mutex.unlock();
}

void LogINI::closeFile()
{
    m_mutex.lock();
    mfileINI.close();
    mfileLogger.close();
    mfileopen = false;
    //qCInfo(m_categrory) << "closeFile";
    m_mutex.unlock();
}

void LogINI::loadINI(void)
{
    QTextStream in(&mfileINI);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        processReadLine(line);
    }
}

void LogINI::getLoggerID(QString LoggerName, int &loggerid)
{
    loggerid = invalidLogID;
    for(unsigned int i = 0; (i < mvLogger.size()) && (loggerid == invalidLogID); i++)
    {
        if(mvLogger[i].loggername == LoggerName)
        {
            loggerid = static_cast<int>(i);
        }
    }
    //qCInfo(m_categrory) << "getLoggerID: LoggerName: " << LoggerName << " id " << loggerid;
}

void LogINI::getLogLevel(int Loggerid, LogLevel &level)
{
    if((Loggerid < mvLogger.size())&&(Loggerid >= 0))
    {
       level = mvLogger[Loggerid].loglevel;
    }
}

void LogINI::getLogMode(int Loggerid, LogMode &mod)
{
    if((Loggerid < mvLogger.size())&&(Loggerid >= 0))
    {
       mod = mvLogger[Loggerid].logmode;
    }
}

void LogINI::getLogActive(int Loggerid, bool &active)
{
    if((Loggerid < mvLogger.size())&&(Loggerid >= 0))
    {
       active = mvLogger[Loggerid].logon;
    }
}

void LogINI::getLogConstr(int Loggerid, bool &constr)
{
    if((Loggerid < mvLogger.size())&&(Loggerid >= 0))
    {
       constr = mvLogger[Loggerid].logconstr;
    }
}



void LogINI::processReadLine(QString line)
{
    if(line.contains("GlobalLogLevel"))
    {
        QString level = line.section(" ",1,1);
        mGlobalLogLevel = getLogLevelFromString(level);
        //qCInfo(m_categrory) << "processReadLine mGlobalLogLevel " << mGlobalLogLevel;
    }
    else if(line.contains("GlobalLogMode"))
    {
        QString mod = line.section(" ",1,1);
        mGlobalLogMode = getLogModFromString(mod);
        //qCInfo(m_categrory) << "processReadLinemGlobalLogMode " << mGlobalLogMode;
    }
    else
    {
        setLogger(line);
    }
}

void LogINI::setLogger(QString LoggerEntry)
{
    //qCInfo(m_categrory) << "setLogger: " << LoggerEntry;
    QString loggername = LoggerEntry.section(" ",0,0);
    int loggerid = invalidLogID;
    getLoggerID(loggername,loggerid);
    if(loggerid == invalidLogID)
    {
        //qCInfo(m_categrory) << "setLogger loggername: " << loggername;
        QString loggerlevel = LoggerEntry.section(" ",1,1);
        QString loggermode = LoggerEntry.section(" ",2,2);
        QString loggeractive = LoggerEntry.section(" ",3,3);
        QString loggercronstr = LoggerEntry.section(" ",4,4);
        slogger newlogger;
        newlogger.loggername = loggername;
        newlogger.loglevel = getLogLevelFromString(loggerlevel);
        newlogger.logmode = getLogModFromString(loggermode);
        newlogger.logon = getLogActiveFromString(loggeractive);
        newlogger.logconstr = getLogContrFromString(loggercronstr);
        mvLogger.push_back(newlogger);
        //qCInfo(m_categrory) << "setLogger loggername: " << loggername << " Size " << mvLogger.size();
    }
}


LogLevel LogINI::getLogLevelFromString(QString level)
{
    LogLevel ret = LLOFF;    
    if(level == "LLcritical")
    {
        ret = LLcritical;
    }
    else if(level == "LLwarning")
    {
        ret = LLwarning;
    }
    else if(level == "LLdebug")
    {
        ret = LLdebug;
    }
    else if(level == "LLinfo")
    {
        ret = LLinfo;
    }
    else if(level == "LLALL")
    {
        ret = LLALL;
    }
    //qCInfo(m_categrory) << "getLogLevelFromString: " << level  << " ret " << ret;
    return ret;
}

LogMode LogINI::getLogModFromString(QString mod)
{
    LogMode ret = LMnoLog;
    if(mod == "LMnoLog")
    {
        ret = LMnoLog;
    }
    else if(mod == "LMfile")
    {
        ret = LMfile;
    }
    else if(mod == "LMall")
    {
        ret = LMall;
    }
    //qCInfo(m_categrory) << "getLogModFromString: " << mod  << " ret " << ret;
    return ret;
}

bool LogINI::getLogActiveFromString(QString active)
{
    bool ret = false;
    if((active == "active")||(active == "1"))
    {
        ret = true;
    }
    //qCInfo(m_categrory) << "getLogActiveFromString: " << active << " ret " << ret;
    return ret;
}

bool LogINI::getLogContrFromString(QString constr)
{
    bool ret = false;
    if((constr == "logconstructer")||(constr == "1"))
    {
        ret = true;
    }
    //qCInfo(m_categrory) << "getLogContrFromString: " << constr << " ret " << ret;
    return ret;
}

void LogINI::writeLoggerList(const char *msg)
{
    m_mutex.lock();
    if(NULL != msg)
    {
        QTextStream toFile(&mfileLogger);
        toFile << msg << endl;
    }
    else
    {
        //qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}




