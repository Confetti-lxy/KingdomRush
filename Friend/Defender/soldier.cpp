#include "soldier.h"

bool soldier::load() {
    my_deploy = new deploy(":/image/soldier1_btn.jpg");
    if (!defenderImg.soldierImg.load(":/image/soldier1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!defenderImg.soldierattackleft1_Img.load(":/image/soldier1attackleft1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!defenderImg.soldierattackleft2_Img.load(":/image/soldier1attackleft2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!defenderImg.soldierattackright1_Img.load(":/image/soldier1attackright1.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!defenderImg.soldierattackright2_Img.load(":/image/soldier1attackright2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

soldier::soldier() {
    // 图片加载，若失败则直接返回
    if (!soldier::load()) {
        return;
    }

    // 图片设置
    SetBase(defenderImg.soldierImg);


    // soldier单位的数值设计
    Type = Soldier;
    set_atk(400), set_rng(1);
    set_cost(50);
    set_allLife(5000), set_existLife(5000);
    set_block(2);
}

void soldier::attackAnimation(enemy *blockedEnemy) {
    if (x() < blockedEnemy->x()) {
        if (!get_atkImg()) {
            setPixmap(defenderImg.soldierattackright1_Img);
            raise();
            set_atkImg(true);
        } else {
            setPixmap(defenderImg.soldierattackright2_Img);
            raise();
            set_atkImg(false);
        }
    } else {
        if (!get_atkImg()) {
            setPixmap(defenderImg.soldierattackleft1_Img);
            raise();
            set_atkImg(true);
        } else {
            setPixmap(defenderImg.soldierattackleft2_Img);
            raise();
            set_atkImg(false);
        }
    }
}

void soldier::attack() {
    QVector < enemy * > e = get_blockEnemy();
    if (!e.empty()) {
        for (auto it = e.begin(); it != e.end(); it++) {
            if (!(*it)->statusChecking()) {
                e.erase(it);
            }
        }
        // 若存在被阻挡的敌人，则优先攻击先被阻挡的敌人
        if (!e.empty()) {
            e[0]->beAttatked(get_atk());
            attackAnimation(e[0]);
        }
            // 否则则变为初始的未攻击的状态
        else {
            setPixmap(defenderImg.soldierImg);
            int width = my_map->get_width();
            move(relative_x * width, relative_y * width);
        }
        this->set_blockedEnemy(e);
    }
}

bool soldier::location_check(QMouseEvent *click) {
    int Width = my_map->get_width(), Height = my_map->get_height(), Length = my_map->get_len();
    int x_loc = (click->pos().x() + 940) / Width, y_loc = (click->pos().y()) / Width;
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









































