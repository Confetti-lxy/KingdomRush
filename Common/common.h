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
#include <QTime>
#include <QBrush>
#include <QPainter>
#include <QImage>
#include <QIcon>

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
    Remoteenemy,
    fly_enemy_01,
    fly_enemy_02,
};// 敌方种类

enum DefenderType {
    Soldier,
    Guard,
    Dragon,
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

struct dragonImage {
    QPixmap dragonImg;
    QPixmap dragonBtnImg;
    QPixmap dragonattackleft1_Img;
    QPixmap dragonattackright1_Img;
    QPixmap dragonattackleft2_Img;
    QPixmap dragonattackright2_Img;
    QPixmap dragonattackleft3_Img;
    QPixmap dragonattackright3_Img;
    QPixmap dragonattackleft4_Img;
    QPixmap dragonattackright4_Img;
};// dragon单位的图片素材

struct levelLabel {
    QLabel *moneyLabel;// 钱的计量槽
    QLabel *moneyNum;// 钱的数量
    QLabel *lifeLabel;// 生命的计量槽
    QLabel *lifeNum;// 生命的数量
    QLabel *victoryInterface;// 胜利界面
    QLabel *failureInterface;// 失败界面
    QLabel *oneSpeed;// 一倍速的标签
    QLabel *doubleSpeed;// 两倍速的标签
};// level里面的标签组件

struct levelButton {
    QPushButton *reopen;// 重新开始
    QPushButton *back;// 返回到选地图的界面
};// level里面的按钮组件

#endif // COMMON_H













