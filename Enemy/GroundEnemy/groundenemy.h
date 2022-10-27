#ifndef GROUNDENEMY_H
#define GROUNDENEMY_H

#include "Enemy/enemy.h"


class groundEnemy : public enemy {
private:
    virtual void load() = 0;

public:
    groundEnemyImage enemyImage;

    groundEnemy();

    void enemyMove(int road_loc, int step);

    virtual void attackAnimation() = 0;

    virtual void moveAnimation() = 0;
};

#endif // GROUNDENEMY_H
