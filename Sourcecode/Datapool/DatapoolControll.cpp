#include "DatapoolControll.hpp"
#include <QMutexLocker>

static DatapoolControll *mpDatapoolControll = NULL;

DatapoolControll::DatapoolControll() : m_categrory("Datapool.DatapoolControll")
{
    mpDatapoolControll = this;
}

DatapoolControll::~DatapoolControll()
{
    mpDatapoolControll = NULL; //ToDo: Maybe Problem
}

DatapoolControll *DatapoolControll::getInstance()
{
    return mpDatapoolControll;
}

void DatapoolControll::setElement(unsigned int id, sElementDatapool &data)
{    
    if(id < DIcount)
    {
        mDatapoolElement[id].setElement(id,data);
    }
}

void DatapoolControll::getElement(unsigned int id, sElementDatapool &element)
{
    if(id < DIcount)
    {
        mDatapoolElement[id].getElement(id,element);
    }
}

void DatapoolControll::loadDatapool()
{
    mSaveDatapool.openFile();
    mSaveDatapool.readHeader();
    int test = 0;
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].loadElement(count);
        mSaveDatapool.loadLine(count,NULL,test);
    }
    mSaveDatapool.closeFile();
}

void DatapoolControll::saveDatapool()
{
    mSaveDatapool.openFile();
    mSaveDatapool.setHeader();
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].saveElement(count);
        mSaveDatapool.saveLine(count,NULL,0);
    }
    mSaveDatapool.closeFile();
    loadDatapool();
}
