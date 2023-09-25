QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp
    QTreeWidgetXmlItem.cpp

HEADERS += \
    mainwindow.h
    QTreeWidgetXmlItem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-ltinyxml2-Desktop-Debug/release/ -lltinyxml2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-ltinyxml2-Desktop-Debug/debug/ -lltinyxml2
else:unix: LIBS += -L$$PWD/../build-ltinyxml2-Desktop-Debug/ -lltinyxml2

INCLUDEPATH += $$PWD/../build-ltinyxml2-Desktop-Debug
DEPENDPATH += $$PWD/../build-ltinyxml2-Desktop-Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-ltinyxml2-Desktop-Debug/release/libltinyxml2.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-ltinyxml2-Desktop-Debug/debug/libltinyxml2.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-ltinyxml2-Desktop-Debug/release/ltinyxml2.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-ltinyxml2-Desktop-Debug/debug/ltinyxml2.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-ltinyxml2-Desktop-Debug/libltinyxml2.a
