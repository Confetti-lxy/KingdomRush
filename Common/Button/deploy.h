#ifndef DEPLOY_H
#define DEPLOY_H

#include "Common/common.h"

// 兵种释放类

class deploy : public QPushButton {
    Q_OBJECT
            QString
    defenderImg;
    bool isMoveaiable = false;
public:
    deploy(QString defenderPath);

    // 鼠标动作
    void mousePressEvent(QMouseEvent *click);

    void mouseReleaseEvent(QMouseEvent *click);

    void mouseMoveEvent(QMouseEvent *click);

    signals:
            void click_deploy(QMouseEvent * click);// 点击动作
    void release_deploy(QMouseEvent *click);// 释放动作
};

#endif // DEPLOY_H
