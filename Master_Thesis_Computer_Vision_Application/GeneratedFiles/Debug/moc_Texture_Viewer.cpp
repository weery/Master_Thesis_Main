/****************************************************************************
** Meta object code from reading C++ file 'Texture_Viewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenGL/Texture_Viewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Texture_Viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenGL__Texture_Viewer_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenGL__Texture_Viewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenGL__Texture_Viewer_t qt_meta_stringdata_OpenGL__Texture_Viewer = {
    {
QT_MOC_LITERAL(0, 0, 22), // "OpenGL::Texture_Viewer"
QT_MOC_LITERAL(1, 23, 22), // "ChangeBenchmarkTexture"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 3), // "rgb"
QT_MOC_LITERAL(4, 51, 7), // "OnClose"
QT_MOC_LITERAL(5, 59, 10) // "OnCloseAll"

    },
    "OpenGL::Texture_Viewer\0ChangeBenchmarkTexture\0"
    "\0rgb\0OnClose\0OnCloseAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenGL__Texture_Viewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OpenGL::Texture_Viewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Texture_Viewer *_t = static_cast<Texture_Viewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeBenchmarkTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->OnClose(); break;
        case 2: _t->OnCloseAll(); break;
        default: ;
        }
    }
}

const QMetaObject OpenGL::Texture_Viewer::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_OpenGL__Texture_Viewer.data,
      qt_meta_data_OpenGL__Texture_Viewer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OpenGL::Texture_Viewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenGL::Texture_Viewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGL__Texture_Viewer.stringdata0))
        return static_cast<void*>(const_cast< Texture_Viewer*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int OpenGL::Texture_Viewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
