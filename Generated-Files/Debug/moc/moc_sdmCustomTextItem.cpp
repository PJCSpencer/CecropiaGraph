/****************************************************************************
** Meta object code from reading C++ file 'sdmCustomTextItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/spencers-dm/cecropia-graph/sdmCustomTextItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sdmCustomTextItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spencers__CustomTextItem_t {
    QByteArrayData data[6];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spencers__CustomTextItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spencers__CustomTextItem_t qt_meta_stringdata_spencers__CustomTextItem = {
    {
QT_MOC_LITERAL(0, 0, 24), // "spencers::CustomTextItem"
QT_MOC_LITERAL(1, 25, 13), // "returnPressed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 11), // "textChanged"
QT_MOC_LITERAL(4, 52, 4), // "text"
QT_MOC_LITERAL(5, 57, 15) // "editingFinished"

    },
    "spencers::CustomTextItem\0returnPressed\0"
    "\0textChanged\0text\0editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spencers__CustomTextItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void spencers::CustomTextItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomTextItem *_t = static_cast<CustomTextItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnPressed(); break;
        case 1: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomTextItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomTextItem::returnPressed)) {
                *result = 0;
            }
        }
        {
            typedef void (CustomTextItem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomTextItem::textChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CustomTextItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomTextItem::editingFinished)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject spencers::CustomTextItem::staticMetaObject = {
    { &QGraphicsTextItem::staticMetaObject, qt_meta_stringdata_spencers__CustomTextItem.data,
      qt_meta_data_spencers__CustomTextItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spencers::CustomTextItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spencers::CustomTextItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spencers__CustomTextItem.stringdata0))
        return static_cast<void*>(const_cast< CustomTextItem*>(this));
    return QGraphicsTextItem::qt_metacast(_clname);
}

int spencers::CustomTextItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTextItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void spencers::CustomTextItem::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void spencers::CustomTextItem::textChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void spencers::CustomTextItem::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
