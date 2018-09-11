#include "DatapoolTrigger.hpp"
#include "DatapoolControll.hpp"

static int mInstancecount = 1;

DatapoolTrigger::DatapoolTrigger() :
    mLogging("Datapool.DatapoolTrigger",false,false),
    minstanceID(mInstancecount)
{
    mInstancecount++;
}

DatapoolTrigger::~DatapoolTrigger()
{

}

void DatapoolTrigger::triggerbyDatapool(unsigned int id, int instance)
{
    mLogging << "triggerbyDatapool id: " << id << " instance: " <= instance;
    if(instance == minstanceID)
    {
        receiveDatapoolID(id);
    }
}


bool DatapoolTrigger::registerDatapoolTrigger(int datapoolid)
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
