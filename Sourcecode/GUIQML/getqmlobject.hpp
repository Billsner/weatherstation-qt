#ifndef GETQMLOBJECT_HPP
#define GETQMLOBJECT_HPP

#include <QObject>
#include "Utils/logging.hpp"


class GetQMLObject
{
public:
    GetQMLObject();
    ~GetQMLObject();

    static GetQMLObject *getInstance();
    static void DestroyGetQMLObject();

    void SetQMLEngineRootObject(QObject *QMLEngineRootObject);
    QObject *GetSpcificQMLObject(QString Objectname);

private:
    Logging mLogging;
    QObject *mQMLEngineRootObject;
};

#endif // GETQMLOBJECT_HPP
