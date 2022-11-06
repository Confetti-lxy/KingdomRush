#ifndef GROUNDENEMY_H
#define GROUNDENEMY_H

#include "Enemy/enemy.h"


class groundEnemy : public enemy {
private:
    virtual void load() = 0;

public:
    groundEnemyImage enemyImage;

    groundEnemy();

    void enemyMove(int road_loc, int step);// 移动

    void Lock_defender();//锁定敌人

    virtual void attackAnimation() = 0; // 攻击动画

    virtual void moveAnimation() = 0;// 移动动画
};

#endif // GROUNDENEMY_H
