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
        blockedEnemys.clear();
        hide();
        return false;
    }
}
