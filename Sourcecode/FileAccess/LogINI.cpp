#include "LogINI.hpp"

#include <QTextStream>
#include <QLoggingCategory>

LogINI::LogINI() :
    mfileINI("Log.ini"),
    mfileLogger("LogLogger.ini"),
    mfileopen(false),
    m_categrory("FileAccess.LogINI")
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
    }
    else
    {
        mfileopen = false;
        qCInfo(m_categrory) << "openFile mfileINI: failed";
    }
    if(true == mfileLogger.open(QIODevice::WriteOnly))
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

void LogINI::writeLoggerList(const char *msg)
{
    m_mutex.lock();
    if(NULL != msg)
    {
        QTextStream toFile(&mfileLogger);
        toFile << msg << "/n";
    }
    else
    {
        qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}
