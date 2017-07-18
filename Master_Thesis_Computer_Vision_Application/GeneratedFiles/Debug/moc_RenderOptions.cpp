/****************************************************************************
** Meta object code from reading C++ file 'RenderOptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenGL/RenderOptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderOptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenGL__RenderOptions_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenGL__RenderOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenGL__RenderOptions_t qt_meta_stringdata_OpenGL__RenderOptions = {
    {
QT_MOC_LITERAL(0, 0, 21), // "OpenGL::RenderOptions"
QT_MOC_LITERAL(1, 22, 20), // "RenderOptionsUpdated"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 22), // "ChangeBenchmarkTexture"
QT_MOC_LITERAL(4, 67, 3), // "rgb"
QT_MOC_LITERAL(5, 71, 17), // "ChangeTextureName"
QT_MOC_LITERAL(6, 89, 11), // "textureName"
QT_MOC_LITERAL(7, 101, 10), // "setChannel"
QT_MOC_LITERAL(8, 112, 7), // "toggled"
QT_MOC_LITERAL(9, 120, 16) // "useThreeChannels"

    },
    "OpenGL::RenderOptions\0RenderOptionsUpdated\0"
    "\0ChangeBenchmarkTexture\0rgb\0"
    "ChangeTextureName\0textureName\0setChannel\0"
    "toggled\0useThreeChannels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGL__RenderOptions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void OpenGL::RenderOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderOptions *_t = static_cast<RenderOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RenderOptionsUpdated(); break;
        case 1: _t->ChangeBenchmarkTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ChangeTextureName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setChannel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->useThreeChannels((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RenderOptions::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptions::RenderOptionsUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OpenGL::RenderOptions::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OpenGL__RenderOptions.data,
      qt_meta_data_OpenGL__RenderOptions,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OpenGL::RenderOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenGL::RenderOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGL__RenderOptions.stringdata0))
        return static_cast<void*>(const_cast< RenderOptions*>(this));
    return QObject::qt_metacast(_clname);
}

int OpenGL::RenderOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void OpenGL::RenderOptions::RenderOptionsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
