/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[24];
    char stringdata0[453];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 16), // "slotColorItemSel"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "slotUpdateEditData"
QT_MOC_LITERAL(4, 44, 15), // "slotEditChanged"
QT_MOC_LITERAL(5, 60, 16), // "slotEditFinished"
QT_MOC_LITERAL(6, 77, 17), // "slotValueChangedH"
QT_MOC_LITERAL(7, 95, 17), // "slotValueChangedS"
QT_MOC_LITERAL(8, 113, 17), // "slotValueChangedV"
QT_MOC_LITERAL(9, 131, 17), // "slotValueChangedR"
QT_MOC_LITERAL(10, 149, 17), // "slotValueChangedG"
QT_MOC_LITERAL(11, 167, 17), // "slotValueChangedB"
QT_MOC_LITERAL(12, 185, 21), // "slotValueChangedXYZ_X"
QT_MOC_LITERAL(13, 207, 21), // "slotValueChangedXYZ_Y"
QT_MOC_LITERAL(14, 229, 21), // "slotValueChangedXYZ_Z"
QT_MOC_LITERAL(15, 251, 22), // "slotValueChangedCMYK_C"
QT_MOC_LITERAL(16, 274, 22), // "slotValueChangedCMYK_M"
QT_MOC_LITERAL(17, 297, 22), // "slotValueChangedCMYK_Y"
QT_MOC_LITERAL(18, 320, 22), // "slotValueChangedCMYK_K"
QT_MOC_LITERAL(19, 343, 21), // "slotValueChangedLAB_L"
QT_MOC_LITERAL(20, 365, 21), // "slotValueChangedLAB_A"
QT_MOC_LITERAL(21, 387, 21), // "slotValueChangedLAB_B"
QT_MOC_LITERAL(22, 409, 21), // "slotValueChangedHSL_S"
QT_MOC_LITERAL(23, 431, 21) // "slotValueChangedHSL_L"

    },
    "Widget\0slotColorItemSel\0\0slotUpdateEditData\0"
    "slotEditChanged\0slotEditFinished\0"
    "slotValueChangedH\0slotValueChangedS\0"
    "slotValueChangedV\0slotValueChangedR\0"
    "slotValueChangedG\0slotValueChangedB\0"
    "slotValueChangedXYZ_X\0slotValueChangedXYZ_Y\0"
    "slotValueChangedXYZ_Z\0slotValueChangedCMYK_C\0"
    "slotValueChangedCMYK_M\0slotValueChangedCMYK_Y\0"
    "slotValueChangedCMYK_K\0slotValueChangedLAB_L\0"
    "slotValueChangedLAB_A\0slotValueChangedLAB_B\0"
    "slotValueChangedHSL_S\0slotValueChangedHSL_L"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x0a /* Public */,
       3,    3,  127,    2, 0x0a /* Public */,
       4,    1,  134,    2, 0x0a /* Public */,
       5,    0,  137,    2, 0x0a /* Public */,
       6,    1,  138,    2, 0x0a /* Public */,
       7,    1,  141,    2, 0x0a /* Public */,
       8,    1,  144,    2, 0x0a /* Public */,
       9,    1,  147,    2, 0x0a /* Public */,
      10,    1,  150,    2, 0x0a /* Public */,
      11,    1,  153,    2, 0x0a /* Public */,
      12,    1,  156,    2, 0x0a /* Public */,
      13,    1,  159,    2, 0x0a /* Public */,
      14,    1,  162,    2, 0x0a /* Public */,
      15,    1,  165,    2, 0x0a /* Public */,
      16,    1,  168,    2, 0x0a /* Public */,
      17,    1,  171,    2, 0x0a /* Public */,
      18,    1,  174,    2, 0x0a /* Public */,
      19,    1,  177,    2, 0x0a /* Public */,
      20,    1,  180,    2, 0x0a /* Public */,
      21,    1,  183,    2, 0x0a /* Public */,
      22,    1,  186,    2, 0x0a /* Public */,
      23,    1,  189,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotColorItemSel((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->slotUpdateEditData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->slotEditChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slotEditFinished(); break;
        case 4: _t->slotValueChangedH((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotValueChangedS((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slotValueChangedV((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slotValueChangedR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotValueChangedG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotValueChangedB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slotValueChangedXYZ_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->slotValueChangedXYZ_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->slotValueChangedXYZ_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->slotValueChangedCMYK_C((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->slotValueChangedCMYK_M((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->slotValueChangedCMYK_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->slotValueChangedCMYK_K((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->slotValueChangedLAB_L((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->slotValueChangedLAB_A((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->slotValueChangedLAB_B((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->slotValueChangedHSL_S((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->slotValueChangedHSL_L((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ColorChange"))
        return static_cast< ColorChange*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
