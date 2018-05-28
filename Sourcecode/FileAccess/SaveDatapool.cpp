#include "SaveDatapool.hpp"
#include <QFile>
#include <QTextStream>

static SaveDatapool *mpSaveDatapool = NULL;

SaveDatapool::SaveDatapool() :
    mfilename("datapool.data"),
    mfile(mfilename),
    mHeaderOffset(0),
    m_categrory("fileaccess.SaveDatapool")
{
    mpSaveDatapool = this;
}

SaveDatapool::~SaveDatapool()
{
    mpSaveDatapool = NULL;
}

SaveDatapool *SaveDatapool::getInstance()
{
    return mpSaveDatapool;
}

void SaveDatapool::openFile()
{
    if(true == mfile.open(QIODevice::ReadWrite))
    {
        qCDebug(m_categrory) << "openFile: successful";
    }
    else
    {
        qCDebug(m_categrory) << "openFile: error";
    }
}

void SaveDatapool::closeFile()
{
    mfile.close();
    qCDebug(m_categrory) << "closeFile";
}

void SaveDatapool::setHeader()
{
    QTextStream writedata(&mfile);
    int major = 34;
    int minor = 25;
    writedata << major;
    writedata << endl;
    writedata << minor;
    writedata << endl;
    qCDebug(m_categrory) << "setHeader: major: " << major << " minor " << minor;
    writedata.flush();
}

int SaveDatapool::readHeader()
{
    QTextStream readdata(&mfile);
    int major = 0;
    int minor = 0;
    readdata >> major;
    readdata >> minor;
    qCDebug(m_categrory) << "readHeader: major: " << major << " minor " << minor;
    return major;
}

void SaveDatapool::saveLine(unsigned int id, char *data, int datasize)
{
    QTextStream writedata(&mfile);
    writedata << id;
    writedata << endl;
    writedata.flush();
    qCDebug(m_categrory) << "saveLine: id: " << id;
}

void SaveDatapool::loadLine(unsigned int id, char *data, int &datasize)
{
    int store;
    QTextStream readdata(&mfile);
    readdata >> store;
    qCDebug(m_categrory) << "loadLine: id: " << id << " store " << store;
}
