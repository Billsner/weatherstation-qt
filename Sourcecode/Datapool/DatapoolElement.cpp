#include "DatapoolElement.hpp"
#include <cstring>

DatapoolElement::DatapoolElement() :
    mElementID(0xffffffff),
    mDatasize(0),
    mpdata(NULL),
    mReceiverChange(0x00000000),
    meElementState(ESInt),
    meElementAction(EANothing),
    m_categrory("DatapoolElement")
{

}

DatapoolElement::~DatapoolElement()
{
    if(NULL != mpdata)
    {
        delete mpdata;
        mpdata = NULL;
        mDatasize = 0;
    }
}

eElementState DatapoolElement::setElement(unsigned int id, sElementDatapool &data)
{
    eElementState ret = data.DataState = ESError;
    if((NULL != data.data)
            &&(0 != data.datasize)
            &&((id == mElementID)||(0xffffffff == mElementID)))
    {
        mElementID = id;
        if((mDatasize != data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize))
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
                ret = data.DataState = meElementState = ESValidChanged;
                mReceiverChange = 0xffffffff;
            }
            else
            {
                 ret = data.DataState = ESError;
            }

        }
        else if((mDatasize == data.datasize)&&(MAXDATAPOOLDATASIZE > data.datasize)&&(NULL != mpdata))
        {
            if(0 != memcmp(mpdata,data.data,mDatasize))
            {
                memcpy(mpdata,data.data,data.datasize);
                ret = data.DataState = meElementState = ESValidChanged;
                mReceiverChange = 0xffffffff;
            }
            else
            {
                ret = data.DataState = ESNothing;
            }
        }
        else
        {
            ret = data.DataState = ESError;
        }

    }
    return ret;
}

bool DatapoolElement::setElementAction(unsigned int id, eElementAction elementaction)
{
    bool ret = false;
    if((id == mElementID)||(0xffffffff == mElementID))
    {
        mElementID = id;
        meElementAction = elementaction;
    }
    return ret;
}

eElementState DatapoolElement::getElement(unsigned int id, sElementDatapool &element)
{
    eElementState ret = element.DataState = ESError;
    element.id = mElementID;
    if(id == mElementID)
    {
        element.DateAction = meElementAction;
        ret = element.DataState = meElementState;
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
                ret = element.DataState = meElementState = ESValidChanged;
            }
            else
            {
                ret = element.DataState = ESError;
            }
        }
        else
        {
            element.datasize = 0;
            if(ESInt != element.DataState)
            {
                ret = element.DataState = ESError;
            }
        }
    }
    return ret;
}

eElementState DatapoolElement::getElementState(unsigned int id)
{
    eElementState ret = ESError;
    if(id == mElementID)
    {
        ret = meElementState;
    }
    return ret;
}

eElementAction DatapoolElement::getElementAction(unsigned int id)
{
    eElementAction ret = EANothing;
    if(id == mElementID)
    {
        ret = meElementAction;
    }
    return ret;
}

bool DatapoolElement::isElementReceiverChangeValid(unsigned int id, unsigned int receiver)
{
    bool ret = false;
    if(((mReceiverChange & receiver) == receiver)&&(id == mElementID))
    {
        ret = true;
        mReceiverChange = (mReceiverChange & !receiver);
    }
    return ret;
}

bool DatapoolElement::loadElement(unsigned int id)
{
    bool ret = false;
    if(id == mElementID)
    {
        qCDebug(m_categrory) << "loadElement Element: " << mElementID << " Status: " << ret;
    }
    return ret;
}

bool DatapoolElement::saveElement(unsigned int id)
{
    bool ret = false;
    if(id == mElementID)
    {
        qCDebug(m_categrory) << "saveElement Element: " << mElementID << " Status: " << ret;
    }
    return ret;
}
