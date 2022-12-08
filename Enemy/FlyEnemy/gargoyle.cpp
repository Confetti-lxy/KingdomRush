#include "gargoyle.h"

extern QVector<bullet*> bullets;

bool gargoyle::load() {
    if (!enemyImage.enemyleft1_Img.load(":/image/enemyflyleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyleft1_Img = enemyImage.enemyleft1_Img.scaled(50,
                                                                 50 * enemyImage.enemyleft1_Img.height() /
                                                                 enemyImage.enemyleft1_Img.width(),
                                                                 Qt::KeepAspectRatio);
    if (!enemyImage.enemyleft2_Img.load(":/image/enemyflyleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyleft2_Img = enemyImage.enemyleft2_Img.scaled(50,
                                                                 50 * enemyImage.enemyleft2_Img.height() /
                                                                 enemyImage.enemyleft2_Img.width(),
                                                                 Qt::KeepAspectRatio);
    if (!enemyImage.enemyright1_Img.load(":/image/enemyflyright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyright1_Img = enemyImage.enemyright1_Img.scaled(50,
                                                                   50 * enemyImage.enemyright1_Img.height() /
                                                                   enemyImage.enemyright1_Img.width(),
                                                                   Qt::KeepAspectRatio);
    if (!enemyImage.enemyright2_Img.load(":/image/enemyflyright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyright2_Img = enemyImage.enemyright2_Img.scaled(50,
                                                                   50 * enemyImage.enemyright2_Img.height() /
                                                                   enemyImage.enemyright2_Img.width(),
                                                                   Qt::KeepAspectRatio);
    if (!enemyImage.enemyleft3_Img.load(":/image/enemyflyleft3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyleft3_Img = enemyImage.enemyleft3_Img.scaled(50,
                                                                 50 * enemyImage.enemyleft3_Img.height() /
                                                                 enemyImage.enemyleft3_Img.width(),
                                                                 Qt::KeepAspectRatio);
    if (!enemyImage.enemyleft4_Img.load(":/image/enemyflyleft4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyleft4_Img = enemyImage.enemyleft4_Img.scaled(50,
                                                                 50 * enemyImage.enemyleft4_Img.height() /
                                                                 enemyImage.enemyleft4_Img.width(),
                                                                 Qt::KeepAspectRatio);
    if (!enemyImage.enemyright3_Img.load(":/image/enemyflyright3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyright3_Img = enemyImage.enemyright3_Img.scaled(50,
                                                                   50 * enemyImage.enemyright3_Img.height() /
                                                                   enemyImage.enemyright3_Img.width(),
                                                                   Qt::KeepAspectRatio);
    if (!enemyImage.enemyright4_Img.load(":/image/enemyflyright4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    enemyImage.enemyright4_Img = enemyImage.enemyright4_Img.scaled(50,
                                                                   50 * enemyImage.enemyright4_Img.height() /
                                                                   enemyImage.enemyright4_Img.width(),
                                                                   Qt::KeepAspectRatio);
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
    set_atk(50), set_rng(2);
    set_allLife(2000), set_existLife(2000);
    set_speed(4), set_interval(2000), set_direction(e_left);
    set_defender(nullptr);
    bulletStatu = 0;
}

void gargoyle::attack() {
    if(!get_alive()) {
        return;
    }
    defender *d = get_defender();
    if (d && d->statusChecking()) {
        d->beAttacked(get_atk());
        this->attackAnimation();
    }
}

void gargoyle::moveAnimation() {
    if (get_alive()) {
        if (get_direction() == e_left) {
            switch (imageCount) {
                case 0:
                    setPixmap(enemyImage.enemyleft1_Img);
                    resize(QSize(enemyImage.enemyleft1_Img.width(), enemyImage.enemyleft1_Img.height()));
                    break;
                case 1:
                    setPixmap(enemyImage.enemyleft2_Img);
                    resize(QSize(enemyImage.enemyleft2_Img.width(), enemyImage.enemyleft2_Img.height()));
                    break;
                case 2:
                    setPixmap(enemyImage.enemyleft3_Img);
                    resize(QSize(enemyImage.enemyleft3_Img.width(), enemyImage.enemyleft3_Img.height()));
                    break;
                case 3:
                    setPixmap(enemyImage.enemyleft4_Img);
                    resize(QSize(enemyImage.enemyleft4_Img.width(), enemyImage.enemyleft4_Img.height()));
                    break;
            }
        } else {
            switch (imageCount) {
                case 0:
                    setPixmap(enemyImage.enemyright1_Img);
                    resize(QSize(enemyImage.enemyright1_Img.width(), enemyImage.enemyright1_Img.height()));
                    break;
                case 1:
                    setPixmap(enemyImage.enemyright2_Img);
                    resize(QSize(enemyImage.enemyright2_Img.width(), enemyImage.enemyright2_Img.height()));
                    break;
                case 2:
                    setPixmap(enemyImage.enemyright3_Img);
                    resize(QSize(enemyImage.enemyright3_Img.width(), enemyImage.enemyright3_Img.height()));
                    break;
                case 3:
                    setPixmap(enemyImage.enemyright4_Img);
                    resize(QSize(enemyImage.enemyright4_Img.width(), enemyImage.enemyright4_Img.height()));
                    break;
            }
        }
        imageCount = (imageCount + 1) % 4;
    }
}

void gargoyle::attackAnimation() {
    if(get_alive()) {
        QLabel *t = get_defender();
        if (bulletStatu == 0) {
            bullet *b = new bullet(bulletImg);
            bullets.append(b);
            if (get_direction() == e_right) {
                b->move(x() + 60, y() + 25);
            } else {
                b->move(x(), y() + 27);
            }
            b->setParent(this->parentWidget());
            b->show();
            b->ballistic(t);
            bulletStatu++;
        } else {
            bulletStatu = (bulletStatu + 1) % 10;
        }
    }
}

bool gargoyle::judge_defender(defender *d) {
    int width = my_map->get_width();
    double dis = get_rng() * width;
    if (d->get_alive()) {
        if (distance_cal(d->x(), d->y()) <= dis) {
            set_defender(d);
            attack();
            return true;
        }
    }
    return false;
}


