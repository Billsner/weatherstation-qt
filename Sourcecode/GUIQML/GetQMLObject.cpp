#include "GetQMLObject.hpp"

static GetQMLObject *mpGetQMLObject = NULL;

GetQMLObject::GetQMLObject() :
    mLogging("GUIQML.GetQMLObject"),
    mQMLEngineRootObject(NULL)
{

}

GetQMLObject::~GetQMLObject()
{

}

GetQMLObject *GetQMLObject::getInstance()
{
    if(NULL == mpGetQMLObject)
    {
        mpGetQMLObject = new GetQMLObject;        
    }
    return mpGetQMLObject;
}

void GetQMLObject::DestroyGetQMLObject()
{
    if(NULL != mpGetQMLObject)
    {
        delete mpGetQMLObject;        
    }
}

void GetQMLObject::SetQMLEngineRootObject(QObject *QMLEngineRootObject)
{
    if(NULL != QMLEngineRootObject)
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
    QObject *myObject = NULL;
    if(NULL != mQMLEngineRootObject)
    {
        myObject = mQMLEngineRootObject->findChild<QObject*>(Objectname);
    }
    else
    {
        mLogging << LLcritical <= "GetSpcificQMLObject: No RootObject";
    }
    return myObject;
}
