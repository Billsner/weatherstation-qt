#include "DatapoolTrigger.hpp"
#include "DatapoolControll.hpp"

static uint32_t mInstancecount = 1;

DatapoolTrigger::DatapoolTrigger() :
    mLogging("Datapool.DatapoolTrigger"),
    minstanceID(mInstancecount)
{
    mInstancecount++;
}

DatapoolTrigger::~DatapoolTrigger()
{

}

void DatapoolTrigger::triggerbyDatapool(uint32_t id, uint32_t instance)
{
    mLogging << "triggerbyDatapool id: " << id << " instance: " <= instance;
    if(instance == minstanceID)
    {
        receiveDatapoolID(id);
    }
}


bool DatapoolTrigger::registerDatapoolTrigger(uint32_t datapoolid)
{
    mLogging << "registerDatapoolTrigger datapoolid: " <= datapoolid;
    bool ret = false;
    DatapoolControll *pDatapoolControll = DatapoolControll::getInstance();
    if(NULL != pDatapoolControll)
    {
        pDatapoolControll->regTriggerInstance(this,minstanceID);
        ret = true;
    }
    return ret;
}
