#ifndef DATAPOOLCONTROLL_HPP
#define DATAPOOLCONTROLL_HPP

#include "DatapoolIndex.hpp"
#include "DatapoolDefinition.hpp"
#include "DatapoolElement.hpp"
#include "DatapoolTrigger.hpp"
#include "FileAccess/SaveDatapool.hpp"
#include "Utils/Logging.hpp"
#include <QMutex>

class DatapoolControll
{
public:
    DatapoolControll();
    ~DatapoolControll();

    static DatapoolControll *getInstance();

    void setElement(unsigned int id, sElementDatapool &data);
    void getElement(unsigned int id, sElementDatapool &element);

    void loadDatapool();
    void saveDatapool();

    void regTriggerInstance(DatapoolTrigger *pDatapoolTrigger, int instanceID);

private:
    DatapoolElement mDatapoolElement[DIcount];
    SaveDatapool mSaveDatapool;
    Logging mLogging;
};

#endif // DATAPOOLCONTROLL_HPP
