QT       += core gui\
            network\
            sensors\
            positioning\
            widgets printsupport\


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ANDROID
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += main.cpp\
        mainwindow.cpp \
        accelhandler.cpp \
        client.cpp

HEADERS  += mainwindow.h \
            accelhandler.h \
            client.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY =
