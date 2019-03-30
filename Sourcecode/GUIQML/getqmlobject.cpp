#include "getqmlobject.hpp"

static GetQMLObject *mpGetQMLObject = nullptr;

GetQMLObject::GetQMLObject() :
    mLogging("GUIQML.GetQMLObject"),
    mQMLEngineRootObject(nullptr)
{

}

GetQMLObject::~GetQMLObject()
{

}

GetQMLObject *GetQMLObject::getInstance()
{
    if(nullptr == mpGetQMLObject)
    {
        mpGetQMLObject = new GetQMLObject;        
    }
    return mpGetQMLObject;
}

void GetQMLObject::DestroyGetQMLObject()
{
    if(nullptr != mpGetQMLObject)
    {
        delete mpGetQMLObject;        
    }
}

void GetQMLObject::SetQMLEngineRootObject(QObject *QMLEngineRootObject)
{
    if(nullptr != QMLEngineRootObject)
    {
        mQMLEngineRootObject = QMLEngineRootObject;
        mLogging <= "SetQMLEngineRootObject: Valid RootObject";
    }
    else
    {
        mLogging << LLcritical <= "SetQMLEngineRootObject: No RootObject";
    }
}

QObject *GetQMLObject::GetSpcificQMLObject(QString Objectname)
{
    QObject *myObject = nullptr;
    if(nullptr != mQMLEngineRootObject)
    {
        myObject = mQMLEngineRootObject->findChild<QObject*>(Objectname);
    }
    else
    {
        mLogging << LLcritical <= "GetSpcificQMLObject: No RootObject";
    }
    return myObject;
}
