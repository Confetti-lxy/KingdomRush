#ifndef SOLDIER_H
#define SOLDIER_H

#include "defender.h"


class soldier : public defender {
private:
    void load() override;

public:
    defenderImage defenderImage; //战士的图片资源
    deploy *defenderDeploy;

    //构造函数
    soldier();

    // 功能函数
    void attackAnimation(enemy *blockedEnemy) override;

};

#endif // SOLDIER_H
