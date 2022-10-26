QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Button/architecture.cpp \
    Common/Button/build.cpp \
    Common/Button/ticket.cpp \
    Common/common.cpp \
    Enemy/enemy.cpp \
    Map/map.cpp \
    Map/road.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Common/Button/architecture.h \
    Common/Button/build.h \
    Common/Button/ticket.h \
    Common/common.h \
    Enemy/enemy.h \
    Map/map.h \
    Map/road.h \
    widget.h

FORMS += \
    widget.ui

TRANSLATIONS += \
    KingdomRush_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
