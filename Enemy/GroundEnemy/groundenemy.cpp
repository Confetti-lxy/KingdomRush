#include "groundenemy.h"

groundEnemy::groundEnemy() {

}

void groundEnemy::enemyMove(int road_loc, int step) {
    if (!get_alive()) {
        return;
    }
    if(bleeded) {
        this->beAttatked(200);
        bleedCount++;
        if(bleedCount == 5) {
            bleedCount = 0, bleeded = false;
        }
    }
    if(!beFrozen) {
        int x_loc = 0, y_loc = 0;
        EnemyDirection t = EnemyDirection(my_map->allRoads[road_loc].transToLoc(step, x_loc, y_loc));
        set_direction(t);
        move(x_loc + 0.5 * (my_map->get_width() - width()),
             y_loc + 0.5 * (my_map->get_width() - height()));
    }
    else {
        frozenCount++;
        if(frozenCount == 100) {
            frozenCount = 0, beFrozen = false;
        }
    }
}
