QT += core opengl widgets
QT -= gui

CONFIG += c++11

TARGET = QOGL3DModelViewer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    glwidget.cpp \
    mesh.cpp \
    Interaction/camera.cpp \
    Loader/modelloader.cpp

HEADERS += \
    glwidget.h \
    mesh.h \
    Interaction/camera.h \
    Loader/modelloader.h

DISTFILES += \
    Shader/program.frag \
    Shader/program.vert

RESOURCES += \
    resource.qrc
