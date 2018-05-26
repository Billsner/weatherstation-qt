#include "GetQMLObject.hpp"

static GetQMLObject *mpGetQMLObject = NULL;

GetQMLObject::GetQMLObject() :
    m_categrory("GUIQML.GetQMLObject"),
    mQMLEngineRootObject(NULL)
{
    qCDebug(m_categrory) << "Constructer";
}

GetQMLObject::~GetQMLObject()
{
    qCDebug(m_categrory) << "Destructer";
}

GetQMLObject *GetQMLObject::getInstance()
{
    if(NULL == mpGetQMLObject)
    {
        mpGetQMLObject = new GetQMLObject;
        //qCDebug("GetQMLObject") << "getInstance: Create new Instance";
    }
    return mpGetQMLObject;
}

void GetQMLObject::DestroyGetQMLObject()
{
    if(NULL != mpGetQMLObject)
    {
        delete mpGetQMLObject;
        //qCDebug("GetQMLObject") << "DestroyGetQMLObject: Destroy Instance";
    }
}

void GetQMLObject::SetQMLEngineRootObject(QObject *QMLEngineRootObject)
{
    if(NULL != QMLEngineRootObject)
    {
        mQMLEngineRootObject = QMLEngineRootObject;
        qCDebug(m_categrory) << "SetQMLEngineRootObject: Valid RootObject";
    }
    else
    {
        qCDebug(m_categrory) << "SetQMLEngineRootObject: No RootObject";
    }
}

QObject *GetQMLObject::GetSpcificQMLObject(QString Objectname)
{
    QObject *myObject = NULL;
    if(NULL != mQMLEngineRootObject)
    {
        myObject = mQMLEngineRootObject->findChild<QObject*>(Objectname);
    }
    return myObject;
}
