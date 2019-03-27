#ifndef DATAPOOLCONTROLL_HPP
#define DATAPOOLCONTROLL_HPP

#include "DatapoolIndex.hpp"
#include "DatapoolDefinition.hpp"
#include "DatapoolElement.hpp"
#include "DatapoolTrigger.hpp"
#include "FileAccess/SaveDatapool.hpp"
#include "Utils/Logging.hpp"
#include <QMutex>
#include <stdint.h>

class DatapoolControll
{
public:
    DatapoolControll();
    ~DatapoolControll();

    static DatapoolControll *getInstance();

    void setElement(uint32_t id, sElementDatapool &data);
    void getElement(uint32_t id, sElementDatapool &element);

    void loadDatapool();
    void saveDatapool();

    void regTriggerInstance(DatapoolTrigger *pDatapoolTrigger, uint32_t instanceID);

private:
    DatapoolElement mDatapoolElement[DIcount];
    SaveDatapool mSaveDatapool;
    Logging mLogging;
};

#endif // DATAPOOLCONTROLL_HPP
