#include "DatapoolControll.hpp"
#include <QMutexLocker>

static DatapoolControll *mpDatapoolControll = NULL;

DatapoolControll::DatapoolControll() :
    mLogging("Datapool.DatapoolControll",true,false)
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
        mLogging << "setElement ID: " << id << " data.DataState: " <= data.DataState;
    }
}

void DatapoolControll::getElement(unsigned int id, sElementDatapool &element)
{
    if(id < DIcount)
    {        
        mDatapoolElement[id].getElement(id,element);
        mLogging << "getElement ID: " << id << " element.DataState: " <= element.DataState;
    }
}

void DatapoolControll::loadDatapool()
{
    mLogging << "loadDatapool count: " <= DIcount;
    mSaveDatapool.openFile();
    mSaveDatapool.loadBuffer();
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].loadElement(count);       
    }
    mSaveDatapool.closeFile();
}

void DatapoolControll::saveDatapool()
{
    mLogging << "saveDatapool count: " <= DIcount;
    mSaveDatapool.openFile();
    mSaveDatapool.prepareBuffer();
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].saveElement(count);        
    }
    mSaveDatapool.closeBuffer();
    mSaveDatapool.closeFile();
}

void DatapoolControll::regTriggerInstance(DatapoolTrigger *pDatapoolTrigger, int instanceID)
{
    mLogging << "regTriggerInstance instanceID: " <= instanceID;
}
