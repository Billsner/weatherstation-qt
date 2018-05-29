#include "SaveDatapool.hpp"
#include <QFile>
#include <QTextStream>

static SaveDatapool *mpSaveDatapool = NULL;

SaveDatapool::SaveDatapool() :
    m_categrory("fileaccess.SaveDatapool"),
    mfilename("datapool.data"),
    mfile(mfilename),
    mbufferindex(0),
    mNeedSaveAll(true),
    mBufferLoaded(false),
    mBufferReadytoSave(false)
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

void SaveDatapool::prepareBuffer()
{
    if(4 < sizeof(mBuffer))
    {
        mBufferReadytoSave = true;
        mbufferindex = 0;
        mBuffer[mbufferindex] = 1; //0: major-version
        mbufferindex++;
        mBuffer[mbufferindex] = 1; //1: minor-version
        mbufferindex++;
        mBuffer[mbufferindex] = static_cast<char>(DIcount&0x00ff); //2: count of DIcount
        mbufferindex++;
        mBuffer[mbufferindex] = static_cast<char>((DIcount&0xff00)>>8); //3: count of DIcount
        mbufferindex = mbufferindex + (DIcount*2) + 1;
    }
}

void SaveDatapool::closeBuffer()
{
    int index = 4;
    if((index+(DIcount*2)) < sizeof(mBuffer))
    {
        for(int diindex = 0; diindex < DIcount; diindex++)
        {
            mBuffer[index] = static_cast<char>(mPosDatapoolEntry[diindex]&0x00ff);
            index++;
            mBuffer[index] = static_cast<char>((mPosDatapoolEntry[diindex]&0xff00)>>8);
            index++;
        }
    }
    if((true == mBufferReadytoSave)&&(mbufferindex < sizeof(mBuffer)))
    {
        QDataStream write(&mfile);
        write.writeRawData(mBuffer,mbufferindex);
    }
}

void SaveDatapool::saveID(unsigned int id, char *data, int datasize)
{
    if(((datasize+mbufferindex+4) < sizeof(mBuffer))&&(id < DIcount))
    {
        mPosDatapoolEntry[id] = mbufferindex;
        mBuffer[mbufferindex] = static_cast<char>(id&0x00ff);
        mbufferindex++;
        mBuffer[mbufferindex] = static_cast<char>((id&0xff00)>>8);
        mbufferindex++;
        mBuffer[mbufferindex] = static_cast<char>(datasize&0x00ff);
        mbufferindex++;
        mBuffer[mbufferindex] = static_cast<char>((datasize&0xff00)>>8);
        mbufferindex++;
        if(((mbufferindex+datasize) < sizeof(mBuffer))&&(datasize > 0)&&(NULL != data))
        {
            memcpy(&mBuffer[mbufferindex],data,datasize);
            mbufferindex = mbufferindex+datasize;
        }
    }
    else
    {
        mBufferReadytoSave = false;
    }
}

void SaveDatapool::loadID(unsigned int id, char *data, int &datasize)
{
    int store;
    QTextStream readdata(&mfile);
    readdata >> store;
    qCDebug(m_categrory) << "loadLine: id: " << id << " store " << store;
}
