/****************************************************************************
** Meta object code from reading C++ file 'videoroute.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../videoroute.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoroute.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoRoute_t {
    QByteArrayData data[14];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoRoute_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoRoute_t qt_meta_stringdata_VideoRoute = {
    {
QT_MOC_LITERAL(0, 0, 10), // "VideoRoute"
QT_MOC_LITERAL(1, 11, 12), // "update_video"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "frame"
QT_MOC_LITERAL(4, 31, 1), // "k"
QT_MOC_LITERAL(5, 33, 12), // "update_route"
QT_MOC_LITERAL(6, 46, 5), // "start"
QT_MOC_LITERAL(7, 52, 3), // "end"
QT_MOC_LITERAL(8, 56, 13), // "update_cursor"
QT_MOC_LITERAL(9, 70, 17), // "update_route_data"
QT_MOC_LITERAL(10, 88, 18), // "update_route_reset"
QT_MOC_LITERAL(11, 107, 6), // "number"
QT_MOC_LITERAL(12, 114, 4), // "save"
QT_MOC_LITERAL(13, 119, 4) // "play"

    },
    "VideoRoute\0update_video\0\0frame\0k\0"
    "update_route\0start\0end\0update_cursor\0"
    "update_route_data\0update_route_reset\0"
    "number\0save\0play"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoRoute[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    3,   54,    2, 0x08 /* Private */,
       8,    3,   61,    2, 0x08 /* Private */,
       9,    3,   68,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      12,    0,   78,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VideoRoute::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoRoute *_t = static_cast<VideoRoute *>(_o);
        switch (_id) {
        case 0: _t->update_video((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->update_route((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->update_cursor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->update_route_data((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->update_route_reset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->save(); break;
        case 6: _t->play(); break;
        default: ;
        }
    }
}

const QMetaObject VideoRoute::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoRoute.data,
      qt_meta_data_VideoRoute,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoRoute::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoRoute::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoRoute.stringdata))
        return static_cast<void*>(const_cast< VideoRoute*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoRoute::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
