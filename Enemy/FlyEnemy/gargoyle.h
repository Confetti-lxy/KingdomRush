#ifndef GARGOYLE_H
#define GARGOYLE_H

#include "./Enemy/FlyEnemy/flyenemy.h"
#include "./Friend/Tower/tower.h"

class gargoyle : public flyEnemy {
private:
    bool load() override;

    int bulletStatu;// 子弹发射的状态参数
public:
    QPixmap bulletImg;// 远程子弹的图片素材

    gargoyle();// 构造函数

    // 功能函数

    void attackAnimation() override;// 攻击动画
    void moveAnimation() override;// 移动动画
    bool judge_defender(defender *d) override;// 选择攻击的defender
    bool judge_tower(tower *t) override;

    void attack() override;// 攻击函数
};

#endif // GARGOYLE_H
