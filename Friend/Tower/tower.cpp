#include "tower.h"

tower::tower() {
    my_range = new range, my_range->hide();
    isRange = false, isAttack = false;
}


void tower::attack() {
    target_enemy->beAttatked(get_atk());
    if(openBleeding) {
        target_enemy->bleeded = true, atkCount++;
        if(atkCount == 100) {
            atkCount = 0, openBleeding = false;
            deleteState(states, Bleeding);
        }
    }
}

void tower::beAttacked(int atk) {
    existLife -= atk;
}


bool tower::statusChecking() {
    if (existLife > 0) {
        return true;
    } else {
        this->hide(), this->my_build->setState(true);
        return false;
    }
}

bool tower::show_rng(int x, int y) {
    my_range->set_xr(this->x() + 0.5 * width());
    my_range->set_yr(this->y() + 0.5 * height());
    my_range->setParent(this->parentWidget());
    if (x >= this->x() && x <= this->x() + 70 && y >= this->y() && y <= this->y() + 70) {
        if (!isRange) {
            if (statusChecking()) {
                set_range(true), my_range->show();
            }
        } else {
            set_range(false), my_range->hide();
        }
    }
    return false;
}

double tower::distance_cal(int enemy_x, int enemy_y) {
    int x = enemy_x - this->x();
    int y = enemy_y - this->y();
    return sqrt(x * x + y * y);
}

bool tower::judge_enemy(enemy *e) {
    int width = my_map->get_width();
    double dis = rng * width;
    if (e->statusChecking()) {
        if (dis >= distance_cal(e->x(), e->y())) {
            target_enemy = e, attack();
            return true;
        }
    }
    return false;
}
