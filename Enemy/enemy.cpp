#include "enemy.h"

enemy::enemy() {
    isAlive = true;
    isAttack = false;
    isImg1 = true;
    isBlocked = false;
    isAtkImg1 = true;
    isArrive = false;
    distance = 0;
    life = new blood;
    life->setParent(this);
    life->show();
    life->raise();
}


void enemy::beAttatked(int hurt) {
    existLife -= hurt;
    set_attack(true);
}

bool enemy::statusChecking() {
    life->raise();
    if (!isAlive) {
        life->hide();
        this->hide();
        return false;
    } else if (isAlive && existLife <= 0) {
        isAlive = false;
        lower();
        life->hide();
        return false;
    } else {
        life->set_len((70.0 * existLife) / allLife);
        life->raise();
        return true;
    }
}

double enemy::distance_cal(int friend_x, int friend_y) {
    int x = friend_x - this->x();
    int y = friend_y - this->y();
    return sqrt(x * x + y * y);
}

bool enemy::enterEnd() {
    if (!isArrive) {
        int index = get_index(), width = my_map->get_width();
        int length = my_map->allRoads[index].get_len();
        int x_len = my_map->allRoads[index].get_loc(length - 1, 0) * width;
        int y_len = my_map->allRoads[index].get_loc(length - 1, 1) * width;
        if (Type == Gargoyle) {
            if (x() <= x_len + 30 && x() >= x_len - 30 && y() >= y_len - 30 && y() <= y_len + 30) {
                set_arrive(true);
                set_alive(false);
                qDebug() << Type << get_alive();
                return true;
            }
        } else {
            if (x() <= x_len + 10 && x() >= x_len - 10 && y() >= y_len - 10 && y() <= y_len + 10) {
                set_arrive(true);
                set_alive(false);
                qDebug() << Type << get_alive();
                return true;
            }
        }
    }
    return false;
}
