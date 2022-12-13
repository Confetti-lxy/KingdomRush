#include "ticket.h"


ticket::ticket(QString routineImg, QString activationImg) {
    this->routineImg = routineImg;
    this->activationImg = activationImg;
    if (!normalImg.load(routineImg)) {
        qDebug() << "picture load fail";
        return;
    }
    SetIcon(normalImg);
    show();
}

void ticket::zoom() {
    QPropertyAnimation *newAnimation = new QPropertyAnimation(this, "geometry");
    newAnimation->setDuration(500);
    newAnimation->setStartValue(QRect(this->x(), this->y() + 20, this->width(), this->height()));
    newAnimation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    newAnimation->setEasingCurve(QEasingCurve::InOutBounce);
    newAnimation->start();
    newAnimation = new QPropertyAnimation(this, "geometry");
    newAnimation->setDuration(500);
    newAnimation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    newAnimation->setEndValue(QRect(this->x(), this->y() + 20, this->width(), this->height()));
    newAnimation->setEasingCurve(QEasingCurve::InOutBounce);
    newAnimation->start();
}
void ticket::press(QMouseEvent *event) {
    if (activationImg != "") {
        if (!specialImg.load(activationImg)) {
            qDebug() << "picture load fail";
            return;
        }
        SetIcon(specialImg);
    }
    return QPushButton::mousePressEvent(event);
}

void ticket::release(QMouseEvent *event) {
    if (activationImg != "") {
        if (!normalImg.load(routineImg)) {
            qDebug() << "picture load fail";
            return;
        }
        SetIcon(normalImg);
    }
    return QPushButton::mouseReleaseEvent(event);
}
