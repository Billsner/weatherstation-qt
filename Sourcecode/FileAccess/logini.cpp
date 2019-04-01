#include "logini.hpp"

#include <QTextStream>
#include <QLoggingCategory>
#include <QDir>
#include <QCoreApplication>

LogINI::LogINI() :
    mfileINI("./cfg/Log.ini"),
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
    bool  fileexists = false;

    if(!QDir::setCurrent(QCoreApplication::applicationDirPath()))
    {
         qCInfo(m_categrory) << "openFile mfileINI: Path: " << QCoreApplication::applicationDirPath();
    }
    else
    {
        qCInfo(m_categrory) << "openFile mfileINI: Path change to: " << QCoreApplication::applicationDirPath();
    }
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QDir cfgfolder("cfg");
    if(!cfgfolder.exists())
    {
        QDir appfolder("");
        if(!appfolder.mkdir("cfg"))
        {
            qCInfo(m_categrory) << "mkdir cfg failed";
        }
    }
    if(mfileINI.exists())
    {
        fileexists = true;
    }
    if(true == mfileINI.open(QIODevice::ReadWrite))
    {
        if(fileexists == true)
        {
            loadINI();
        }
        else
        {
            writeDefaultGlobalLog();
        }
    }
    else
    {
        qCInfo(m_categrory) << "openFile mfileINI: failed";

    }
    m_mutex.unlock();
}

void LogINI::closeFile()
{
    m_mutex.lock();
    mfileINI.close();
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

void LogINI::getLoggerID(QString LoggerName, unsigned int &loggerid)
{
    loggerid = invalidLogID;
    for(uint32_t i = 0; (i < mvLogger.size()) && (loggerid == invalidLogID); i++)
    {
        if(mvLogger[i].loggername == LoggerName)
        {
            loggerid = i;
        }
    }
    //qCInfo(m_categrory) << "getLoggerID: LoggerName: " << LoggerName << " id " << loggerid;
}

void LogINI::getLogLevel(uint32_t Loggerid, LogLevel &level)
{
    if((Loggerid < mvLogger.size()))
    {
       level = mvLogger[Loggerid].loglevel;
    }
}

void LogINI::getLogMode(uint32_t Loggerid, LogMode &mod)
{
    if((Loggerid < mvLogger.size()))
    {
       mod = mvLogger[Loggerid].logmode;
    }
}

void LogINI::getLogActive(uint32_t Loggerid, bool &active)
{
    if((Loggerid < mvLogger.size()))
    {
       active = mvLogger[Loggerid].logon;
    }
}

void LogINI::getLogConstr(uint32_t Loggerid, bool &constr)
{
    if((Loggerid < mvLogger.size()))
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
    uint32_t loggerid = invalidLogID;
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

void LogINI::writeDefaultLogEntry(const char *msg)
{
    m_mutex.lock();
    if(nullptr != msg)
    {
        QString newLogger(msg);
        uint32_t loggerid = invalidLogID;
        getLoggerID(newLogger,loggerid);
        if(loggerid == invalidLogID)
        {
            newLogger = newLogger + " LLinfo" + " LMall";
            QTextStream toFile(&mfileINI);
            setLogger(newLogger);
            toFile << newLogger << endl;
        }
    }
    else
    {
        //qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}

void LogINI::writeDefaultGlobalLog(void)
{
    QString newLogger("GlobalLogLevel");
    newLogger = newLogger + " LLcritical";
    mGlobalLogLevel = LLcritical;
    QTextStream toFile(&mfileINI);
    toFile << newLogger << endl;
    newLogger = "GlobalLogMode";
    newLogger = newLogger + " LMall";
    mGlobalLogMode = LMall;
    toFile << newLogger << endl;
}



