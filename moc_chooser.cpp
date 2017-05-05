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
    QByteArrayData data[58];
    char stringdata0[1203];
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
QT_MOC_LITERAL(6, 94, 31), // "on_alphaChooserRec_valueChanged"
QT_MOC_LITERAL(7, 126, 21), // "on_recChooser_clicked"
QT_MOC_LITERAL(8, 148, 26), // "on_gradiantChooser_clicked"
QT_MOC_LITERAL(9, 175, 32), // "on_alphaChooserGrad_valueChanged"
QT_MOC_LITERAL(10, 208, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(11, 241, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(12, 276, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(13, 310, 20), // "on_Chooser_destroyed"
QT_MOC_LITERAL(14, 331, 23), // "on_arithChooser_clicked"
QT_MOC_LITERAL(15, 355, 7), // "checked"
QT_MOC_LITERAL(16, 363, 21), // "on_SAPChooser_clicked"
QT_MOC_LITERAL(17, 385, 18), // "on_control_clicked"
QT_MOC_LITERAL(18, 404, 23), // "on_controlArith_clicked"
QT_MOC_LITERAL(19, 428, 20), // "on_SDChooser_clicked"
QT_MOC_LITERAL(20, 449, 21), // "on_controlRec_clicked"
QT_MOC_LITERAL(21, 471, 20), // "on_controlSD_clicked"
QT_MOC_LITERAL(22, 492, 21), // "on_controlSAP_clicked"
QT_MOC_LITERAL(23, 514, 16), // "on_accel_clicked"
QT_MOC_LITERAL(24, 531, 17), // "on_deccel_clicked"
QT_MOC_LITERAL(25, 549, 20), // "on_speedDown_clicked"
QT_MOC_LITERAL(26, 570, 18), // "on_speedUp_clicked"
QT_MOC_LITERAL(27, 589, 14), // "on_end_clicked"
QT_MOC_LITERAL(28, 604, 16), // "on_begin_clicked"
QT_MOC_LITERAL(29, 621, 22), // "on_accel_Arith_clicked"
QT_MOC_LITERAL(30, 644, 23), // "on_deccel_Arith_clicked"
QT_MOC_LITERAL(31, 668, 24), // "on_speedUp_Arith_clicked"
QT_MOC_LITERAL(32, 693, 26), // "on_speedDown_Arith_clicked"
QT_MOC_LITERAL(33, 720, 20), // "on_end_Arith_clicked"
QT_MOC_LITERAL(34, 741, 22), // "on_begin_Arith_clicked"
QT_MOC_LITERAL(35, 764, 22), // "on_speedUp_Rec_clicked"
QT_MOC_LITERAL(36, 787, 24), // "on_speedDown_Rec_clicked"
QT_MOC_LITERAL(37, 812, 21), // "on_deccel_Rec_clicked"
QT_MOC_LITERAL(38, 834, 20), // "on_accel_Rec_clicked"
QT_MOC_LITERAL(39, 855, 20), // "on_begin_Rec_clicked"
QT_MOC_LITERAL(40, 876, 18), // "on_end_Rec_clicked"
QT_MOC_LITERAL(41, 895, 19), // "on_begin_SD_clicked"
QT_MOC_LITERAL(42, 915, 20), // "on_deccel_SD_clicked"
QT_MOC_LITERAL(43, 936, 23), // "on_speedDown_SD_clicked"
QT_MOC_LITERAL(44, 960, 21), // "on_speedUp_SD_clicked"
QT_MOC_LITERAL(45, 982, 19), // "on_accel_SD_clicked"
QT_MOC_LITERAL(46, 1002, 17), // "on_end_SD_clicked"
QT_MOC_LITERAL(47, 1020, 22), // "on_speedUp_SAP_clicked"
QT_MOC_LITERAL(48, 1043, 24), // "on_speedDown_SAP_clicked"
QT_MOC_LITERAL(49, 1068, 21), // "on_deccel_SAP_clicked"
QT_MOC_LITERAL(50, 1090, 20), // "on_accel_SAP_clicked"
QT_MOC_LITERAL(51, 1111, 20), // "on_begin_SAP_clicked"
QT_MOC_LITERAL(52, 1132, 18), // "on_end_SAP_clicked"
QT_MOC_LITERAL(53, 1151, 10), // "updateGrad"
QT_MOC_LITERAL(54, 1162, 9), // "updateRec"
QT_MOC_LITERAL(55, 1172, 8), // "updateSD"
QT_MOC_LITERAL(56, 1181, 9), // "updateSAP"
QT_MOC_LITERAL(57, 1191, 11) // "updateArith"

    },
    "Chooser\0on_gradiantMorph_clicked\0\0"
    "on_pushButton_clicked\0"
    "on_alphaChooserSAP_valueChanged\0value\0"
    "on_alphaChooserRec_valueChanged\0"
    "on_recChooser_clicked\0on_gradiantChooser_clicked\0"
    "on_alphaChooserGrad_valueChanged\0"
    "on_horizontalSlider_valueChanged\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_horizontalSlider_sliderPressed\0"
    "on_Chooser_destroyed\0on_arithChooser_clicked\0"
    "checked\0on_SAPChooser_clicked\0"
    "on_control_clicked\0on_controlArith_clicked\0"
    "on_SDChooser_clicked\0on_controlRec_clicked\0"
    "on_controlSD_clicked\0on_controlSAP_clicked\0"
    "on_accel_clicked\0on_deccel_clicked\0"
    "on_speedDown_clicked\0on_speedUp_clicked\0"
    "on_end_clicked\0on_begin_clicked\0"
    "on_accel_Arith_clicked\0on_deccel_Arith_clicked\0"
    "on_speedUp_Arith_clicked\0"
    "on_speedDown_Arith_clicked\0"
    "on_end_Arith_clicked\0on_begin_Arith_clicked\0"
    "on_speedUp_Rec_clicked\0on_speedDown_Rec_clicked\0"
    "on_deccel_Rec_clicked\0on_accel_Rec_clicked\0"
    "on_begin_Rec_clicked\0on_end_Rec_clicked\0"
    "on_begin_SD_clicked\0on_deccel_SD_clicked\0"
    "on_speedDown_SD_clicked\0on_speedUp_SD_clicked\0"
    "on_accel_SD_clicked\0on_end_SD_clicked\0"
    "on_speedUp_SAP_clicked\0on_speedDown_SAP_clicked\0"
    "on_deccel_SAP_clicked\0on_accel_SAP_clicked\0"
    "on_begin_SAP_clicked\0on_end_SAP_clicked\0"
    "updateGrad\0updateRec\0updateSD\0updateSAP\0"
    "updateArith"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chooser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  284,    2, 0x08 /* Private */,
       3,    0,  285,    2, 0x08 /* Private */,
       4,    1,  286,    2, 0x08 /* Private */,
       6,    1,  289,    2, 0x08 /* Private */,
       7,    0,  292,    2, 0x08 /* Private */,
       8,    0,  293,    2, 0x08 /* Private */,
       9,    1,  294,    2, 0x08 /* Private */,
      10,    1,  297,    2, 0x08 /* Private */,
      11,    0,  300,    2, 0x08 /* Private */,
      12,    0,  301,    2, 0x08 /* Private */,
      13,    0,  302,    2, 0x08 /* Private */,
      14,    1,  303,    2, 0x08 /* Private */,
      16,    1,  306,    2, 0x08 /* Private */,
      17,    0,  309,    2, 0x08 /* Private */,
      18,    1,  310,    2, 0x08 /* Private */,
      19,    1,  313,    2, 0x08 /* Private */,
      20,    1,  316,    2, 0x08 /* Private */,
      21,    1,  319,    2, 0x08 /* Private */,
      22,    1,  322,    2, 0x08 /* Private */,
      23,    1,  325,    2, 0x08 /* Private */,
      24,    1,  328,    2, 0x08 /* Private */,
      25,    1,  331,    2, 0x08 /* Private */,
      26,    1,  334,    2, 0x08 /* Private */,
      27,    1,  337,    2, 0x08 /* Private */,
      28,    1,  340,    2, 0x08 /* Private */,
      29,    1,  343,    2, 0x08 /* Private */,
      30,    0,  346,    2, 0x08 /* Private */,
      31,    1,  347,    2, 0x08 /* Private */,
      32,    1,  350,    2, 0x08 /* Private */,
      33,    1,  353,    2, 0x08 /* Private */,
      34,    1,  356,    2, 0x08 /* Private */,
      35,    1,  359,    2, 0x08 /* Private */,
      36,    1,  362,    2, 0x08 /* Private */,
      37,    0,  365,    2, 0x08 /* Private */,
      38,    1,  366,    2, 0x08 /* Private */,
      39,    1,  369,    2, 0x08 /* Private */,
      40,    1,  372,    2, 0x08 /* Private */,
      41,    1,  375,    2, 0x08 /* Private */,
      42,    1,  378,    2, 0x08 /* Private */,
      43,    1,  381,    2, 0x08 /* Private */,
      44,    1,  384,    2, 0x08 /* Private */,
      45,    1,  387,    2, 0x08 /* Private */,
      46,    1,  390,    2, 0x08 /* Private */,
      47,    1,  393,    2, 0x08 /* Private */,
      48,    1,  396,    2, 0x08 /* Private */,
      49,    1,  399,    2, 0x08 /* Private */,
      50,    1,  402,    2, 0x08 /* Private */,
      51,    1,  405,    2, 0x08 /* Private */,
      52,    1,  408,    2, 0x08 /* Private */,
      53,    0,  411,    2, 0x0a /* Public */,
      54,    0,  412,    2, 0x0a /* Public */,
      55,    0,  413,    2, 0x0a /* Public */,
      56,    0,  414,    2, 0x0a /* Public */,
      57,    0,  415,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,
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
        case 3: _t->on_alphaChooserRec_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_recChooser_clicked(); break;
        case 5: _t->on_gradiantChooser_clicked(); break;
        case 6: _t->on_alphaChooserGrad_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_sliderReleased(); break;
        case 9: _t->on_horizontalSlider_sliderPressed(); break;
        case 10: _t->on_Chooser_destroyed(); break;
        case 11: _t->on_arithChooser_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_SAPChooser_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_control_clicked(); break;
        case 14: _t->on_controlArith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_SDChooser_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_controlRec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_controlSD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_controlSAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_accel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_deccel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_speedDown_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_speedUp_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_end_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->on_begin_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->on_accel_Arith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_deccel_Arith_clicked(); break;
        case 27: _t->on_speedUp_Arith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_speedDown_Arith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_end_Arith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_begin_Arith_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_speedUp_Rec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_speedDown_Rec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_deccel_Rec_clicked(); break;
        case 34: _t->on_accel_Rec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_begin_Rec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_end_Rec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_begin_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_deccel_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_speedDown_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_speedUp_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_accel_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_end_SD_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_speedUp_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_speedDown_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_deccel_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->on_accel_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_begin_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_end_SAP_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->updateGrad(); break;
        case 50: _t->updateRec(); break;
        case 51: _t->updateSD(); break;
        case 52: _t->updateSAP(); break;
        case 53: _t->updateArith(); break;
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
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 54;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
