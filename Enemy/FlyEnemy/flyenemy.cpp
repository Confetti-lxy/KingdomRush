#include "flyenemy.h"

flyEnemy::flyEnemy() {

}

void flyEnemy::enemyMove(int road_loc, int step) {
    int x_loc = 0, y_loc = 0;
    set_direction(EnemyDirection(my_map->allRoads[road_loc].transToLoc(step, x_loc, y_loc)));
    move(x_loc + 0.5 * (my_map->get_width() - width()),
         y_loc + 0.5 * (my_map->get_width() - height()));
}
