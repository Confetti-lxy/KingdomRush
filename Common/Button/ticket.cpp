#include "ticket.h"


ticket::ticket(QString routineImg, QString activationImg) {
    this->routineImg = routineImg;
    this->activationImg = activationImg;
    QPixmap normalImg;
    bool ret = normalImg.load(routineImg);
    if (!ret) {
        qDebug() << "picture load fail";
        return;
    }
    setFixedSize(normalImg.width(), normalImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(normalImg);
    setIconSize(QSize(normalImg.width(), normalImg.height()));
    show();
}


void ticket::zoomUp() {
    QPropertyAnimation *newAnimation = new QPropertyAnimation(this, "geometry");
    newAnimation->setDuration(500);
    newAnimation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    newAnimation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    newAnimation->setEasingCurve(QEasingCurve::InOutBounce);
    newAnimation->start();
}

void ticket::zoomDown() {
    QPropertyAnimation *newAnimation = new QPropertyAnimation(this, "geometry");
    newAnimation->setDuration(500);
    newAnimation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    newAnimation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    newAnimation->setEasingCurve(QEasingCurve::InOutBounce);
    newAnimation->start();
}

