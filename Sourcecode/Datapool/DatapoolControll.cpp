#include "DatapoolControll.hpp"
#include <QMutexLocker>

static DatapoolControll *mpDatapoolControll = NULL;

DatapoolControll::DatapoolControll() : m_categrory("Datapool.DatapoolControll")
{
    mpDatapoolControll = this;
}

DatapoolControll::~DatapoolControll()
{
    mpDatapoolControll = NULL; //ToDo: Maybe Problem
}

DatapoolControll *DatapoolControll::getInstance()
{
    return mpDatapoolControll;
}

void DatapoolControll::setElement(unsigned int id, sElementDatapool &data)
{
    QMutexLocker Locker(&m_mutex);
    if(id < DIcount)
    {
        mDatapoolElement[id].setElement(id,data);
    }
}

void DatapoolControll::getElement(unsigned int id, sElementDatapool &element)
{
    QMutexLocker Locker(&m_mutex);
    if(id < DIcount)
    {
        mDatapoolElement[id].getElement(id,element);
    }
}

void DatapoolControll::loadDatapool()
{
    QMutexLocker Locker(&m_mutex);
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].loadElement(count);
    }
}

void DatapoolControll::saveDatapool()
{
    QMutexLocker Locker(&m_mutex);
    for(int count = 0; count < DIcount; count++)
    {
        mDatapoolElement[count].saveElement(count);
    }
}
