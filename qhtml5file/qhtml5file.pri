INCLUDEDIR+=$$PWD

HEADERS += $$PWD/qhtml5file.h
wasm {
    SOURCES += $$PWD/qhtml5file_html5.cpp 
} else {
    SOURCES += $$PWD/qhtml5file.cpp
}

HEADERS += $$PWD/qhtmlfileaccess.h
SOURCES += $$PWD/qhtmlfileaccess.cpp
