QT       += core gui
QT       += opengl

QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    jl_thread.cpp \
    julia_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    mb_thread.cpp \
    mb_widget2.cpp

HEADERS += \
    jl_thread.h \
    julia_widget.h \
    mainwindow.h \
    mb_thread.h \
    mb_widget2.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
