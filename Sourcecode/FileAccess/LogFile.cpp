#include "LogFile.hpp"

#include <QTextStream>
#include <QLoggingCategory>

static Logfile *mpLogfile = NULL;
QLoggingCategory m_categrory("FileAccess.LogFile");

Logfile::Logfile() :
    mfile("Log.log"),
    mfileopen(false)
{
    mpLogfile = this;
}

Logfile::~Logfile()
{
    mpLogfile = NULL;
}

Logfile *Logfile::getInstance()
{
    return mpLogfile;
}

void Logfile::openFile()
{
    m_mutex.lock();
    if(true == mfile.open(QIODevice::WriteOnly))
    {
        mfileopen = true;
        qCInfo(m_categrory) << "openFile: success";
    }
    else
    {
        mfileopen = false;
        qCInfo(m_categrory) << "openFile: failed";
    }
    m_mutex.unlock();
}

void Logfile::closeFile()
{
    m_mutex.lock();
    mfile.close();
    mfileopen = false;
    qCInfo(m_categrory) << "closeFile";
    m_mutex.unlock();
}

void Logfile::writeLogMsg(const char *msg, bool &ret)
{
    m_mutex.lock();
    if((NULL != msg)&&(true == mfileopen))
    {
        QTextStream toFile(&mfile);
        toFile << msg;
        ret = true;
    }
    else
    {
        ret = false;
        qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}
