#include "DatapoolInterface.hpp"

DatapoolInterface::DatapoolInterface() : mpDatapoolControll(NULL)
{
    connectDatapool();
}

DatapoolInterface::~DatapoolInterface()
{

}

bool DatapoolInterface::connectDatapool()
{
    bool ret = false;
    mpDatapoolControll = DatapoolControll::getInstance();
    if(NULL != mpDatapoolControll)
    {
        ret = true;
    }
    return ret;
}

bool DatapoolInterface::setDatapoolInt(unsigned int id, int value)
{
    bool ret = false;
    return ret;
}

bool DatapoolInterface::getDatapoolInt(unsigned int id, int &value)
{
    bool ret = false;
    return ret;
}

bool DatapoolInterface::setDatapoolString(unsigned int id, QString value)
{
    bool ret = false;
    return ret;
}

bool DatapoolInterface::getDatapoolString(unsigned int id, QString &value)
{
    bool ret = false;
    return ret;
}
