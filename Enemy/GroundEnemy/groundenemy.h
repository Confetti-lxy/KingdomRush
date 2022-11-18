#ifndef GROUNDENEMY_H
#define GROUNDENEMY_H

#include "Enemy/enemy.h"


class groundEnemy : public enemy {
private:
    virtual bool load() = 0;

public:
    groundEnemyImage enemyImage;//敌人的图片素材

    groundEnemy();//构造函数


    //功能函数

    // 虚函数，在子类中细化
    virtual void attackAnimation() = 0; // 攻击动画
    virtual void moveAnimation() = 0;// 移动动画
    virtual bool judge_defender(defender *d) = 0;// 选择攻击的defender
    virtual void attack() = 0;// 攻击函数

    // 实函数，在所有子类中共用
    void enemyMove(int road_loc, int step);// 地面敌人的移动
    void Lock_defender();//锁定敌人


};

#endif // GROUNDENEMY_H
