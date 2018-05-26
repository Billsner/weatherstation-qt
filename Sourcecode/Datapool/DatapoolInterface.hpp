#ifndef DATAPOOLINTERFACE_HPP
#define DATAPOOLINTERFACE_HPP

#include "DatapoolIndex.hpp"
#include "DatapoolDefinition.hpp"
#include "DatapoolControll.hpp"

#include <QString>
#include <QLoggingCategory>

class DatapoolInterface
{
public:
    DatapoolInterface();
    ~DatapoolInterface();

    bool connectDatapool();

    bool setDatapoolInt(unsigned int id, int value);
    bool getDatapoolInt(unsigned int id, int &value);

    bool setDatapoolQString(unsigned int id, QString &value);
    bool getDatapoolQString(unsigned int id, QString &value);

private:
    void createDataArray(int size);
    bool serializeInt(int value, char *data, int datasize);
    bool deserializeInt(int &value, char *data, int datasize);

    DatapoolControll *mpDatapoolControll;
    sElementDatapool msElementDatapool;
    QLoggingCategory m_categrory;
};

#endif // DATAPOOLINTERFACE_HPP