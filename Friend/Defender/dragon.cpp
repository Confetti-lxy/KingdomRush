#include "dragon.h"

bool dragon::load() {
    my_deploy = new deploy(":/image/soldier3_btn.png");
    if (!dragonImg.dragonImg.load(":/image/soldier3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackleft1_Img.load(":/image/soldier3attackleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackleft2_Img.load(":/image/soldier3attackleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackright1_Img.load(":/image/soldier3attackright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackright2_Img.load(":/image/soldier3attackright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackleft3_Img.load(":/image/soldier3attackleft3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackleft4_Img.load(":/image/soldier3attackleft4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackright3_Img.load(":/image/soldier3attackright3.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!dragonImg.dragonattackright4_Img.load(":/image/soldier3attackright4.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

dragon::dragon() {
    // 图片加载，若失败则直接返回
    if (!dragon::load()) {
        return;
    }

    // 图片设置
    SetBase(dragonImg.dragonImg);

    // soldier单位的数值设计
    Type = Dragon;
    set_atk(600), set_rng(1);
    set_cost(100);
    set_allLife(6000), set_existLife(6000);
    set_block(2);
}

bool dragon::location_check(QMouseEvent *click) {
    int Width = my_map->get_width(), Height = my_map->get_height(), Length = my_map->get_len();
    int x_loc = (click->pos().x() + 940) / Width, y_loc = (click->pos().y() + 300) / Width;
    if (x_loc >= 0 && x_loc < Length / Width && y_loc >= 0 && y_loc < Height / Width) {
        if (my_map->get_grid(x_loc, y_loc) == close_cell) {
            defender_x_loc = x_loc * 70, defender_y_loc = y_loc * 70;
            relative_x = x_loc + 0.5 * (Width - width());
            relative_y = y_loc + 0.5 * (Width - height());
            move(x_loc * Width + 0.5 * (Width - width()), y_loc * Width + 0.5 * (Width - height()));
            return true;
        }
    }
    return false;
}

void dragon::attackAnimation(enemy *blockedEnemy) {
    if (blockedEnemy->Type == Barbarian || blockedEnemy->Type == Remoteenemy) {
        if (x() < blockedEnemy->x()) {
            if (!get_atkImg()) {
                setPixmap(dragonImg.dragonattackright1_Img);
                raise();
                set_atkImg(true);
            } else {
                setPixmap(dragonImg.dragonattackright2_Img);
                raise();
                set_atkImg(false);
            }
        } else {
            if (!get_atkImg()) {
                setPixmap(dragonImg.dragonattackleft1_Img);
                raise();
                set_atkImg(true);
            } else {
                setPixmap(dragonImg.dragonattackleft2_Img);
                raise();
                set_atkImg(false);
            }
        }
    } else {
        if (x() < blockedEnemy->x()) {
            if (!get_atkImg()) {
                setPixmap(dragonImg.dragonattackright3_Img);
                raise();
                set_atkImg(true);
            } else {
                setPixmap(dragonImg.dragonattackright4_Img);
                raise();
                set_atkImg(false);
            }
        } else {
            if (!get_atkImg()) {
                setPixmap(dragonImg.dragonattackleft3_Img);
                raise();
                set_atkImg(true);
            } else {
                setPixmap(dragonImg.dragonattackleft4_Img);
                raise();
                set_atkImg(false);
            }
        }
    }
}

void dragon::attack() {
    QVector < enemy * > e = get_blockEnemy();
    if (!e.empty()) {
        for (auto it = e.begin(); it != e.end(); it++) {
            if (!(*it)->statusChecking()) {
                e.erase(it);
                //----------------------------------------
                // 防止只有一个单位时卡死
                if(it == e.end()) break; //追加容错，防止崩溃
                //----------------------------------------
            }
        }
        // 若存在被阻挡的敌人，则优先攻击先被阻挡的敌人
        if (!e.empty()) {
            e[0]->beAttatked(get_atk());
            attackAnimation(e[0]);

        }
            // 否则则变为初始的未攻击的状态
        else {
            setPixmap(dragonImg.dragonImg);
            int width = my_map->get_width();
            move(relative_x * width, relative_y * width);
        }
        this->set_blockedEnemy(e);
    }
    //-------------------------------------
    // 阻挡单位
    for (auto e: get_blockEnemy()) {
        e->be_blocked();
    }
    //-------------------------------------
}

bool dragon::add_enemy(enemy *e) {
    QVector < enemy * > d = get_blockEnemy();
    if (e->statusChecking() && d.size() < get_block()) {
        if (!e->get_blocked() && judge_attack(e->x(), e->y())) {
            d.append(e);
            e->set_blocked(true);
            set_blockedEnemy(d);
            return true;
        }
    }
    return false;
}

