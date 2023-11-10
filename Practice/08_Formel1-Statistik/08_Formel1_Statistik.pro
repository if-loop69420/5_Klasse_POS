QT       += core gui charts
include(../../QxOrm_1.4.9/QxOrm/QxOrm.pri)


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

INCLUDEPATH += ../../QxOrm_1.4.9/QxOrm/include/
LIBS += -L"../../QxOrm_1.4.9/QxOrm/lib" -lQxOrmd

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += _BUILDING_QX_FORMULA_ONE
PRECOMPILED_HEADER = precompiled.h

SOURCES += \
    constructors.cpp \
    driver.cpp \
    main.cpp \
    mainwindow.cpp \
    races.cpp \
    results.cpp


HEADERS += \
    constructors.h \
    driver.h \
    export.h \
    mainwindow.h \
    precompiled.h \
    races.h \
    results.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
