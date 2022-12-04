#ifndef BUILD_H
#define BUILD_H

#include "architecture.h"


class build : public QPushButton {

private:
    QPixmap RemoteCellImg, CircleImg;// 远程建筑地块和周边圈的图片素材
    QLabel *Circle;// 指向周边圈的label
    QWidget *page; // 依附的父类图层
    bool isClicked = false, state = true;// 是否点击，以及状态参数(此地块是否已经部署)
    int rngState = 0;// 范围

public:

    QVector<architecture *> architectures = QVector<architecture *>(3);// 三种建筑塔

    explicit build(QWidget *page);// 构造函数

    void PressEvent(int x, int y);// 鼠标点击动作


    // get和set函数
    void setState(bool s) { this->state = s; }

    bool getState() { return this->state; }

    void setRng(int r) { this->rngState = r; }

    int getRng() { return this->rngState; }
};

#endif // BUILD_H
