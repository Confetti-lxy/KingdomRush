#ifndef RAPTOR_H
#define RAPTOR_H

#include "./Enemy/FlyEnemy/flyenemy.h"
#include "./Friend/Tower/tower.h"
#include "./Common/Bullet/bullet.h"

class raptor : public flyEnemy {
private:
    bool load() override;

    int bulletStatu;// 子弹发射的状态参数

    int imageCount = 0;// 该单位此时处于哪个图片上
public:
    QPixmap bulletImg;// 远程子弹的图片素材

    raptor();// 构造函数

    // 功能函数
    void attackAnimation() override;// 攻击动画
    void moveAnimation() override;// 移动动画
    bool judge_defender(defender *d) override;// 选择攻击的defender
    void attack() override;// 攻击函数
};

#endif // RAPTOR_H
