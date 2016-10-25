/****************************************************************************
** Meta object code from reading C++ file 'sdmSimpleMatrixItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/spencers-dm/cecropia-graph/sdmSimpleMatrixItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sdmSimpleMatrixItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spencers__SimpleMatrixItem_t {
    QByteArrayData data[4];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spencers__SimpleMatrixItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spencers__SimpleMatrixItem_t qt_meta_stringdata_spencers__SimpleMatrixItem = {
    {
QT_MOC_LITERAL(0, 0, 26), // "spencers::SimpleMatrixItem"
QT_MOC_LITERAL(1, 27, 13), // "cellDidChange"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 9) // "cellIndex"

    },
    "spencers::SimpleMatrixItem\0cellDidChange\0"
    "\0cellIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spencers__SimpleMatrixItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void spencers::SimpleMatrixItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimpleMatrixItem *_t = static_cast<SimpleMatrixItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cellDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SimpleMatrixItem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SimpleMatrixItem::cellDidChange)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject spencers::SimpleMatrixItem::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_spencers__SimpleMatrixItem.data,
      qt_meta_data_spencers__SimpleMatrixItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spencers::SimpleMatrixItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spencers::SimpleMatrixItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spencers__SimpleMatrixItem.stringdata0))
        return static_cast<void*>(const_cast< SimpleMatrixItem*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int spencers::SimpleMatrixItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void spencers::SimpleMatrixItem::cellDidChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
