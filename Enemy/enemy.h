#ifndef ENEMY_H
#define ENEMY_H

#include "Map/map.h"
#include "EnemyState/enemystate.h"

class enemy : public QLabel {
private:
    EnemyType type;
    int atk, rng;   //攻击力和攻击范围
    int allLife, existLife;
    int speed; //移动速度
    EnemyDirection enemyDirection;//面朝方向
    bool isAttack, isAlive, isImg1;//是否在攻击，是否存活,是否是步行的第一步
    vector <enemyState> states;//敌人的buff状态


public:

    Map *my_map;

    enemy();

    EnemyType get_type();

    void set_direction(EnemyDirection dir);

    EnemyDirection get_direction();

    void set_attack(bool isAttack);

    bool get_attack();

    void set_alive(bool isAlive);

    bool get_alive();

    void set_img1(bool isImg1);

    bool get_img1();

    void set_allLife(int allLife);

    int get_allLife();

    void set_existLife(int existLife);

    int get_existLife();

    void set_speed(int speed);

    int get_speed();

    void set_atk(int atk);

    int get_atk();

    void set_rng(int rng);

    int get_rng();
};

#endif // ENEMY_H
