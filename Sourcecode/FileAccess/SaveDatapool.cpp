#include "SaveDatapool.hpp"
#include <QFile>
#include <QTextStream>

static SaveDatapool *mpSaveDatapool = NULL;

enum bufferheaderindex
{
    bmajorlow,
    bmajorhigh,
    bminorlow,
    bminorhigh,
    bdiindexlow,
    bdiindexhigh,

    bhcount
};

enum bufferitemindex
{
    idlow,
    idhigh,
    datasizelow,
    datasizehigh,

    bicount
};

int DatapoolMajorVersion = 1; //change as incompatible if datapoolid is add at start or in the middle
int DatapoolMinorVersion = 1; //change as compatible if datapoolid is add at the end


SaveDatapool::SaveDatapool() :
    m_categrory("fileaccess.SaveDatapool"),
    mfilename("datapool.data"),
    mfile(mfilename),
    mbufferindex(0),
    mNeedSaveAll(true),
    mBufferLoaded(false),
    mBufferReadytoSave(false),
    mbuffersizeload(0)
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
        mBuffer[bmajorlow] = static_cast<char>(DatapoolMajorVersion&0x00ff); //0: major-version
        mBuffer[bmajorhigh] = static_cast<char>((DatapoolMajorVersion&0xff00)>>8);; //0: major-version
        mBuffer[bminorlow] = static_cast<char>(DatapoolMinorVersion&0x00ff); //1: minor-version
        mBuffer[bminorhigh] = static_cast<char>((DatapoolMinorVersion&0xff00)>>8);; //1: minor-version
        mBuffer[bdiindexlow] = static_cast<char>(DIcount&0x00ff); //2: count of DIcount
        mBuffer[bdiindexhigh] = static_cast<char>((DIcount&0xff00)>>8); //3: count of DIcount
        mbufferindex = bhcount + (DIcount*2);
        qCDebug(m_categrory) << "prepareBuffer";
    }
}

void SaveDatapool::closeBuffer()
{
    unsigned int index = 4;
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
        qCDebug(m_categrory) << "closeBuffer: write";
    }
}

void SaveDatapool::loadBuffer()
{
    QDataStream read(&mfile);
    mbuffersizeload = read.readRawData(mBuffer,sizeof(mBuffer));
    if((bhcount <= mbuffersizeload)&&(bhcount <= sizeof(mBuffer)))
    {
        char buffermajorversion = static_cast<int>(mBuffer[bmajorhigh] << 8) + mBuffer[bmajorlow];
        char bufferminorversion = static_cast<int>(mBuffer[bminorhigh] << 8) + mBuffer[bminorlow];
        mbufferDIcountload = static_cast<int>(mBuffer[bdiindexhigh] << 8) + mBuffer[bdiindexlow];
        if(buffermajorversion == DatapoolMajorVersion)
        {
            if((bufferminorversion == DatapoolMinorVersion)&&(mbufferDIcountload == DIcount))
            {
                qCDebug(m_categrory) << "loadBuffer: should be the same";
            }
            else
            {
                qCDebug(m_categrory) << "loadBuffer: minorchange";
            }
            if((mbuffersizeload >=  bhcount +  (mbufferDIcountload*2))&&(sizeof(mBuffer) >=  bhcount +  (mbufferDIcountload*2)))
            {
                mBufferLoaded = true;
                for(unsigned int diindex = 0; (diindex < mbufferDIcountload) && (diindex < DIcount); diindex++)
                {
                    mPosDatapoolEntry[diindex] = static_cast<int>(mBuffer[bhcount+(diindex*2)+1] << 8) + mBuffer[bhcount+(diindex*2)];
                }
                qCDebug(m_categrory) << "loadBuffer: loadindexpos";
            }
        }
        else
        {
            qCDebug(m_categrory) << "loadBuffer: majorchange --> no data";
        }
    }
    else
    {
        qCDebug(m_categrory) << "loadBuffer: readbuffersize to small --> no data";
    }
}

void SaveDatapool::saveID(saveelement savedata)
{
    if(((savedata.datasize+mbufferindex+4) < sizeof(mBuffer))&&(savedata.id < DIcount))
    {
        mPosDatapoolEntry[savedata.id] = mbufferindex;
        mBuffer[mbufferindex + idlow] = static_cast<char>(savedata.id&0x00ff);
        mBuffer[mbufferindex + idhigh] = static_cast<char>((savedata.id&0xff00)>>8);
        mBuffer[mbufferindex + datasizelow] = static_cast<char>(savedata.datasize&0x00ff);
        mBuffer[mbufferindex + datasizehigh] = static_cast<char>((savedata.datasize&0xff00)>>8);
        mbufferindex = mbufferindex + bicount;
        if(((mbufferindex+savedata.datasize) < sizeof(mBuffer))&&(savedata.datasize > 0)&&(NULL != savedata.data))
        {
            memcpy(&mBuffer[mbufferindex],savedata.data,savedata.datasize);
            mbufferindex = mbufferindex+savedata.datasize;
        }
    }
    else
    {
        mBufferReadytoSave = false;
    }
}

void SaveDatapool::loadID(saveelement &loaddata)
{
    loaddata.datasize = 0;
    if((mbufferDIcountload > loaddata.id)&&(loaddata.id < DIcount)&&(true == mBufferLoaded))
    {
        unsigned int bufferindex = mPosDatapoolEntry[loaddata.id];
        if((bufferindex + bicount < sizeof(mBuffer))&&(bufferindex + bicount < mbuffersizeload))
        {
            unsigned int buffferid = static_cast<int>(mBuffer[bufferindex + idhigh] << 8) + mBuffer[bufferindex + idlow];
            if(buffferid == loaddata.id)
            {
                loaddata.datasize = static_cast<int>(mBuffer[bufferindex + datasizehigh] << 8) + mBuffer[bufferindex + datasizelow];
            }
            if((bufferindex + bicount + loaddata.datasize < sizeof(mBuffer))&&(bufferindex + bicount + loaddata.datasize < mbuffersizeload))
            {
                loaddata.data = &mBuffer[bufferindex + bicount];
                qCDebug(m_categrory) << "loadID: load data id: " << loaddata.id;
            }
            else
            {
                loaddata.datasize = 0;
            }
        }
    }
}
