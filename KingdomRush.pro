QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Blood/blood.cpp \
    Common/Bullet/bullet.cpp \
    Common/Button/architecture.cpp \
    Common/Button/build.cpp \
    Common/Button/deploy.cpp \
    Common/Button/ticket.cpp \
    Common/common.cpp \
    Enemy/EnemyState/enemystate.cpp \
    Enemy/FlyEnemy/flyenemy.cpp \
    Enemy/FlyEnemy/gargoyle.cpp \
    Enemy/FlyEnemy/raptor.cpp \
    Enemy/GroundEnemy/barbarian.cpp \
    Enemy/GroundEnemy/groundenemy.cpp \
    Enemy/GroundEnemy/remoteenemy.cpp \
    Enemy/enemy.cpp \
    Friend/Defender/defender.cpp \
    Friend/Defender/dragon.cpp \
    Friend/Defender/guard.cpp \
    Friend/Defender/soldier.cpp \
    Friend/Tower/arrowtower.cpp \
    Friend/Tower/firetower.cpp \
    Friend/Tower/mercenarytower.cpp \
    Friend/Tower/range.cpp \
    Friend/Tower/tower.cpp \
    Level/level.cpp \
    Map/map.cpp \
    Map/road.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Common/Blood/blood.h \
    Common/Bullet/bullet.h \
    Common/Button/architecture.h \
    Common/Button/build.h \
    Common/Button/deploy.h \
    Common/Button/ticket.h \
    Common/common.h \
    Enemy/EnemyIntegration.h \
    Enemy/EnemyState/enemystate.h \
    Enemy/FlyEnemy/flyenemy.h \
    Enemy/FlyEnemy/gargoyle.h \
    Enemy/FlyEnemy/raptor.h \
    Enemy/GroundEnemy/barbarian.h \
    Enemy/GroundEnemy/groundenemy.h \
    Enemy/GroundEnemy/remoteenemy.h \
    Enemy/enemy.h \
    Friend/Defender/defender.h \
    Friend/Defender/dragon.h \
    Friend/Defender/guard.h \
    Friend/Defender/soldier.h \
    Friend/FriendIntegration.h \
    Friend/Tower/arrowtower.h \
    Friend/Tower/firetower.h \
    Friend/Tower/mercenarytower.h \
    Friend/Tower/range.h \
    Friend/Tower/tower.h \
    Level/level.h \
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

RESOURCES += \
    image/image.qrc \
    mapfile/file.qrc
