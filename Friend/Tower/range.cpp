#include "range.h"

range::range() {
    setFixedSize(1000, 1000);
}

void range::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QColor color("#AAAAAA");
    color.setAlpha(100);
    QBrush brush(color);
    painter.setBrush(brush);
    painter.drawEllipse(x_r - 0.5 * r, y_r - 0.5 * r, r, r);
}
