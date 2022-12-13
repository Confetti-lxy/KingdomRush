#ifndef BULLET_H
#define BULLET_H

#include "./Common/common.h"

class bullet : public QLabel {
private:
    QPixmap bulletImg;// bullet的图片素材

    QTimer *bulletTimer;// 时间计时器
public:
    bullet(QPixmap bulletImg);// 构造函数

    void ballistic(QLabel *target);// 子弹飞行攻击目标
};

#endif // BULLET_H
