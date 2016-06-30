/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[21];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 11), // "eventFilter"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "obj"
QT_MOC_LITERAL(4, 24, 7), // "QEvent*"
QT_MOC_LITERAL(5, 32, 5), // "event"
QT_MOC_LITERAL(6, 38, 23), // "on_CancelButton_clicked"
QT_MOC_LITERAL(7, 62, 4), // "draw"
QT_MOC_LITERAL(8, 67, 1), // "x"
QT_MOC_LITERAL(9, 69, 1), // "y"
QT_MOC_LITERAL(10, 71, 22), // "on_ApplyButton_clicked"
QT_MOC_LITERAL(11, 94, 21), // "on_TurnButton_clicked"
QT_MOC_LITERAL(12, 116, 20), // "on_cutButton_clicked"
QT_MOC_LITERAL(13, 137, 24), // "on_spinBoxx_valueChanged"
QT_MOC_LITERAL(14, 162, 4), // "arg1"
QT_MOC_LITERAL(15, 167, 24), // "on_spinBoxy_valueChanged"
QT_MOC_LITERAL(16, 192, 29), // "on_doubleSpinBox_valueChanged"
QT_MOC_LITERAL(17, 222, 21), // "on_leftButton_clicked"
QT_MOC_LITERAL(18, 244, 22), // "on_rightButton_clicked"
QT_MOC_LITERAL(19, 267, 21), // "on_HomoButton_clicked"
QT_MOC_LITERAL(20, 289, 21) // "on_SaveButton_clicked"

    },
    "Dialog\0eventFilter\0\0obj\0QEvent*\0event\0"
    "on_CancelButton_clicked\0draw\0x\0y\0"
    "on_ApplyButton_clicked\0on_TurnButton_clicked\0"
    "on_cutButton_clicked\0on_spinBoxx_valueChanged\0"
    "arg1\0on_spinBoxy_valueChanged\0"
    "on_doubleSpinBox_valueChanged\0"
    "on_leftButton_clicked\0on_rightButton_clicked\0"
    "on_HomoButton_clicked\0on_SaveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    2,   85,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      15,    1,   96,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->on_CancelButton_clicked(); break;
        case 2: _t->draw((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_ApplyButton_clicked(); break;
        case 4: _t->on_TurnButton_clicked(); break;
        case 5: _t->on_cutButton_clicked(); break;
        case 6: _t->on_spinBoxx_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinBoxy_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_leftButton_clicked(); break;
        case 10: _t->on_rightButton_clicked(); break;
        case 11: _t->on_HomoButton_clicked(); break;
        case 12: _t->on_SaveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
