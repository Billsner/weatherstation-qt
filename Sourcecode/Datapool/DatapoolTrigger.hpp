#ifndef DATAPOOLTRIGGER_HPP
#define DATAPOOLTRIGGER_HPP

#include "Utils/Logging.hpp"
#include <stdint.h>

class DatapoolTrigger
{
public:
    DatapoolTrigger();
    virtual ~DatapoolTrigger();

    void triggerbyDatapool(uint32_t id, uint32_t instance);
    bool registerDatapoolTrigger(uint32_t datapoolid);

    virtual void receiveDatapoolID(uint32_t id) = 0;



private:
    Logging mLogging;
    uint32_t minstanceID;

};

#endif // DATAPOOLTRIGGER_HPP
