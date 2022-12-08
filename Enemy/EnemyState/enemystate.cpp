#include "enemystate.h"

enemyState::enemyState(enemy * e, EnemyBuff t) {
    this->buffEnemy = e;
    this->Type = t;
    if(t == Speed) {
        e->set_speed(2 * e->get_speed());
    }
    if(t == Powered) {
        e->set_atk(2 * e->get_atk());
    }
    if(t == Flash) {
        e->openFlash = true;
        e->flashCooling = true;
    }
}
