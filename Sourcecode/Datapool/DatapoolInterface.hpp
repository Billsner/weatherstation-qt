#ifndef DATAPOOLINTERFACE_HPP
#define DATAPOOLINTERFACE_HPP

#include "DatapoolIndex.hpp"
#include "DatapoolDefinition.hpp"
#include "DatapoolControll.hpp"

#include <QString>

class DatapoolInterface
{
public:
    DatapoolInterface();
    ~DatapoolInterface();

    bool connectDatapool();

    bool setDatapoolInt(unsigned int id, int value);
    bool getDatapoolInt(unsigned int id, int &value);

    bool setDatapoolString(unsigned int id, QString value);
    bool getDatapoolString(unsigned int id, QString &value);

private:
    DatapoolControll *mpDatapoolControll;
    sElementDatapool msElementDatapool;
};

#endif // DATAPOOLINTERFACE_HPP
