#include "build.h"


build::build(QWidget *page) {
    // 上层页面的设置
    this->page = page;

    // 图片素材的加载
    if (!RemoteCellImg.load(":/image/remote_cell.png")) {
        qDebug() << "picture loaded failed";
        return;
    }
    if (!CircleImg.load(":/image/circle.png")) {
        qDebug() << "picture loaded failed";
        return;
    }
    // 边框圈的图片素材的加载
    Circle = new QLabel;
    Circle->hide();
    Circle->setParent(page);
    Circle->setFixedSize(CircleImg.width(), CircleImg.height());
    Circle->setStyleSheet("QPushButton{border:Opx;}");
    Circle->setPixmap(CircleImg);
    Circle->setBaseSize(QSize(CircleImg.width(), CircleImg.height()));
    Circle->setAttribute(Qt::WA_TransparentForMouseEvents);
    SetIcon(RemoteCellImg);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    show();
    // 3种防御塔单位的图片素材的加载
    architectures[0] = new architecture(":/image/tower1_btn.png");
    architectures[1] = new architecture(":/image/tower2_btn.png");
    architectures[2] = new architecture(":/image/tower3_btn.png");
    for (auto architecture: architectures) {
        architecture->setParent(page);
        architecture->hide();
    }
}

void build::PressEvent(int x, int y) {
    if (state) {
        if (isClicked) {
            isClicked = false;
            Circle->hide();
            for (auto architecture: architectures) {
                architecture->hide();
            }
        } else {
            if (x >= this->x() && x <= this->x() + this->width()
                && y >= this->y() && y <= this->y() + this->height()) {
                double x_ = this->x() + 0.5 * (this->width() - Circle->width()),
                        y_ = this->y() + 0.5 * (this->height() - Circle->height());
                Circle->move(int(x_), int(y_));
                Circle->show();
                Circle->raise();
                // 参数待定
                architectures[0]->move(Circle->x() + 47, Circle->y() + 2);
                architectures[1]->move(Circle->x() + 85, Circle->y() + 55);
                architectures[2]->move(Circle->x() + 9, Circle->y() + 55);
                for (auto architecture: architectures) {
                    architecture->show();
                    architecture->raise();
                }
                isClicked = true;
            }
        }
    }
}
