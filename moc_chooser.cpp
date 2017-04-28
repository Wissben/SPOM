/****************************************************************************
** Meta object code from reading C++ file 'chooser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chooser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chooser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Chooser_t {
    QByteArrayData data[16];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chooser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chooser_t qt_meta_stringdata_Chooser = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Chooser"
QT_MOC_LITERAL(1, 8, 24), // "on_gradiantMorph_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 56, 31), // "on_alphaChooserSAP_valueChanged"
QT_MOC_LITERAL(5, 88, 5), // "value"
QT_MOC_LITERAL(6, 94, 24), // "on_NChooser_valueChanged"
QT_MOC_LITERAL(7, 119, 4), // "arg1"
QT_MOC_LITERAL(8, 124, 31), // "on_alphaChooserRec_valueChanged"
QT_MOC_LITERAL(9, 156, 21), // "on_recChooser_clicked"
QT_MOC_LITERAL(10, 178, 26), // "on_gradiantChooser_clicked"
QT_MOC_LITERAL(11, 205, 32), // "on_alphaChooserGrad_valueChanged"
QT_MOC_LITERAL(12, 238, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(13, 271, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(14, 306, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(15, 340, 20) // "on_Chooser_destroyed"

    },
    "Chooser\0on_gradiantMorph_clicked\0\0"
    "on_pushButton_clicked\0"
    "on_alphaChooserSAP_valueChanged\0value\0"
    "on_NChooser_valueChanged\0arg1\0"
    "on_alphaChooserRec_valueChanged\0"
    "on_recChooser_clicked\0on_gradiantChooser_clicked\0"
    "on_alphaChooserGrad_valueChanged\0"
    "on_horizontalSlider_valueChanged\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_horizontalSlider_sliderPressed\0"
    "on_Chooser_destroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chooser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       8,    1,   82,    2, 0x08 /* Private */,
       9,    0,   85,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chooser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chooser *_t = static_cast<Chooser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_gradiantMorph_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_alphaChooserSAP_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_alphaChooserRec_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_recChooser_clicked(); break;
        case 6: _t->on_gradiantChooser_clicked(); break;
        case 7: _t->on_alphaChooserGrad_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_sliderReleased(); break;
        case 10: _t->on_horizontalSlider_sliderPressed(); break;
        case 11: _t->on_Chooser_destroyed(); break;
        default: ;
        }
    }
}

const QMetaObject Chooser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Chooser.data,
      qt_meta_data_Chooser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chooser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chooser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chooser.stringdata0))
        return static_cast<void*>(const_cast< Chooser*>(this));
    return QWidget::qt_metacast(_clname);
}

int Chooser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
