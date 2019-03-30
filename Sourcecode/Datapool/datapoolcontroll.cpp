#include "datapoolcontroll.hpp"
#include <QMutexLocker>

static DatapoolControll *mpDatapoolControll = nullptr;

DatapoolControll::DatapoolControll() :
    mLogging("Datapool.DatapoolControll")
{
    mpDatapoolControll = this;
}

DatapoolControll::~DatapoolControll()
{
    mpDatapoolControll = nullptr; //ToDo: Maybe Problem
}

DatapoolControll *DatapoolControll::getInstance()
{
    return mpDatapoolControll;
}

void DatapoolControll::setElement(uint32_t id, sElementDatapool &data)
{    
    if(id < DIcount)
    {
        mDatapoolElement[id].setElement(id,data);
        mLogging << "setElement ID: " << id << " data.DataState: " <= data.DataState;
    }
}

void DatapoolControll::getElement(uint32_t id, sElementDatapool &element)
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
    for(uint32_t count = 0; count < DIcount; count++)
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
    for(uint32_t count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].saveElement(count);        
    }
    mSaveDatapool.closeBuffer();
    mSaveDatapool.closeFile();
}

void DatapoolControll::regTriggerInstance(DatapoolTrigger *pDatapoolTrigger, uint32_t instanceID)
{
    if(pDatapoolTrigger == nullptr)
    {
        mLogging << "regTriggerInstance instanceID: " <= instanceID;
    }
}
