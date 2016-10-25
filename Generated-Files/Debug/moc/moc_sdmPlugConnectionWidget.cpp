/****************************************************************************
** Meta object code from reading C++ file 'sdmPlugConnectionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/spencers-dm/cecropia-graph/sdmPlugConnectionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sdmPlugConnectionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spencers__PlugConnectionWidget_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spencers__PlugConnectionWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spencers__PlugConnectionWidget_t qt_meta_stringdata_spencers__PlugConnectionWidget = {
    {
QT_MOC_LITERAL(0, 0, 30), // "spencers::PlugConnectionWidget"
QT_MOC_LITERAL(1, 31, 12), // "startSession"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 10), // "PlugGroup&"
QT_MOC_LITERAL(4, 56, 9), // "plugGroup"
QT_MOC_LITERAL(5, 66, 13), // "changeSession"
QT_MOC_LITERAL(6, 80, 5), // "Plug*"
QT_MOC_LITERAL(7, 86, 4), // "plug"
QT_MOC_LITERAL(8, 91, 10), // "sceneAdded"
QT_MOC_LITERAL(9, 102, 12), // "NodeControl&"
QT_MOC_LITERAL(10, 115, 11), // "nodeControl"
QT_MOC_LITERAL(11, 127, 12) // "sceneRemoved"

    },
    "spencers::PlugConnectionWidget\0"
    "startSession\0\0PlugGroup&\0plugGroup\0"
    "changeSession\0Plug*\0plug\0sceneAdded\0"
    "NodeControl&\0nodeControl\0sceneRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spencers__PlugConnectionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,
       8,    1,   42,    2, 0x0a /* Public */,
      11,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void spencers::PlugConnectionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlugConnectionWidget *_t = static_cast<PlugConnectionWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSession((*reinterpret_cast< PlugGroup(*)>(_a[1]))); break;
        case 1: _t->changeSession((*reinterpret_cast< PlugGroup(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 2: _t->sceneAdded((*reinterpret_cast< NodeControl(*)>(_a[1]))); break;
        case 3: _t->sceneRemoved((*reinterpret_cast< NodeControl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject spencers::PlugConnectionWidget::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_spencers__PlugConnectionWidget.data,
      qt_meta_data_spencers__PlugConnectionWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spencers::PlugConnectionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spencers::PlugConnectionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spencers__PlugConnectionWidget.stringdata0))
        return static_cast<void*>(const_cast< PlugConnectionWidget*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int spencers::PlugConnectionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
