#include "enemy.h"

enemy::enemy() {
    isAlive = true;
    isAttack = false;
    isImg1 = true;
    isBlocked = false;
    isAtkImg1 = true;
}


void enemy::beAttatked(int hurt) {
    existLife -= hurt;
    set_attack(true);
}


bool enemy::statusChecking() {
    if (!isAlive) {
        hide();
        return false;
    } else if (isAlive && existLife <= 0) {
        isAlive = false;
        hide();
        return false;
    } else {
        return true;
    }
}
