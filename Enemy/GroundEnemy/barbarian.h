#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "groundenemy.h"


class barbarian : public groundEnemy {
private:
    bool load() override;

public:
    barbarian(); // 构造函数


    // 功能函数

    void attackAnimation() override;// 攻击动画
    void moveAnimation() override;// 移动动画
    bool judge_defender(defender *d) override;// 选择攻击的defender
    void attack() override;// 攻击函数
};

#endif // BARBARIAN_H
