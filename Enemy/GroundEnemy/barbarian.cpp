#include "barbarian.h"

void barbarian::load() {
    if (!enemyImage.enemyleft1_Img.load(":/image/enemyleft1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyleft2_Img.load(":/image/enemyleft2.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyright1_Img.load(":/image/enemyright1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyright2_Img.load(":/image/enemyright2.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyattackleft1_Img.load(":/image/enemyleftattack.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyattackleft2_Img.load(":/image/enemyleftattack2.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyattackright1_Img.load(":/image/enemyrightattack.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!enemyImage.enemyattackright2_Img.load(":/image/enemyrightattack2.png")) {
        qDebug() << "picture load fail";
        return;
    }
}

barbarian::barbarian() {
    barbarian::load();
    setFixedSize(enemyImage.enemyleft1_Img.width(), enemyImage.enemyleft1_Img.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setPixmap(enemyImage.enemyleft1_Img);
    setBaseSize(QSize(enemyImage.enemyleft1_Img.width(), enemyImage.enemyleft1_Img.height()));
}


void barbarian::attackAnimation() {
    if (!get_attack()) {
        setPixmap(enemyImage.enemyattackleft1_Img);
        set_attack(true);
    } else {
        setPixmap(enemyImage.enemyattackleft2_Img);
        set_attack(false);
    }


//    if(!get_attack()) {
//        setPixmap(enemyImage.enemyattackright1_Img);
//        set_attack(true);
//    }
//    else {
//        setPixmap(enemyImage.enemyattackright2_Img);
//        set_attack(false);
//    }
}

void barbarian::moveAnimation() {
    if (get_direction() == e_left) {
        if (get_img1()) {
            setPixmap(enemyImage.enemyleft2_Img);
            resize(QSize(enemyImage.enemyleft2_Img.width(), enemyImage.enemyleft2_Img.height()));
            set_img1(false);
        } else {
            setPixmap(enemyImage.enemyleft1_Img);
            resize(QSize(enemyImage.enemyleft1_Img.width(), enemyImage.enemyleft1_Img.height()));
            set_img1(true);
        }
        return;
    }
    if (get_direction() == e_right) {
        if (get_img1()) {
            setPixmap(enemyImage.enemyright2_Img);
            resize(QSize(enemyImage.enemyright2_Img.width(), enemyImage.enemyright2_Img.height()));
            set_img1(false);
        } else {
            setPixmap(enemyImage.enemyright1_Img);
            resize(QSize(enemyImage.enemyright1_Img.width(), enemyImage.enemyright1_Img.height()));
            set_img1(true);
        }
    }
}


































