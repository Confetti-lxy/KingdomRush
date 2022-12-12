#include "blood.h"

blood::blood() {
    setFixedSize(300, 5);
    color.setNamedColor("#F20900");
}

void blood::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QBrush brush(color);// 刷子为红色
    painter.setBrush(brush);
    painter.drawRect(this->x() + t, this->y() - 5, len, 100);
}
