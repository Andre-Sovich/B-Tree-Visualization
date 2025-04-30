/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "on_insert_button_clicked",
    "",
    "on_btree_radio_button_clicked",
    "on_bplus_radio_button_clicked",
    "on_bstar_radio_button_clicked",
    "on_delete_button_clicked",
    "on_clear_button_clicked",
    "max_degree_combo_index_changed",
    "index",
    "resetTrees",
    "clearDisplay",
    "isNumber",
    "std::string",
    "string",
    "displayTreeFromQueue",
    "queue<BPlusTreeNode*>",
    "q",
    "displayTreeFromQueueFind",
    "queue<BTreeNode*>",
    "find_value",
    "on_find_button_clicked",
    "wheelEvent",
    "QWheelEvent*",
    "event"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    0,  115,    2, 0x08,    6 /* Private */,
       8,    1,  116,    2, 0x08,    7 /* Private */,
      10,    0,  119,    2, 0x08,    9 /* Private */,
      11,    0,  120,    2, 0x08,   10 /* Private */,
      12,    1,  121,    2, 0x08,   11 /* Private */,
      15,    1,  124,    2, 0x08,   13 /* Private */,
      18,    2,  127,    2, 0x08,   15 /* Private */,
      18,    2,  132,    2, 0x08,   18 /* Private */,
      15,    1,  137,    2, 0x08,   21 /* Private */,
      21,    0,  140,    2, 0x08,   23 /* Private */,
      22,    1,  141,    2, 0x08,   24 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int,   17,   20,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int,   17,   20,
    QMetaType::Void, 0x80000000 | 19,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_insert_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btree_radio_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bplus_radio_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bstar_radio_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delete_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'max_degree_combo_index_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'resetTrees'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isNumber'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'displayTreeFromQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<queue<BPlusTreeNode*>, std::false_type>,
        // method 'displayTreeFromQueueFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<queue<BTreeNode*>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'displayTreeFromQueueFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<queue<BPlusTreeNode*>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'displayTreeFromQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<queue<BTreeNode*>, std::false_type>,
        // method 'on_find_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wheelEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWheelEvent *, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_insert_button_clicked(); break;
        case 1: _t->on_btree_radio_button_clicked(); break;
        case 2: _t->on_bplus_radio_button_clicked(); break;
        case 3: _t->on_bstar_radio_button_clicked(); break;
        case 4: _t->on_delete_button_clicked(); break;
        case 5: _t->on_clear_button_clicked(); break;
        case 6: _t->max_degree_combo_index_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->resetTrees(); break;
        case 8: _t->clearDisplay(); break;
        case 9: { bool _r = _t->isNumber((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->displayTreeFromQueue((*reinterpret_cast< std::add_pointer_t<queue<BPlusTreeNode*>>>(_a[1]))); break;
        case 11: _t->displayTreeFromQueueFind((*reinterpret_cast< std::add_pointer_t<queue<BTreeNode*>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->displayTreeFromQueueFind((*reinterpret_cast< std::add_pointer_t<queue<BPlusTreeNode*>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->displayTreeFromQueue((*reinterpret_cast< std::add_pointer_t<queue<BTreeNode*>>>(_a[1]))); break;
        case 14: _t->on_find_button_clicked(); break;
        case 15: _t->wheelEvent((*reinterpret_cast< std::add_pointer_t<QWheelEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
