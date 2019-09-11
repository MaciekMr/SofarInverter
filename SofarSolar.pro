QT += core gui widgets


CONFIG += c++17


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += -fconcepts
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        configmodel.cpp \
        configwindow.cpp \
        connector.cpp \
        datacollector.cpp \
        inverter.cpp \
        logwindow.cpp \
        main.cpp \
        mainmenu.cpp \
        mainwindow.cpp \
        threadset.cpp \
        timer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    configmodel.h \
    configwindow.h \
    connector.h \
    datacollector.h \
    inverter.h \
    logwindow.h \
    mainmenu.h \
    mainwindow.h \
    threadset.h \
    timer.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/release/ -lboost_filesystem-gcc9-mt-x64-1_70
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/debug/ -lboost_filesystem-gcc9-mt-x64-1_70
else:unix: LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/ -lboost_filesystem-gcc9-mt-x64-1_70

INCLUDEPATH += $$PWD/../../../../usr/local/boost_1.70/include
DEPENDPATH += $$PWD/../../../../usr/local/boost_1.70/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/release/ -lboost_iostreams-gcc9-mt-x64-1_70
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/debug/ -lboost_iostreams-gcc9-mt-x64-1_70
else:unix: LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/ -lboost_iostreams-gcc9-mt-x64-1_70

INCLUDEPATH += $$PWD/../../../../usr/local/boost_1.70/include
DEPENDPATH += $$PWD/../../../../usr/local/boost_1.70/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/release/ -lboost_serialization-gcc9-mt-x64-1_70
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/debug/ -lboost_serialization-gcc9-mt-x64-1_70
else:unix: LIBS += -L$$PWD/../../../../usr/local/boost_1.70/lib/ -lboost_serialization-gcc9-mt-x64-1_70

INCLUDEPATH += $$PWD/../../../../usr/local/boost_1.70/include
DEPENDPATH += $$PWD/../../../../usr/local/boost_1.70/include
