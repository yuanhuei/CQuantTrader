/****************************************************************************
** Meta object code from reading C++ file 'CTAStrategyManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CTAStrategyManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTAStrategyManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTAStrategyManager_t {
    QByteArrayData data[10];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTAStrategyManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTAStrategyManager_t qt_meta_stringdata_CTAStrategyManager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CTAStrategyManager"
QT_MOC_LITERAL(1, 19, 19), // "addStrategy_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "initStrategy_clicked"
QT_MOC_LITERAL(4, 61, 20), // "startStrategy_cliced"
QT_MOC_LITERAL(5, 82, 20), // "stopStragegy_clicked"
QT_MOC_LITERAL(6, 103, 24), // "startAllStrategy_clicked"
QT_MOC_LITERAL(7, 128, 23), // "stopAllStrategy_clicked"
QT_MOC_LITERAL(8, 152, 8), // "clearLog"
QT_MOC_LITERAL(9, 161, 21) // "StrategyTable_clicked"

    },
    "CTAStrategyManager\0addStrategy_clicked\0"
    "\0initStrategy_clicked\0startStrategy_cliced\0"
    "stopStragegy_clicked\0startAllStrategy_clicked\0"
    "stopAllStrategy_clicked\0clearLog\0"
    "StrategyTable_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTAStrategyManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CTAStrategyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTAStrategyManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addStrategy_clicked(); break;
        case 1: _t->initStrategy_clicked(); break;
        case 2: _t->startStrategy_cliced(); break;
        case 3: _t->stopStragegy_clicked(); break;
        case 4: _t->startAllStrategy_clicked(); break;
        case 5: _t->stopAllStrategy_clicked(); break;
        case 6: _t->clearLog(); break;
        case 7: _t->StrategyTable_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CTAStrategyManager::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CTAStrategyManager.data,
    qt_meta_data_CTAStrategyManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CTAStrategyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTAStrategyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTAStrategyManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CTAStrategyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
