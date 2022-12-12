#include "towerstate.h"

towerState::towerState(tower * t, TowerBuff b)
{
    this->buffTower = t;
    this->Type = b;
    if(b == Bleeding) {
        t->openBleeding = true;
    }
}
