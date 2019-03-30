#include "datapoolinterface.hpp"

DatapoolInterface::DatapoolInterface() :
    mpDatapoolControll(nullptr),
    mLogging("Datapool.DatapoolInterface")
{
    msElementDatapool.DataState = ESInt;
    msElementDatapool.datasize = 0;
    msElementDatapool.data = nullptr;
    connectDatapool();
}

DatapoolInterface::~DatapoolInterface()
{

}

bool DatapoolInterface::connectDatapool()
{
    bool ret = false;
    mpDatapoolControll = DatapoolControll::getInstance();
    if(nullptr != mpDatapoolControll)
    {
        ret = true;
    }
    else
    {
        mLogging << LLcritical <= "connectDatapool: No Connection";
    }
    return ret;
}

bool DatapoolInterface::setDatapoolInt(uint32_t id, int32_t value)
{
    mLogging << "setDatapoolInt ";
    bool ret = false;
    if(nullptr != mpDatapoolControll)
    {
        msElementDatapool.id = id;
        msElementDatapool.datasize = sizeof(value);
        createDataArray(msElementDatapool.datasize);
        if(nullptr != msElementDatapool.data)
        {
            if(serializeInt(value,msElementDatapool.data,msElementDatapool.datasize) == true)
            {
                mpDatapoolControll->setElement(id,msElementDatapool);
                ret = true;
            }
        }
    }
    else
    {
        mLogging << LLcritical <= "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::getDatapoolInt(uint32_t id, int32_t &value)
{
    mLogging <= "getDatapoolInt";
    bool ret = false;
    value = 0;
    if(nullptr != mpDatapoolControll)
    {
        mpDatapoolControll->getElement(id,msElementDatapool);
        if((ESError != msElementDatapool.DataState)&&(NULL != msElementDatapool.data)&&(0 < msElementDatapool.datasize))
        {
            if(deserializeInt(value,msElementDatapool.data,msElementDatapool.datasize) == true)
            {
                ret = true;
            }
        }
    }
    else
    {
        mLogging << LLcritical <= "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::setDatapoolQString(uint32_t id, QString &value)
{
    bool ret = false;
    if(nullptr != mpDatapoolControll)
    {
        if((nullptr != msElementDatapool.data)&&(0 != msElementDatapool.datasize))
        {
            //Delete old array
            delete msElementDatapool.data;
            msElementDatapool.data = nullptr;
            mLogging <= "setDatapoolQString: delete old array";
        }
        msElementDatapool.id = id;
        msElementDatapool.datasize = value.toStdString().size() + 1;
        msElementDatapool.data = reinterpret_cast<uint8_t *>(const_cast<char*>(value.toStdString().c_str()));
        mpDatapoolControll->setElement(id,msElementDatapool);
        //Set to 0 because only use pointer and no reserved memory to reduse copy of data
        msElementDatapool.datasize = 0;
        msElementDatapool.data = nullptr;
        ret = true;
    }
    else
    {
        mLogging << LLcritical <= "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

bool DatapoolInterface::getDatapoolQString(uint32_t id, QString &value)
{
    bool ret = false;
    if(nullptr != mpDatapoolControll)
    {
        mpDatapoolControll->getElement(id,msElementDatapool);
        const std::string svalue(reinterpret_cast<char*>(msElementDatapool.data),msElementDatapool.datasize);
        value = QString::fromStdString(svalue);
        ret = true;
    }
    else
    {
        mLogging << LLcritical <= "setDatapoolInt: Try Reconnect";
        connectDatapool();
    }
    return ret;
}

void DatapoolInterface::createDataArray(uint32_t size)
{
    if((nullptr != msElementDatapool.data)&&(size != msElementDatapool.datasize))
    {
        //Delete old array
        delete msElementDatapool.data;
        msElementDatapool.data = nullptr;
        mLogging <= "createDataArray: delete old array";
    }
    if(nullptr == msElementDatapool.data)
    {
        msElementDatapool.data = new uint8_t[size];
        msElementDatapool.datasize = size;
        mLogging << "createDataArray: create new Array Size: " <= size;
    }
}

bool DatapoolInterface::serializeInt(int32_t value, uint8_t *data, uint32_t datasize)
{
    bool ret = false;
    if((datasize == sizeof(value))&&(nullptr != data)&&(datasize == 4))
    {
        data[0] = static_cast<uint8_t>((0xff000000 & value) >> 24);
        data[1] = static_cast<uint8_t>((0x00ff0000 & value) >> 16);
        data[2] = static_cast<uint8_t>((0x0000ff00 & value) >> 0);
        data[3] = static_cast<uint8_t>((0x000000ff & value));
        mLogging << "serializeInt: data[0]: " << static_cast<int>(data[0])
                << " data[1]: " << static_cast<int>(data[1])
                << " data[2]: " << static_cast<int>(data[2])
                << " data[3]: " << static_cast<int>(data[3])
                << " value: " <= value;
        ret = true;
    }
    else
    {
        mLogging << LLcritical <= "serializeInt: Error";
    }
    return ret;
}

bool DatapoolInterface::deserializeInt(int32_t &value, uint8_t *data, uint32_t datasize)
{
    bool ret = false;
    value = 0;
    if((datasize == sizeof(value))&&(nullptr != data)&&(datasize == 4))
    {
        value = data[3] + (data[2] << 8) + (data[1] << 16) + (data[0] << 24);
        mLogging << "deserializeInt: data[0]: " << static_cast<int>(data[0])
                             << " data[1]: " << static_cast<int>(data[1])
                             << " data[2]: " << static_cast<int>(data[2])
                             << " data[3]: " << static_cast<int>(data[3])
                             << " value: " <= value;
        ret = true;
    }
    else
    {
        mLogging << LLcritical <= "deserializeInt: Error";
    }
    return ret;
}
