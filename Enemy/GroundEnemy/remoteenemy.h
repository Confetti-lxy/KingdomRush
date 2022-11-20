#ifndef REMOTEENEMY_H
#define REMOTEENEMY_H

#include "./groundenemy.h"
#include "./Common/Bullet/bullet.h"

class remoteenemy : public groundEnemy {
private:
    bool load() override;

    int bulletStatu;// 子弹发射的状态参数
public:
    QPixmap bulletImg;// 远程子弹的图片素材

    remoteenemy();// 构造函数


    // 功能函数

    void attackAnimation() override;// 攻击动画
    void moveAnimation() override;// 移动动画
    bool judge_defender(defender *d) override;// 选择攻击的defender
    void attack() override;// 攻击函数
};

#endif // REMOTEENEMY_H
