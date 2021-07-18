/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[465];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "UpdateLogSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "LogData"
QT_MOC_LITERAL(4, 36, 4), // "data"
QT_MOC_LITERAL(5, 41, 19), // "UpdateAccountSignal"
QT_MOC_LITERAL(6, 61, 11), // "AccountData"
QT_MOC_LITERAL(7, 73, 20), // "UpdatePositionSignal"
QT_MOC_LITERAL(8, 94, 12), // "PositionData"
QT_MOC_LITERAL(9, 107, 22), // "UpdatePriceTableSignal"
QT_MOC_LITERAL(10, 130, 20), // "UpdatePriceTableData"
QT_MOC_LITERAL(11, 151, 22), // "UpdateOrderTableSignal"
QT_MOC_LITERAL(12, 174, 20), // "UpdateOrderTableData"
QT_MOC_LITERAL(13, 195, 22), // "UpdateTradeTableSignal"
QT_MOC_LITERAL(14, 218, 20), // "UpdateTradeTableData"
QT_MOC_LITERAL(15, 239, 16), // "menu_ctp_connect"
QT_MOC_LITERAL(16, 256, 9), // "menu_exit"
QT_MOC_LITERAL(17, 266, 16), // "menu_CTAStrategy"
QT_MOC_LITERAL(18, 283, 16), // "menu_CTABacktest"
QT_MOC_LITERAL(19, 300, 25), // "menu_contractQueryclicked"
QT_MOC_LITERAL(20, 326, 20), // "symbol_ReturnPressed"
QT_MOC_LITERAL(21, 347, 17), // "SendOrder_clicked"
QT_MOC_LITERAL(22, 365, 16), // "UpdateAccountBox"
QT_MOC_LITERAL(23, 382, 17), // "UpdatePositionBox"
QT_MOC_LITERAL(24, 400, 14), // "UpdateLogTable"
QT_MOC_LITERAL(25, 415, 15), // "UpdateTickTable"
QT_MOC_LITERAL(26, 431, 16), // "UpdateOrderTable"
QT_MOC_LITERAL(27, 448, 16) // "UpdateTradeTable"

    },
    "MainWindow\0UpdateLogSignal\0\0LogData\0"
    "data\0UpdateAccountSignal\0AccountData\0"
    "UpdatePositionSignal\0PositionData\0"
    "UpdatePriceTableSignal\0UpdatePriceTableData\0"
    "UpdateOrderTableSignal\0UpdateOrderTableData\0"
    "UpdateTradeTableSignal\0UpdateTradeTableData\0"
    "menu_ctp_connect\0menu_exit\0menu_CTAStrategy\0"
    "menu_CTABacktest\0menu_contractQueryclicked\0"
    "symbol_ReturnPressed\0SendOrder_clicked\0"
    "UpdateAccountBox\0UpdatePositionBox\0"
    "UpdateLogTable\0UpdateTickTable\0"
    "UpdateOrderTable\0UpdateTradeTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       5,    1,  112,    2, 0x06 /* Public */,
       7,    1,  115,    2, 0x06 /* Public */,
       9,    1,  118,    2, 0x06 /* Public */,
      11,    1,  121,    2, 0x06 /* Public */,
      13,    1,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,
      20,    0,  132,    2, 0x08 /* Private */,
      21,    0,  133,    2, 0x08 /* Private */,
      22,    1,  134,    2, 0x08 /* Private */,
      23,    1,  137,    2, 0x08 /* Private */,
      24,    1,  140,    2, 0x08 /* Private */,
      25,    1,  143,    2, 0x08 /* Private */,
      26,    1,  146,    2, 0x08 /* Private */,
      27,    1,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, 0x80000000 | 10,    4,
    QMetaType::Void, 0x80000000 | 12,    4,
    QMetaType::Void, 0x80000000 | 14,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,    4,
    QMetaType::Void, 0x80000000 | 12,    4,
    QMetaType::Void, 0x80000000 | 14,    4,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateLogSignal((*reinterpret_cast< LogData(*)>(_a[1]))); break;
        case 1: _t->UpdateAccountSignal((*reinterpret_cast< AccountData(*)>(_a[1]))); break;
        case 2: _t->UpdatePositionSignal((*reinterpret_cast< PositionData(*)>(_a[1]))); break;
        case 3: _t->UpdatePriceTableSignal((*reinterpret_cast< UpdatePriceTableData(*)>(_a[1]))); break;
        case 4: _t->UpdateOrderTableSignal((*reinterpret_cast< UpdateOrderTableData(*)>(_a[1]))); break;
        case 5: _t->UpdateTradeTableSignal((*reinterpret_cast< UpdateTradeTableData(*)>(_a[1]))); break;
        case 6: _t->menu_ctp_connect(); break;
        case 7: _t->menu_exit(); break;
        case 8: _t->menu_CTAStrategy(); break;
        case 9: _t->menu_CTABacktest(); break;
        case 10: _t->menu_contractQueryclicked(); break;
        case 11: _t->symbol_ReturnPressed(); break;
        case 12: _t->SendOrder_clicked(); break;
        case 13: _t->UpdateAccountBox((*reinterpret_cast< AccountData(*)>(_a[1]))); break;
        case 14: _t->UpdatePositionBox((*reinterpret_cast< PositionData(*)>(_a[1]))); break;
        case 15: _t->UpdateLogTable((*reinterpret_cast< LogData(*)>(_a[1]))); break;
        case 16: _t->UpdateTickTable((*reinterpret_cast< UpdatePriceTableData(*)>(_a[1]))); break;
        case 17: _t->UpdateOrderTable((*reinterpret_cast< UpdateOrderTableData(*)>(_a[1]))); break;
        case 18: _t->UpdateTradeTable((*reinterpret_cast< UpdateTradeTableData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(LogData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateLogSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(AccountData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateAccountSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(PositionData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdatePositionSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(UpdatePriceTableData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdatePriceTableSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(UpdateOrderTableData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateOrderTableSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(UpdateTradeTableData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateTradeTableSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::UpdateLogSignal(LogData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::UpdateAccountSignal(AccountData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::UpdatePositionSignal(PositionData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::UpdatePriceTableSignal(UpdatePriceTableData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::UpdateOrderTableSignal(UpdateOrderTableData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::UpdateTradeTableSignal(UpdateTradeTableData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
