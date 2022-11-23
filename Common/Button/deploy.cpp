#include "deploy.h"

deploy::deploy(QString defenderPath) {
    defenderImg = defenderPath;
    QPixmap pix;
    if (!pix.load(defenderImg)) {
        qDebug() << "picture load fail";
        return;
    }
    SetIcon(pix);
}

void deploy::mousePressEvent(QMouseEvent *event) {
    //窗体中相对鼠标位置与图片位置的判断，检测是否选中图片
    isMoveaiable = true;
}

void deploy::mouseMoveEvent(QMouseEvent *event) {
    if (isMoveaiable) {
        emit click_deploy(event);
    }
}

void deploy::mouseReleaseEvent(QMouseEvent *event) {
    if (isMoveaiable)
        emit release_deploy(event);
    isMoveaiable = false;
}
