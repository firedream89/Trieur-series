/****************************************************************************
** Meta object code from reading C++ file 'principal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TSeries/principal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'principal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_principal_t {
    QByteArrayData data[18];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_principal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_principal_t qt_meta_stringdata_principal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "principal"
QT_MOC_LITERAL(1, 10, 9), // "Parcourir"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "Suppression"
QT_MOC_LITERAL(4, 33, 1), // "l"
QT_MOC_LITERAL(5, 35, 1), // "c"
QT_MOC_LITERAL(6, 37, 7), // "Edition"
QT_MOC_LITERAL(7, 45, 10), // "Traitement"
QT_MOC_LITERAL(8, 56, 4), // "lien"
QT_MOC_LITERAL(9, 61, 12), // "Modification"
QT_MOC_LITERAL(10, 74, 5), // "ligne"
QT_MOC_LITERAL(11, 80, 7), // "colonne"
QT_MOC_LITERAL(12, 88, 11), // "Application"
QT_MOC_LITERAL(13, 100, 12), // "Application2"
QT_MOC_LITERAL(14, 113, 7), // "listing"
QT_MOC_LITERAL(15, 121, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 138, 5), // "nItem"
QT_MOC_LITERAL(17, 144, 12) // "AutoOrganise"

    },
    "principal\0Parcourir\0\0Suppression\0l\0c\0"
    "Edition\0Traitement\0lien\0Modification\0"
    "ligne\0colonne\0Application\0Application2\0"
    "listing\0QTreeWidgetItem*\0nItem\0"
    "AutoOrganise"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_principal[] = {

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
       1,    0,   64,    2, 0x08 /* Private */,
       3,    2,   65,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       9,    2,   74,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    2,   81,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x28 /* Private | MethodCloned */,
      17,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 15, QMetaType::QString, 0x80000000 | 15,    8,   16,
    0x80000000 | 15, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void principal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        principal *_t = static_cast<principal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Parcourir(); break;
        case 1: _t->Suppression((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->Edition(); break;
        case 3: _t->Traitement((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Modification((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->Application(); break;
        case 6: _t->Application2(); break;
        case 7: { QTreeWidgetItem* _r = _t->listing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QTreeWidgetItem**>(_a[0]) = _r; }  break;
        case 8: { QTreeWidgetItem* _r = _t->listing((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTreeWidgetItem**>(_a[0]) = _r; }  break;
        case 9: _t->AutoOrganise(); break;
        default: ;
        }
    }
}

const QMetaObject principal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_principal.data,
      qt_meta_data_principal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *principal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *principal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_principal.stringdata0))
        return static_cast<void*>(const_cast< principal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int principal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
