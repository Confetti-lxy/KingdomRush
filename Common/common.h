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
#include <QCoreApplication>
#include <QSoundEffect>


//-------------------------------------------------------------------------------------
// 常用的宏，用于减少代码量

// 图片设置1
#define SetIcon(pix)\
    setFixedSize(pix.width(),pix.height());\
    setStyleSheet("QPushButton{border:Opx;}");\
    setIcon(pix);\
    setIconSize(QSize(pix.width(),pix.height()));

// 图片设置2
#define SetBase(pix)\
    setFixedSize(pix.width(),pix.height());\
    setStyleSheet("QPushButton{border:Opx;}");\
    setPixmap(pix);\
    setBaseSize(QSize(pix.width(),pix.height()));

// 图片设置3
#define pointerSet(pointer, x, y)\
    pointer = new QLabel;\
    pointer->setParent(this);\
    pointer->setPixmap(pix);\
    pointer->move(x,y);\
    pointer->setFixedSize(pix.width(),pix.height());

// defender单位的初始化宏定义，包含单位初始化，按钮设置以及链接,主要应用于level.cpp
#define defenderInit(pointer, x, y, m, n)\
    pointer->set_map(my_map);\
    pointer->setParent(this);\
    pointer->move(x, y);\
    pointer->show();\
    pointer->get_deploy()->setParent(this);\
    pointer->get_deploy()->show();\
    pointer->get_deploy()->move(m,n);\
    connect(pointer->get_deploy(), &deploy::click_deploy, \
            pointer, &defender::defenderDeploy);\
    connect(pointer->get_deploy(), &deploy::release_deploy, \
            pointer,&defender::mouseReleaseEvent);

// 指针指向的Button单位的具体化
#define pointerSetIcon(pointer)\
    pointer= new QPushButton;\
    pointer->setParent(this);\
    pointer->setIcon(pix);\
    pointer->setFixedSize(pix.width(),pix.height());\
    pointer->setStyleSheet("QPushButton{border:0px;}");\
    pointer->setIconSize(QSize(pix.width(),pix.height()));\
    pointer->hide();

// 关卡链接
#define levelConnect(L)\
    connect(this, &Widget::openLevel, L, &level::gameStart);\
    connect(L, &level::levelBack, this, [=]() {\
        L->hide();\
        delete L;\
        this->show();\
        status->show();\
    });\
    this->hide();\
    L->show();\
    emit openLevel();\

// 成功和失败见面的跳转
#define FaceBounce(page)\
    page->show();\
    page->move(labels.victoryInterface->x(),-434);\
    QPropertyAnimation *animation=new QPropertyAnimation(page,"geometry");\
    animation->setDuration(1000);\
    animation->setStartValue(QRect(QPoint(page->x(),page->y()),QPoint(page->x()+page->width(),page->height())));\
    animation->setEndValue(QRect(QPoint(page->x(),page->y()+500),QPoint(page->x()+page->width(),page->height()+120)));\
    animation->setEasingCurve(QEasingCurve::OutBounce);\
    animation->start();


// 用于词条效果结束后进行删除
#define deleteState(s, type)\
    for(auto it = s.begin();it!=s.end();it++) {\
        if((*it)->Type == type) {\
            states.erase(it);\
            if(it == s.end()) break;\
        }\
    }\

// 用于文字QLabel的加载
#define draw(img,x,y)\
    img = new QLabel;\
    img ->setParent(this);\
    img ->move(x, y);\
    img ->setFixedSize(pix.width(), pix.height());\
    img ->setBaseSize(QSize(pix.width(), pix.height()));\
    img ->raise();

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// 各类集合体，用于描述各类参数
enum direction_type {
    d_left,
    d_right,
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
    Gargoyle,
    Raptor,
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

enum EnemyBuff {
    Flash,
    Speed,
    Powered,
};// 敌方单位的buff增益

enum TowerBuff {
    Bleeding,
};// 友方防御塔单位的buff增益

enum DefenderBuff {
    Berserk,
    Glacial,
    MassInjured,
};// 友方近战单位的buff增益
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// 各类结构体
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

struct flyEnemyImage {
    QPixmap enemyleft1_Img;
    QPixmap enemyleft2_Img;
    QPixmap enemyleft3_Img;
    QPixmap enemyleft4_Img;
    QPixmap enemyright1_Img;
    QPixmap enemyright2_Img;
    QPixmap enemyright3_Img;
    QPixmap enemyright4_Img;
};// 飞行敌人的图片素材

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
    QLabel *berserk;//显示是否存有berserk词条
    QLabel *glacial;//显示是否存有glacial词条
    QLabel *massInjured;//显示是否存有massInjured词条
    QLabel *bleeding;//显示是否存有bleeding词条
};// level里面的标签组件

struct levelButton {
    QPushButton *reopen;// 重新开始
    QPushButton *back;// 返回到选地图的界面
};// level里面的按钮组件

//-------------------------------------------------------------------------------------

#endif // COMMON_H
