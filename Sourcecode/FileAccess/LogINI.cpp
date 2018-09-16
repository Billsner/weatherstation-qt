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
        qCInfo(m_categrory) << "openFile mfileINI: success";
        loadINI();
    }
    else
    {
        mfileopen = false;
        qCInfo(m_categrory) << "openFile mfileINI: failed";
    }
    if(true == mfileLogger.open(QIODevice::ReadWrite))
    {
        qCInfo(m_categrory) << "openFile mfileLogger: success";
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
    qCInfo(m_categrory) << "closeFile";
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
        qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}

void LogINI::processReadLine(QString line)
{
    if(line.contains("GlobalLogLevel"))
    {
        QString level = line.section(" ",1,1);
        mGlobalLogLevel = getLogLevelFromString(level);
        qCInfo(m_categrory) << " mGlobalLogLevel " << mGlobalLogLevel;
    }
    else if(line.contains("GlobalLogMode"))
    {
        QString mod = line.section(" ",1,1);
        mGlobalLogMode = getLogModFromString(mod);
        qCInfo(m_categrory) << " mGlobalLogMode " << mGlobalLogMode;
    }
    else
    {

    }
}

LogLevel LogINI::getLogLevelFromString(QString level)
{
    LogLevel ret = LLOFF;
    qCInfo(m_categrory) << "level: " << level;
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
    return ret;
}

LogMode LogINI::getLogModFromString(QString mod)
{
    LogMode ret = LMoutput;
    qCInfo(m_categrory) << "mod: " << mod;
    if(mod == "LMfile")
    {
        ret = LMfile;
    }
    else if(mod == "LMall")
    {
        ret = LMall;
    }
    return ret;
}
