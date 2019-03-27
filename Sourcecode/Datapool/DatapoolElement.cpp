#include "DatapoolElement.hpp"
#include <cstring>
#include <QMutexLocker>
#include "FileAccess/SaveDatapool.hpp"

static uint32_t MAXDATAPOOLDATASIZE = 100;

DatapoolElement::DatapoolElement() :
    mElementID(0xffffffff),
    mDatasize(0),
    mpdata(nullptr),
    mReceiverChange(0x00000000),
    meElementState(ESInt),
    meElementAction(EANothing),
    mLogging("Datapool.DatapoolElement")
{

}

DatapoolElement::~DatapoolElement()
{
    QMutexLocker Locker(&m_mutex);
    if(nullptr != mpdata)
    {
        delete mpdata;
        mpdata = nullptr;
        mDatasize = 0;
    }
}

void DatapoolElement::setElement(uint32_t id, sElementDatapool &data)
{
    QMutexLocker Locker(&m_mutex);
    data.DataState = ESError;
    if((nullptr != data.data)
            &&(0 != data.datasize)
            &&((id == mElementID)||(0xffffffff == mElementID)))
    {
        mElementID = id;
        if((mDatasize != data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize)&&(nullptr != data.data))
        {
            mLogging << "Create-Resize Element: " <= mElementID;
            if(nullptr != mpdata)
            {
                delete mpdata;
                mpdata = nullptr;
            }
            mpdata = new uint8_t [data.datasize];
            if(nullptr != mpdata)
            {
                memcpy(mpdata,data.data,data.datasize);
                mDatasize = data.datasize;
                data.DataState = meElementState = ESValidChanged;
                mReceiverChange = 0xffffffff;
            }
            else
            {
                 data.DataState = ESError;
            }

        }
        else if((mDatasize == data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize)&&(nullptr != mpdata)&&(nullptr != data.data))
        {
            if(0 != memcmp(mpdata,data.data,mDatasize))
            {
                memcpy(mpdata,data.data,data.datasize);
                data.DataState = meElementState = ESValidChanged;
                mReceiverChange = 0xffffffff;
            }
            else
            {
                data.DataState = ESNothing;
            }
        }
        else
        {
            data.DataState = ESError;
        }

    }
}

void DatapoolElement::setElementAction(uint32_t id, eElementAction elementaction, bool &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = false;
    if((id == mElementID)||(0xffffffff == mElementID))
    {
        mElementID = id;
        meElementAction = elementaction;
    }
}

void DatapoolElement::getElement(uint32_t id, sElementDatapool &element)
{
    QMutexLocker Locker(&m_mutex);
    element.DataState = ESError;
    element.id = mElementID;
    if(id == mElementID)
    {
        element.DateAction = meElementAction;
        element.DataState = meElementState;
        if((0 != mDatasize) && (nullptr != mpdata) && (MAXDATAPOOLDATASIZE > mDatasize))
        {
            element.datasize = mDatasize;
            if(nullptr != element.data)
            {
                delete element.data;
                element.data = nullptr;
            }
            element.data = new uint8_t [element.datasize];
            if(nullptr != element.data)
            {
                memcpy(element.data,mpdata,element.datasize);                
            }
            else
            {
                element.DataState = ESError;
            }
        }
        else
        {
            element.datasize = 0;
            if(ESInt != element.DataState)
            {
                element.DataState = ESError;
            }
        }
    }
}

void DatapoolElement::getElementState(uint32_t id, eElementState &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = ESError;
    if(id == mElementID)
    {
        ret = meElementState;
    }
}

void DatapoolElement::getElementAction(uint32_t id, eElementAction &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = EANothing;
    if(id == mElementID)
    {
        ret = meElementAction;
    }
}

void DatapoolElement::isElementReceiverChangeValid(uint32_t id, uint32_t receiver, bool &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = false;
    if(((mReceiverChange & receiver) == receiver)&&(id == mElementID))
    {
        ret = true;
        mReceiverChange = (mReceiverChange & !receiver);
    }
}

void DatapoolElement::loadElement(uint32_t id)
{
    QMutexLocker Locker(&m_mutex);
    if((id == mElementID)||(0xffffffff == mElementID))
    {
        mElementID = id;
        if(ESInt == meElementState)
        {
            SaveDatapool *pSaveDatapool = SaveDatapool::getInstance();
            if(nullptr != pSaveDatapool)
            {

                saveelement loadedata;
                loadedata.id = mElementID;
                loadedata.data = nullptr;
                loadedata.datasize = 0;
                pSaveDatapool->loadID(loadedata);
                if((nullptr != loadedata.data)&&(0 < loadedata.datasize)&&(MAXDATAPOOLDATASIZE > loadedata.datasize))
                {
                    if(nullptr != mpdata)
                    {
                        delete mpdata;
                        mpdata = nullptr;
                    }
                    mpdata = new uint8_t [loadedata.datasize];
                    if(nullptr != mpdata)
                    {
                        memcpy(mpdata,loadedata.data,loadedata.datasize);
                        mDatasize = loadedata.datasize;
                        meElementState = ESValidLoad;;
                        mReceiverChange = 0xffffffff;
                        mLogging << "loadElement Element: " <= mElementID;
                    }
                }
                else
                {
                    mLogging << "loadElement Element: " << mElementID << " Errordata size: " << loadedata.datasize << " data: " <= loadedata.data;
                }
            }
            else
            {
                mLogging << "loadElement Element: " << mElementID <= " Error pSaveDatapool";
            }
        }
        else
        {
            mLogging << "loadElement Element: " << mElementID <= " Error Element exist";
        }
    }    
}

void DatapoolElement::saveElement(uint32_t id)
{    
    QMutexLocker Locker(&m_mutex);
    if(id == mElementID)
    {
        SaveDatapool *pSaveDatapool = SaveDatapool::getInstance();
        if(nullptr != pSaveDatapool)
        {            
            if((ESValidChanged == meElementState)||(pSaveDatapool->needSaveAll()))
            {
                saveelement saveedata;
                saveedata.id = mElementID;
                saveedata.datasize = mDatasize;
                saveedata.data = mpdata;
                pSaveDatapool->saveID(saveedata);
                meElementState = ESValidSaved;
                mLogging << "saveElement Element: " <= mElementID;
            }
        }
    }
}
