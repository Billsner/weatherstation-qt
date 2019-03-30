#include "logfile.hpp"

#include <QTextStream>

Logfile::Logfile() :
    mfile("Log.log"),
    mfileopen(false),
    m_categrory("FileAccess.LogFile")
{

}

Logfile::~Logfile()
{

}

void Logfile::openFile()
{
    m_mutex.lock();
    if(true == mfile.open(QIODevice::WriteOnly))
    {
        mfileopen = true;
        //qCInfo(m_categrory) << "openFile: success";
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
    //qCInfo(m_categrory) << "closeFile";
    m_mutex.unlock();
}

void Logfile::writeLogMsg(const char *msg)
{
    m_mutex.lock();
    if((nullptr != msg)&&(true == mfileopen))
    {
        QTextStream toFile(&mfile);
        toFile << msg;
    }
    else
    {
        qCInfo(m_categrory) << "writeLogMsg: mfileopen: " << mfileopen;
    }
    m_mutex.unlock();
}
