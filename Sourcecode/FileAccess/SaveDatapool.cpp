#include "SaveDatapool.hpp"
#include <QFile>
#include <QTextStream>

static SaveDatapool *mpSaveDatapool = nullptr;

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

static const uint32_t DatapoolMajorVersion = 2; //change as incompatible if datapoolid is add at start or in the middle
static const uint32_t DatapoolMinorVersion = 1; //change as compatible if datapoolid is add at the end


SaveDatapool::SaveDatapool() :
    mLogging("fileaccess.SaveDatapool"),
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
    mpSaveDatapool = nullptr;
}

SaveDatapool *SaveDatapool::getInstance()
{
    return mpSaveDatapool;
}

void SaveDatapool::openFile()
{
    if(true == mfile.open(QIODevice::ReadWrite))
    {
        mLogging <= "openFile: successful";
    }
    else
    {
        mLogging <= "openFile: error";
    }
}

void SaveDatapool::closeFile()
{
    mfile.close();
    mLogging <= "closeFile";
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
        mLogging <= "prepareBuffer";
    }
}

void SaveDatapool::closeBuffer()
{
    uint32_t index = bhcount;
    if((index+(DIcount*2)) < sizeof(mBuffer))
    {
        for(uint32_t diindex = 0; diindex < DIcount; diindex++)
        {
            mBuffer[index] = static_cast<char>(mPosDatapoolEntry[diindex]&0x00ff);
            index++;
            mBuffer[index] = static_cast<char>((mPosDatapoolEntry[diindex]&0xff00)>>8);
            index++;
        }
    }
    if((true == mBufferReadytoSave)&&(mbufferindex < sizeof(mBuffer)))
    {
        //printBUffer();
        QDataStream write(&mfile);
        write.writeRawData(reinterpret_cast<char*>(mBuffer),static_cast<int>(mbufferindex));
        mLogging <= "closeBuffer: write";
    }
}

void SaveDatapool::loadBuffer()
{
    QDataStream read(&mfile);
    mbuffersizeload = static_cast<uint32_t>(read.readRawData(reinterpret_cast<char*>(mBuffer),sizeof(mBuffer)));
    //printBUffer();
    if((bhcount <= mbuffersizeload)&&(bhcount <= sizeof(mBuffer)))
    {
        uint32_t buffermajorversion = static_cast<uint32_t>(mBuffer[bmajorhigh] << 8) + mBuffer[bmajorlow];
        uint32_t bufferminorversion = static_cast<uint32_t>(mBuffer[bminorhigh] << 8) + mBuffer[bminorlow];
        mbufferDIcountload = static_cast<uint32_t>(mBuffer[bdiindexhigh] << 8) + mBuffer[bdiindexlow];
        if(buffermajorversion == DatapoolMajorVersion)
        {
            if((bufferminorversion == DatapoolMinorVersion)&&(mbufferDIcountload == DIcount))
            {
                mLogging <= "loadBuffer: should be the same";
            }
            else
            {
                mLogging << "loadBuffer: minorchange bufferminorversion: " << bufferminorversion
                         << " DatapoolMinorVersion: " << DatapoolMinorVersion
                         << " mbufferDIcountload: " << mbufferDIcountload
                         << " DIcount " <= DIcount;
            }
            if((mbuffersizeload >=  bhcount +  (mbufferDIcountload*2))&&(sizeof(mBuffer) >=  bhcount +  (mbufferDIcountload*2)))
            {
                mBufferLoaded = true;
                for(uint32_t diindex = 0; (diindex < mbufferDIcountload) && (diindex < DIcount); diindex++)
                {
                    mPosDatapoolEntry[diindex] = static_cast<uint32_t>(mBuffer[bhcount+(diindex*2)+1] << 8) + mBuffer[bhcount+(diindex*2)];
                    mLogging << "loadBuffer: mPosDatapoolEntry[diindex]: " << mPosDatapoolEntry[diindex] << " diindex: " <= diindex;
                }
                mLogging <= "loadBuffer: loadindexpos";
            }
        }
        else
        {
            mLogging << LLwarning <= "loadBuffer: majorchange --> no data";
        }
    }
    else
    {
        mLogging << LLwarning <= "loadBuffer: readbuffersize to small --> no data";
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
        if(((mbufferindex+savedata.datasize) < sizeof(mBuffer))&&(savedata.datasize > 0)&&(nullptr != savedata.data))
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
        uint32_t bufferindex = mPosDatapoolEntry[loaddata.id];
        if((bufferindex + bicount < sizeof(mBuffer))&&(bufferindex + bicount < mbuffersizeload))
        {
            uint32_t buffferid = static_cast<uint32_t>(mBuffer[bufferindex + idhigh] << 8) + mBuffer[bufferindex + idlow];
            if(buffferid == loaddata.id)
            {
                loaddata.datasize = static_cast<uint32_t>(mBuffer[bufferindex + datasizehigh] << 8) + mBuffer[bufferindex + datasizelow];
            }
            else
            {
                mLogging << "loadID: error id: " << loaddata.id  << " bufferid " <= buffferid;
            }
            if((bufferindex + bicount + loaddata.datasize < sizeof(mBuffer))&&(bufferindex + bicount + loaddata.datasize < mbuffersizeload))
            {
                loaddata.data = &mBuffer[bufferindex + bicount];
                mLogging << "loadID: load data id: " <= loaddata.id;
            }
            else
            {
                loaddata.datasize = 0;
                mLogging << "loadID: load data 0 id: " <= loaddata.id;
            }
        }
    }
}

void SaveDatapool::printBUffer()
{
    mLogging << " sizeof(mBuffer): " <= sizeof(mBuffer);
    mLogging <= " sizeof(mBuffer): All";
    for(int i = 0; i < 50; i++)
    {
        mLogging << " index: " << i << " Data: " <= static_cast<int>(mBuffer[i]);
    }

}
