#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "groundenemy.h"


class barbarian : public groundEnemy {
private:
    void load() override;

public:
    barbarian();

    void attackAnimation() override;

    void moveAnimation() override;
};

#endif // BARBARIAN_H
