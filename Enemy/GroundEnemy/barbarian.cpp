#include "barbarian.h"

bool barbarian::load() {
    if (!enemyImage.enemyleft1_Img.load(":/image/enemyleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyleft2_Img.load(":/image/enemyleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright1_Img.load(":/image/enemyright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright2_Img.load(":/image/enemyright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackleft1_Img.load(":/image/enemyleftattack.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackleft2_Img.load(":/image/enemyleftattack2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackright1_Img.load(":/image/enemyrightattack.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackright2_Img.load(":/image/enemyrightattack2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

barbarian::barbarian() {
    // 图片加载，失败则直接返回
    if (!barbarian::load()) {
        return;
    }
    SetBase(enemyImage.enemyleft1_Img);

    // Barbarian的属性设置
    Type = Barbarian;
    set_atk(40), set_rng(1);
    set_allLife(4000), set_existLife(4000);
    set_speed(4), set_interval(2000), set_direction(e_left);
    set_defender(nullptr);
}

void barbarian::attackAnimation() {
    if (x() > get_defender()->x()) {
        if (!get_atkImg()) {
            setPixmap(enemyImage.enemyattackleft1_Img);
            set_atkImg(true);
        } else {
            setPixmap(enemyImage.enemyattackleft2_Img);
            set_atkImg(false);
        }
    } else {
        if (!get_atkImg()) {
            setPixmap(enemyImage.enemyattackright1_Img);
            set_atkImg(true);
        } else {
            setPixmap(enemyImage.enemyattackright2_Img);
            set_atkImg(false);
        }
    }
}

void barbarian::moveAnimation() {
    if (!get_alive()) {
        return ;
    }
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

bool barbarian::judge_defender(defender *d) {
    int width = my_map->get_width();
    if (statusChecking()) {
        if (d->statusChecking()) {
            if (distance_cal(d->defender_x_loc, d->defender_y_loc) <= width * get_rng()) {
                set_defender(d);
                attack();
                return true;
            }
        }
    }
    return false;
}

void barbarian::attack() {
    defender *d = get_defender();
    if (d && d->statusChecking()) {
        d->beAttacked(get_atk());
        this->attackAnimation();
    }
}


































