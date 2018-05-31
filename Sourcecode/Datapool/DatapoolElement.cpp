#include "DatapoolElement.hpp"
#include <cstring>
#include <QMutexLocker>
#include "FileAccess/SaveDatapool.hpp"

static int MAXDATAPOOLDATASIZE = 100;

DatapoolElement::DatapoolElement() :
    mElementID(0xffffffff),
    mDatasize(0),
    mpdata(NULL),
    mReceiverChange(0x00000000),
    meElementState(ESInt),
    meElementAction(EANothing),
    m_categrory("Datapool.DatapoolElement")
{

}

DatapoolElement::~DatapoolElement()
{
    QMutexLocker Locker(&m_mutex);
    if(NULL != mpdata)
    {
        delete mpdata;
        mpdata = NULL;
        mDatasize = 0;
    }
}

void DatapoolElement::setElement(unsigned int id, sElementDatapool &data)
{
    QMutexLocker Locker(&m_mutex);
    data.DataState = ESError;
    if((NULL != data.data)
            &&(0 != data.datasize)
            &&((id == mElementID)||(0xffffffff == mElementID)))
    {
        mElementID = id;
        if((mDatasize != data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize)&&(NULL != data.data))
        {
            qCDebug(m_categrory) << "Create-Resize Element: " << mElementID;
            if(NULL != mpdata)
            {
                delete mpdata;
                mpdata = NULL;
            }
            mpdata = new char[data.datasize];
            if(NULL != mpdata)
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
        else if((mDatasize == data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize)&&(NULL != mpdata)&&(NULL != data.data))
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

void DatapoolElement::setElementAction(unsigned int id, eElementAction elementaction, bool &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = false;
    if((id == mElementID)||(0xffffffff == mElementID))
    {
        mElementID = id;
        meElementAction = elementaction;
    }
}

void DatapoolElement::getElement(unsigned int id, sElementDatapool &element)
{
    QMutexLocker Locker(&m_mutex);
    element.DataState = ESError;
    element.id = mElementID;
    if(id == mElementID)
    {
        element.DateAction = meElementAction;
        element.DataState = meElementState;
        if((0 != mDatasize) && (NULL != mpdata) && (MAXDATAPOOLDATASIZE > mDatasize))
        {
            element.datasize = mDatasize;
            if(NULL != element.data)
            {
                delete element.data;
                element.data = NULL;
            }
            element.data = new char[element.datasize];
            if(NULL != element.data)
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

void DatapoolElement::getElementState(unsigned int id, eElementState &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = ESError;
    if(id == mElementID)
    {
        ret = meElementState;
    }
}

void DatapoolElement::getElementAction(unsigned int id, eElementAction &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = EANothing;
    if(id == mElementID)
    {
        ret = meElementAction;
    }
}

void DatapoolElement::isElementReceiverChangeValid(unsigned int id, unsigned int receiver, bool &ret)
{
    QMutexLocker Locker(&m_mutex);
    ret = false;
    if(((mReceiverChange & receiver) == receiver)&&(id == mElementID))
    {
        ret = true;
        mReceiverChange = (mReceiverChange & !receiver);
    }
}

void DatapoolElement::loadElement(unsigned int id)
{
    QMutexLocker Locker(&m_mutex);
    if((id == mElementID)||(0xffffffff == mElementID))
    {
        mElementID = id;
        if(ESInt == meElementState)
        {
            SaveDatapool *pSaveDatapool = SaveDatapool::getInstance();
            if(NULL != pSaveDatapool)
            {

                saveelement loadedata;
                loadedata.id = mElementID;
                loadedata.data = NULL;
                loadedata.datasize = 0;
                pSaveDatapool->loadID(loadedata);
                if((NULL != loadedata.data)&&(0 < loadedata.datasize)&&(MAXDATAPOOLDATASIZE > loadedata.datasize))
                {
                    if(NULL != mpdata)
                    {
                        delete mpdata;
                        mpdata = NULL;
                    }
                    mpdata = new char[loadedata.datasize];
                    if(NULL != mpdata)
                    {
                        memcpy(mpdata,loadedata.data,loadedata.datasize);
                        mDatasize = loadedata.datasize;
                        meElementState = ESValidLoad;;
                        mReceiverChange = 0xffffffff;
                        qCDebug(m_categrory) << "loadElement Element: " << mElementID;
                    }
                }
            }
        }
    }    
}

void DatapoolElement::saveElement(unsigned int id)
{    
    QMutexLocker Locker(&m_mutex);
    if(id == mElementID)
    {
        SaveDatapool *pSaveDatapool = SaveDatapool::getInstance();
        if(NULL != pSaveDatapool)
        {            
            if((ESValidChanged == meElementState)||(pSaveDatapool->needSaveAll()))
            {
                saveelement saveedata;
                saveedata.id = mElementID;
                saveedata.datasize = mDatasize;
                saveedata.data = mpdata;
                pSaveDatapool->saveID(saveedata);
                meElementState = ESValidSaved;
                qCDebug(m_categrory) << "saveElement Element: " << mElementID;
            }
        }
    }
}
