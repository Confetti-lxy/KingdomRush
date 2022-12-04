#include "groundenemy.h"

groundEnemy::groundEnemy() {

}

void groundEnemy::enemyMove(int road_loc, int step) {
    if (get_alive()) {
        int x_loc = 0, y_loc = 0;
        EnemyDirection t = EnemyDirection(my_map->allRoads[road_loc].transToLoc(step, x_loc, y_loc));
        set_direction(t);
        move(x_loc + 0.5 * (my_map->get_width() - width()),
             y_loc + 0.5 * (my_map->get_width() - height()));
    }
}
