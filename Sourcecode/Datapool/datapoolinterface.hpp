#ifndef DATAPOOLINTERFACE_HPP
#define DATAPOOLINTERFACE_HPP

#include "datapoolindex.hpp"
#include "datapooldefinition.hpp"
#include "datapoolcontroll.hpp"
#include "Utils/logging.hpp"

#include <QString>


class DatapoolInterface
{
public:
    DatapoolInterface();
    ~DatapoolInterface();

    bool connectDatapool();

    bool setDatapoolInt(uint32_t id, int32_t value);
    bool getDatapoolInt(uint32_t id, int32_t &value);

    bool setDatapoolQString(uint32_t id, QString &value);
    bool getDatapoolQString(uint32_t id, QString &value);

private:
    void createDataArray(uint32_t size);
    bool serializeInt(int32_t value, uint8_t *data, uint32_t datasize);
    bool deserializeInt(int32_t &value, uint8_t *data, uint32_t datasize);

    DatapoolControll *mpDatapoolControll;
    sElementDatapool msElementDatapool;
    Logging mLogging;
};

#endif // DATAPOOLINTERFACE_HPP
