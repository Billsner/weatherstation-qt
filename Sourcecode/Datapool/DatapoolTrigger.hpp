#ifndef DATAPOOLTRIGGER_HPP
#define DATAPOOLTRIGGER_HPP

#include "Utils/Logging.hpp"

class DatapoolTrigger
{
public:
    DatapoolTrigger();
    virtual ~DatapoolTrigger();

    void triggerbyDatapool(unsigned int id, int instance);
    bool registerDatapoolTrigger(int datapoolid);

    virtual void receiveDatapoolID(unsigned int id) = 0;



private:
    Logging mLogging;
    int minstanceID;

};

#endif // DATAPOOLTRIGGER_HPP
