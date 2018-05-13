#ifndef GETQMLOBJECT_HPP
#define GETQMLOBJECT_HPP

#include <QObject>
#include <QLoggingCategory>


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
    QLoggingCategory m_categrory;
    QObject *mQMLEngineRootObject;
};

#endif // GETQMLOBJECT_HPP
