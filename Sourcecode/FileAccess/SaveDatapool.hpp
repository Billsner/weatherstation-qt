#ifndef SAVEDATAPOOL_HPP
#define SAVEDATAPOOL_HPP

#include <QString>
#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>
#include "Datapool/DatapoolIndex.hpp"

struct saveelement
{
    unsigned int id;
    char *data;
    int datasize;
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
    QLoggingCategory m_categrory;
    QString mfilename;
    QFile mfile;
    char mBuffer[8192];
    unsigned int mbufferindex;
    unsigned int mPosDatapoolEntry[DIcount];
    bool mNeedSaveAll;
    bool mBufferLoaded;
    bool mBufferReadytoSave;
    unsigned int mbuffersizeload;
    unsigned int mbufferDIcountload;
};

#endif // SAVEDATAPOOL_HPP
