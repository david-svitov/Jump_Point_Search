/****************************************************************************
** Meta object code from reading C++ file 'jps.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JPS/jps.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jps.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JPS_t {
    QByteArrayData data[20];
    char stringdata[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_JPS_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_JPS_t qt_meta_stringdata_JPS = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 12),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 11),
QT_MOC_LITERAL(4, 30, 1),
QT_MOC_LITERAL(5, 32, 21),
QT_MOC_LITERAL(6, 54, 10),
QT_MOC_LITERAL(7, 65, 12),
QT_MOC_LITERAL(8, 78, 5),
QT_MOC_LITERAL(9, 84, 23),
QT_MOC_LITERAL(10, 108, 23),
QT_MOC_LITERAL(11, 132, 23),
QT_MOC_LITERAL(12, 156, 15),
QT_MOC_LITERAL(13, 172, 12),
QT_MOC_LITERAL(14, 185, 1),
QT_MOC_LITERAL(15, 187, 23),
QT_MOC_LITERAL(16, 211, 23),
QT_MOC_LITERAL(17, 235, 23),
QT_MOC_LITERAL(18, 259, 23),
QT_MOC_LITERAL(19, 283, 23)
    },
    "JPS\0errorMessage\0\0std::string\0m\0"
    "on_pushButton_clicked\0paintEvent\0"
    "QPaintEvent*\0event\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_8_clicked\0"
    "on_pushButton_9_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JPS[] = {

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
       1,    1,   74,    2, 0x08,
       5,    0,   77,    2, 0x08,
       6,    1,   78,    2, 0x08,
       9,    0,   81,    2, 0x08,
      10,    0,   82,    2, 0x08,
      11,    0,   83,    2, 0x08,
      12,    1,   84,    2, 0x08,
      15,    0,   87,    2, 0x08,
      16,    0,   88,    2, 0x08,
      17,    0,   89,    2, 0x08,
      18,    0,   90,    2, 0x08,
      19,    0,   91,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void JPS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JPS *_t = static_cast<JPS *>(_o);
        switch (_id) {
        case 0: _t->errorMessage((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_6_clicked(); break;
        case 9: _t->on_pushButton_7_clicked(); break;
        case 10: _t->on_pushButton_8_clicked(); break;
        case 11: _t->on_pushButton_9_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject JPS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_JPS.data,
      qt_meta_data_JPS,  qt_static_metacall, 0, 0}
};


const QMetaObject *JPS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JPS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JPS.stringdata))
        return static_cast<void*>(const_cast< JPS*>(this));
    return QWidget::qt_metacast(_clname);
}

int JPS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
