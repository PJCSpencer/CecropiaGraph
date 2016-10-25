/****************************************************************************
** Meta object code from reading C++ file 'sdmPlugGroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/spencers-dm/cecropia-graph/sdmPlugGroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sdmPlugGroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spencers__PlugGroup_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spencers__PlugGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spencers__PlugGroup_t qt_meta_stringdata_spencers__PlugGroup = {
    {
QT_MOC_LITERAL(0, 0, 19), // "spencers::PlugGroup"
QT_MOC_LITERAL(1, 20, 16), // "plugGroupChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 10), // "PlugGroup&"
QT_MOC_LITERAL(4, 49, 9), // "plugGroup"
QT_MOC_LITERAL(5, 59, 17), // "plugGroupDetached"
QT_MOC_LITERAL(6, 77, 5), // "Plug*"
QT_MOC_LITERAL(7, 83, 4) // "plug"

    },
    "spencers::PlugGroup\0plugGroupChanged\0"
    "\0PlugGroup&\0plugGroup\0plugGroupDetached\0"
    "Plug*\0plug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spencers__PlugGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    2,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,

       0        // eod
};

void spencers::PlugGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlugGroup *_t = static_cast<PlugGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plugGroupChanged((*reinterpret_cast< PlugGroup(*)>(_a[1]))); break;
        case 1: _t->plugGroupDetached((*reinterpret_cast< PlugGroup(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlugGroup::*_t)(PlugGroup & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlugGroup::plugGroupChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PlugGroup::*_t)(PlugGroup & , Plug * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlugGroup::plugGroupDetached)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject spencers::PlugGroup::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_spencers__PlugGroup.data,
      qt_meta_data_spencers__PlugGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spencers::PlugGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spencers::PlugGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spencers__PlugGroup.stringdata0))
        return static_cast<void*>(const_cast< PlugGroup*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int spencers::PlugGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void spencers::PlugGroup::plugGroupChanged(PlugGroup & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void spencers::PlugGroup::plugGroupDetached(PlugGroup & _t1, Plug * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
