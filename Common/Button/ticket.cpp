#include "ticket.h"


ticket::ticket(QString routineImg, QString activationImg) {
    this->routineImg = routineImg;
    this->activationImg = activationImg;
    QPixmap normalImg;
    if (!normalImg.load(routineImg)) {
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


void ticket::press(QMouseEvent *event) {
    if (activationImg != "") {
        QPixmap pix;
        if (!pix.load(activationImg)) {
            qDebug() << "picture load fail";
            return;
        }
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:Opx;}");
        setIcon(pix);
        setIconSize(QSize(pix.width(), pix.height()));
    }
    return mousePressEvent(event);
}


void ticket::release(QMouseEvent *event) {
    if (activationImg != "") {
        QPixmap pix;
        if (!pix.load(routineImg)) {
            qDebug() << "picture load fail";
            return;
        }
        setFixedSize(pix.width(), pix.height());
        setStyleSheet("QPushButton{border:Opx;}");
        setIcon(pix);
        setIconSize(QSize(pix.width(), pix.height()));
    }
    return mouseReleaseEvent(event);
}






















