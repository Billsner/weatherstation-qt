#include "logfile.hpp"
#include <QTextStream>
#include <QDir>
#include <QDate>

Logfile::Logfile() :
    mfile(),
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
    QDir cfgfolder("log");
    if(!cfgfolder.exists())
    {
        QDir appfolder("");
        if(!appfolder.mkdir("log"))
        {
            qCInfo(m_categrory) << "openFile: error create folder";
        }
    }
    QDate currentdate = QDate::currentDate();;
    QString filename = "./log/" + currentdate.toString("yyyy")
            +currentdate.toString("MM")
            +currentdate.toString("dd")
            + "_Log.txt";
    qCInfo(m_categrory) << "openFile: " << filename;
    mfile.setFileName(filename);
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
