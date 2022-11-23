#include "defender.h"

defender::defender() {
    isAlive = true;
    isAttack = false;
    isAtkImg1 = true;
    blockedEnemys.clear();
}

bool defender::statusChecking() {
    if (existLife > 0 && isAlive) {
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
    if (location_check(click)) {
        show();
        set_IsDep(true);
    } else {
        close();
    }
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






















