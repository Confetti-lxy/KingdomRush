#include "gargoyle.h"

bool gargoyle::load() {
    if (!enemyImage.enemyleft1_Img.load(":/image/enemyflyleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyleft2_Img.load(":/image/enemyflyleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright1_Img.load(":/image/enemyflyright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright2_Img.load(":/image/enemyflyright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyleft3_Img.load(":/image/enemyflyleft3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyleft4_Img.load(":/image/enemyflyleft4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright3_Img.load(":/image/enemyflyright3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright4_Img.load(":/image/enemyflyright4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!bulletImg.load(":/image/remoteenemybullet.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

gargoyle::gargoyle() {
    if (!gargoyle::load()) {
        return;
    }
    SetBase(enemyImage.enemyleft1_Img);

    Type = Gargoyle;
    set_rng(2);

}

void gargoyle::attack() {
    defender *d = get_defender();
    if (d && d->statusChecking()) {
        d->beAttacked(get_atk());
        this->attackAnimation();
    }
}
