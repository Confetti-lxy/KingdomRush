#ifndef LEVEL_H
#define LEVEL_H

#include "./Map/map.h"
#include "./Map/road.h"
#include "./Enemy/EnemyIntegration.h"
#include "./Friend/FriendIntegration.h"

class level : public QWidget {
    Q_OBJECT
private:
    QVector<enemy *> AllEnemy;// 地图中所有敌人的集合
    QVector<defender *> AllDefender;// 地图中所有友方近战单位的集合
    QVector<tower *> AllTower;// 地图中所有友方防御塔的集合

    defender *soldierModel, *guardModel, *dragonModel;//近战单位的3个实例单位

    Map *my_map;// 依赖的上层地图
    levelLabel labels;// 界面相关的标签组件
    levelButton buttons;// 界面相关的按钮组件
    QTimer *timer0, *timer1, *timer2;// 时间控制的组件，与出怪，跳钱相关

    int existLife;// 人物剩余生命

    bool isOver, isWin;// 判断是否胜利，是否游戏结束
    bool isDoubleSpeed;// 判断是否为二倍速


    void FriDefenderInit();// 3个友方defender单位的初始化
    void labelInit();// 标签组件的初始化
    void buttonInit();// 按钮组件的初始化
public:
    level();// 基础的构造函数，可忽略不计
    level(int Level);// Level为关卡等级

    // 功能函数

    void makeWar();//
    void gameStart();//
    void restart();//

    signals:
            void levelBack();

    void levelAgain();
};


#endif // LEVEL_H




























