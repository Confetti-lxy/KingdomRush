#ifndef COMMON_H
#define COMMON_H

#include <bits/stdc++.h>

using namespace std;

#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QFile>
#include <QTimer>
#include <QPainter>
#include <QImage>

// 图片设置1
#define set(pix)\
setFixedSize(pix.width(),pix.height());\
setStyleSheet("QPushButton{border:Opx;}");\
setIcon(pix);\
setIconSize(QSize(pix.width(),pix.height()));

// 图片设置2
#define setBase(pix)\
setFixedSize(pix.width(),pix.height());\
setStyleSheet("QPushButton{border:Opx;}");\
setPixmap(pix);\
setBaseSize(QSize(pix.width(),pix.height()));

enum direction_type {
    d_right,
    d_left,
    d_front,
    d_back
};//敌人的行进方向

enum road_type {
    ground_road,
    fly_road,
    stone_road
};//路线种类

enum cell_type {
    remote_cell,
    stone_cell,
    close_cell,
    start_cell,
    end_cell
};// 地块种类

enum EnemyType {
    Barbarian,
    ground_enemy_02,
    fly_enemy_01,
    fly_enemy_02,
};// 敌方种类

enum DefenderType {
    Soldier,
    Defender_02,
    Defender_03,
};// 友方近战单位的种类

enum EnemyDirection {
    e_left,
    e_right,
    e_front,
    e_back,
};// 敌方面朝方向


struct groundEnemyImage {
    QPixmap enemyleft1_Img;
    QPixmap enemyleft2_Img;
    QPixmap enemyright1_Img;
    QPixmap enemyright2_Img;
    QPixmap enemyattackleft1_Img;
    QPixmap enemyattackleft2_Img;
    QPixmap enemyattackright1_Img;
    QPixmap enemyattackright2_Img;
};// 地面敌人的图片素材

struct defenderImage {
    QPixmap soldierImg;
    QPixmap soldierBtnImg;
    QPixmap soldierattackleft1_Img;
    QPixmap soldierattackright1_Img;
    QPixmap soldierattackleft2_Img;
    QPixmap soldierattackright2_Img;
};// soldier单位的图片素材

#endif // COMMON_H
