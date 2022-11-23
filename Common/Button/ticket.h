#ifndef TICKET_H
#define TICKET_H

#include "Common/common.h"

// 这个类用于描述抖动的窗口，这个项目中只用于开始界面的start button

class ticket : public QPushButton {

private:
    Q_OBJECT
            QString
    routineImg,
    activationImg;

public:
    ticket(QString routineImg, QString activationImg = "");

    void zoomUp();// 向上抖动

    void zoomDown();// 向下抖动

    void press(QMouseEvent *event);// 鼠标点击动作

    void release(QMouseEvent *event);// 鼠标释放动作

    signals:
};

#endif // TICKET_H
