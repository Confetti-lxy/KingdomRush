#ifndef ENEMYSTATE_H
#define ENEMYSTATE_H

#include "./Common/common.h"
#include "./Enemy/enemy.h"

class enemy;

class enemyState:public QLabel {
private:
    enemy* buffEnemy;// 受到增幅的敌方单位
    QPixmap buffImage;// 增幅状态的显示
public:
    EnemyBuff Type;// buff的类型
    enemyState(enemy * e, EnemyBuff t);// 构造函数
};

#endif // ENEMYSTATE_H
