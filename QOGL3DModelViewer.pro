QT += core opengl widgets
QT -= gui

CONFIG += c++11

TARGET = QOGL3DModelViewer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lassimp

SOURCES += main.cpp \
    glwidget.cpp \
    mesh.cpp \
    Interaction/camera.cpp \
    Loader/modelloader.cpp \
    Loader/parser.cpp \
    Interaction/menu.cpp

HEADERS += \
    glwidget.h \
    mesh.h \
    Interaction/camera.h \
    Loader/modelloader.h \
    Loader/parser.h \
    Interaction/menu.h

DISTFILES += \
    Shader/program.frag \
    Shader/program.vert

RESOURCES += \
    resource.qrc

FORMS += \
    Interaction/menu.ui
