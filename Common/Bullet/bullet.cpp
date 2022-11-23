#include "bullet.h"

bullet::bullet(QPixmap bulletImg) {
    this->bulletImg = bulletImg;
    SetBase(this->bulletImg);
    this->hide();
}


void bullet::ballistic(QLabel *target) {
    QTimer *t = new QTimer;
    t->start(100);
    connect(t, &QTimer::timeout, [=]() {
        int x_ = x() - (target->x() + 0.5 * target->width() + 20);
        int y_ = y() - (target->y() + 0.5 * target->height());
        double distance = sqrt(x_ * x_ + y_ * y_);
        if (distance <= 30) {
            this->hide();
        } else {
            this->move(x() - 30 * x_ / distance, y() - 30 * y_ / distance);
        }
    });
}




















