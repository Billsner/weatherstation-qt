#include "DatapoolInterface.hpp"

DatapoolInterface::DatapoolInterface() :
    mpDatapoolControll(NULL),
    m_categrory("Datapool.DatapoolInterface")
{
    msElementDatapool.datasize = 0;
    msElementDatapool.data = NULL;
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
    else
    {
        qCCritical(m_categrory) << "connectDatapool: No Connection";
    }
    return ret;
}

bool DatapoolInterface::setDatapoolInt(unsigned int id, int value)
{
    bool ret = false;
    if(NULL != mpDatapoolControll)
    {
        msElementDatapool.id = id;
        msElementDatapool.datasize = sizeof(value);
        createDataArray(2);
        if(NULL != msElementDatapool.data)
        {

        }

        ret = true;

    }
    else
    {
        qCDebug(m_categrory) << "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::getDatapoolInt(unsigned int id, int &value)
{
    bool ret = false;
    if(NULL != mpDatapoolControll)
    {

        ret = true;

    }
    else
    {
        qCDebug(m_categrory) << "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::setDatapoolString(unsigned int id, QString value)
{
    bool ret = false;
    if(NULL != mpDatapoolControll)
    {

        ret = true;

    }
    else
    {
        qCDebug(m_categrory) << "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::getDatapoolString(unsigned int id, QString &value)
{
    bool ret = false;
    if(NULL != mpDatapoolControll)
    {

        ret = true;

    }
    else
    {
        qCDebug(m_categrory) << "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

void DatapoolInterface::createDataArray(int size)
{
    if(NULL != msElementDatapool.data)
    {
        //Delete old array
        delete msElementDatapool.data;
        msElementDatapool.data = NULL;
        qCDebug(m_categrory) << "createDataArray: delete old array";
    }
    if(NULL == msElementDatapool.data)
    {
        msElementDatapool.data = new char[size];
        msElementDatapool.datasize = size;
        qCDebug(m_categrory) << "createDataArray: create new Array Size: " << size;
    }
}
