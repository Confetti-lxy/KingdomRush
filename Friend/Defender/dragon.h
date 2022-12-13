#ifndef DRAGON_H
#define DRAGON_H

#include "defender.h"

class dragon : public defender {
private:
    bool load() override;
public:
    dragonImage dragonImg;// 龙的图片资源

    dragon();// 构造函数

    // 功能函数
    void attackAnimation(enemy *blockedEnemy) override;// 攻击动画
    void attack() override;// 攻击敌人
    bool add_enemy(enemy *e) override;// 添加阻挡的敌人
    // 鼠标动作，相关的部署函数
    bool location_check(QMouseEvent *click) override;// 位置检查
};

#endif // DRAGON_H
