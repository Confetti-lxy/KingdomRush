#include "defenderstate.h"

defenderState::defenderState(defender*d,DefenderBuff t)
{
    this->buffDefender = d;
    this->Type = t;
    if(t == Berserk) {
        d->set_atk(2 * d->get_atk());
    }
    else if(t == Glacial) {
        d->openGlacial = true;
    }
    else {
        d->openMassInjured = true;
    }
}
