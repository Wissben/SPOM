/****************************************************************************
** Meta object code from reading C++ file 'selector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "selector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Selector_t {
    QByteArrayData data[13];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Selector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Selector_t qt_meta_stringdata_Selector = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Selector"
QT_MOC_LITERAL(1, 9, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "checked"
QT_MOC_LITERAL(4, 41, 24), // "on_radioButton_4_toggled"
QT_MOC_LITERAL(5, 66, 27), // "on_gradiantOublieux_toggled"
QT_MOC_LITERAL(6, 94, 28), // "on_moyenneRecurssive_toggled"
QT_MOC_LITERAL(7, 123, 23), // "on_moyenneArith_toggled"
QT_MOC_LITERAL(8, 147, 20), // "on_moyenneSD_toggled"
QT_MOC_LITERAL(9, 168, 14), // "on_SAP_toggled"
QT_MOC_LITERAL(10, 183, 21), // "on_Selector_destroyed"
QT_MOC_LITERAL(11, 205, 23), // "on_quitSelector_clicked"
QT_MOC_LITERAL(12, 229, 27) // "on_gradiantOublieux_clicked"

    },
    "Selector\0on_radioButton_toggled\0\0"
    "checked\0on_radioButton_4_toggled\0"
    "on_gradiantOublieux_toggled\0"
    "on_moyenneRecurssive_toggled\0"
    "on_moyenneArith_toggled\0on_moyenneSD_toggled\0"
    "on_SAP_toggled\0on_Selector_destroyed\0"
    "on_quitSelector_clicked\0"
    "on_gradiantOublieux_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Selector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Selector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Selector *_t = static_cast<Selector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 2: _t->on_gradiantOublieux_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_moyenneRecurssive_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_moyenneArith_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_moyenneSD_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_SAP_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_quitSelector_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Selector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Selector.data,
      qt_meta_data_Selector,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Selector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Selector::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Selector.stringdata0))
        return static_cast<void*>(const_cast< Selector*>(this));
    return QWidget::qt_metacast(_clname);
}

int Selector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
