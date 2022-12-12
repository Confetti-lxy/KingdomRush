#ifndef TOWERSTATE_H
#define TOWERSTATE_H

#include "./Common/common.h"
#include "./Friend/Tower/tower.h"

class tower;

class towerState:public QLabel
{
private:
    tower* buffTower;// 受到增幅的塔单位
    QPixmap buffImage;// 增幅状态的显示
public:
    TowerBuff Type;// buff的类型
    towerState(tower * t, TowerBuff b);// 构造函数
};

#endif // TOWERSTATE_H
