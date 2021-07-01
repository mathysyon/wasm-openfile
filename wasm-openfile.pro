TEMPLATE = app
QT += core gui widgets
TARGET = wasm-openfile
SOURCES += main.cpp \
    mainwindow.cpp
CONFIG += console
HEADERS += qhtml5file/qhtmlfileaccess.h \
    mainwindow.h
SOURCES += qhtml5file/qhtmlfileaccess.cpp qhtml5file/qhtml5file_html5.cpp

FORMS += \
    mainwindow.ui
