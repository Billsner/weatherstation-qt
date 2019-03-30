#ifndef SAVEDATAPOOL_HPP
#define SAVEDATAPOOL_HPP

#include <QString>
#include <QFile>
#include <QDataStream>
#include "Utils/logging.hpp"
#include "Datapool/datapoolindex.hpp"
#include <stdint.h>

struct saveelement
{
    uint32_t id;
    uint8_t *data;
    uint32_t datasize;
};

class SaveDatapool
{
public:
    SaveDatapool();
    ~SaveDatapool();

    static SaveDatapool *getInstance();

    void openFile();
    void closeFile();

    bool needSaveAll() {return mNeedSaveAll;}

    void prepareBuffer();
    void closeBuffer();
    void loadBuffer();

    void saveID(saveelement savedata);
    void loadID(saveelement &loaddata);


private:
    void printBUffer();

    Logging mLogging;
    QString mfilename;
    QFile mfile;
    uint8_t mBuffer[8192];
    uint32_t mbufferindex;
    uint32_t mPosDatapoolEntry[DIcount];
    bool mNeedSaveAll;
    bool mBufferLoaded;
    bool mBufferReadytoSave;
    uint32_t mbuffersizeload;
    uint32_t mbufferDIcountload;
};

#endif // SAVEDATAPOOL_HPP
