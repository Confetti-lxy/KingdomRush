#include "defender.h"

int extern coins;

defender::defender() {
    isAlive = true;
    isAttack = false;
    isAtkImg1 = true;
    blockedEnemys.clear();
    life = new blood;
    life->setParent(this);
    life->show();
    life->raise();
}

bool defender::statusChecking() {
    if (existLife > 0 && isAlive) {
        life->set_len(70.0 * allLife / existLife);
        return true;
    } else {
        isAlive = false;
        for (auto blockedEnemy: blockedEnemys) {
            blockedEnemy->set_blocked(false);
        }
        this->blockedEnemys.clear();
        this->hide();
        return false;
    }
}

void defender::beAttacked(int atk) {
    existLife -= atk;
}

void defender::mouseReleaseEvent(QMouseEvent *click) {
    if (location_check(click) && coins >= cost) {
        show();
        coins -= cost;
        set_IsDep(true);
    } else {
        close();
    }
}

void defender::defenderDeploy(QMouseEvent *click) {
    if (Type == Soldier)
        this->move(click->x() + 895, click->y() - 20);
    if (Type == Guard)
        this->move(click->x() + 895, click->y() + 130);
    if (Type == Dragon)
        this->move(click->x() + 810, click->y() + 280);
    this->show();
    this->raise();
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
}

double defender::distance_cal(int enemy_x, int enemy_y) {
    int x = enemy_x - defender_x_loc;
    int y = enemy_y - defender_y_loc;
    return sqrt(x * x + y * y);
}

bool defender::judge_attack(int x, int y) {
    int width = my_map->get_width();
    if (block_num == blockedEnemys.size()) {
        return false;
    } else {
        if (distance_cal(x, y) <= width * rng) {
            return true;
        }
    }
    return false;
}

bool defender::add_enemy(enemy *e) {
    if (e->statusChecking() && blockedEnemys.size() < block_num) {
        if (e->Type == Remoteenemy || e->Type == Barbarian) {
            if (!e->get_blocked() && judge_attack(e->x(), e->y())) {
                blockedEnemys.append(e);
                e->set_blocked(true);
                return true;
            }
        }
    }
    return false;
}






















