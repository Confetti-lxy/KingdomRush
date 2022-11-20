#ifndef BULLET_H
#define BULLET_H

#include "./Common/common.h"

class bullet : public QLabel {
public:
    QPixmap bulletImg;// bullet的图片素材

    bullet(QPixmap bulletImg);// 构造函数

    void ballistic(QLabel *target);// 子弹飞行攻击目标
};

#endif // BULLET_H
