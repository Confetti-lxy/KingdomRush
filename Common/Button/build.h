#ifndef BUILD_H
#define BUILD_H

#include "architecture.h"


class build : public QPushButton {

private:
    QPixmap RemoteCellImg, CircleImg;
    QLabel *Circle;
    QWidget *page;
    bool isClicked = false, state = true;
    int rng;


public:

    QVector<architecture *> architectures = QVector<architecture *>(3);

    explicit build(QWidget *page);// 构造函数

    void PressEvent(int x, int y);// 鼠标点击动作


    // get和set函数
    void setState(bool s) { this->state = s; }

    void setRng(int r) { this->rng = r; }
};

#endif // BUILD_H
