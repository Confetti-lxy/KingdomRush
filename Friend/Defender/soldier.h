#ifndef SOLDIER_H
#define SOLDIER_H

#include "defender.h"


class soldier : public defender {
private:
    bool load() override;
public:
    defenderImage defenderImg; // 战士的图片资源
    soldier();    // 构造函数

    // 功能函数
    void attackAnimation(enemy *blockedEnemy) override;// 攻击动画
    void attack() override;// 攻击敌人
    // 鼠标动作，相关的部署函数
    bool location_check(QMouseEvent *click) override;// 位置检查
};

#endif // SOLDIER_H
