#include "remoteenemy.h"

extern QVector<bullet*> bullets;

bool remoteenemy::load() {
    if (!enemyImage.enemyleft1_Img.load(":/image/remoteenemyleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyleft2_Img.load(":/image/remoteenemyleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright1_Img.load(":/image/remoteenemyright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyright2_Img.load(":/image/remoteenemyright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackleft1_Img.load(":/image/remoteenemyattackleft.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackleft2_Img.load(":/image/remoteenemyattackleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackright1_Img.load(":/image/remoteenemyattackright.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!enemyImage.enemyattackright2_Img.load(":/image/remoteenemyattackright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!bulletImg.load(":/image/remoteenemybullet.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

remoteenemy::remoteenemy() {
    // 图片加载，失败则直接返回
    if (!remoteenemy::load()) {
        return;
    }
    SetBase(enemyImage.enemyleft1_Img);
    // Remoteenemy的属性设置
    Type = Remoteenemy;
    set_atk(100), set_rng(3);
    set_allLife(4000), set_existLife(4000);
    set_speed(4), set_interval(2000), set_direction(e_left);
    set_defender(nullptr);
    bulletStatu = 0;
}

void remoteenemy::moveAnimation() {
    if (!get_alive()) {
        return;
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

bool remoteenemy::judge_defender(defender *d) {
    int width = my_map->get_width();
    if (statusChecking()) {
        if (d->statusChecking()) {
            if (distance_cal(d->defender_x_loc, d->defender_y_loc) <= width * get_rng()) {
                set_defender(d), attack();
                return true;
            }
        }
    }
    return false;
}

void remoteenemy::attack() {
    if(!get_alive()) {
        return;
    }
    defender *d = get_defender();
    if (d && d->statusChecking()) {
        d->beAttacked(get_atk());
        this->attackAnimation();
    }
}

void remoteenemy::attackAnimation() {
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
    if(get_alive()) {
        if (bulletStatu == 0) {
            bullet *b = new bullet(bulletImg);
            bullets.append(b);
            b->move(x() + 60, y() + 25);
            b->setParent(this->parentWidget());
            b->show(), b->ballistic(get_defender());
            bulletStatu++;
        } else {
            bulletStatu = (bulletStatu + 1) % 10;
        }
    }
}
