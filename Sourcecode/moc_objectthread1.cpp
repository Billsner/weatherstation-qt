/****************************************************************************
** Meta object code from reading C++ file 'objectthread1.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "objectthread1.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectthread1.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ObjectThread1_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ObjectThread1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ObjectThread1_t qt_meta_stringdata_ObjectThread1 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ObjectThread1"
QT_MOC_LITERAL(1, 14, 13), // "sendtoThread2"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "count"
QT_MOC_LITERAL(4, 35, 8), // "setClock"
QT_MOC_LITERAL(5, 44, 4), // "time"
QT_MOC_LITERAL(6, 49, 19), // "receiveThread2Count"
QT_MOC_LITERAL(7, 69, 13) // "receiveSwitch"

    },
    "ObjectThread1\0sendtoThread2\0\0count\0"
    "setClock\0time\0receiveThread2Count\0"
    "receiveSwitch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObjectThread1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ObjectThread1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObjectThread1 *_t = static_cast<ObjectThread1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendtoThread2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setClock((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->receiveThread2Count((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->receiveSwitch((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ObjectThread1::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ObjectThread1::sendtoThread2)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ObjectThread1::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ObjectThread1::setClock)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ObjectThread1::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ObjectThread1.data,
      qt_meta_data_ObjectThread1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ObjectThread1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectThread1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectThread1.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ObjectThread1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ObjectThread1::sendtoThread2(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObjectThread1::setClock(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
