#ifndef ENEMY_H
#define ENEMY_H

#include "Map/map.h"
#include "EnemyState/enemystate.h"
#include "Friend/Defender/defender.h"

class defender;

class enemy : public QLabel {
private:

    int atk, rng;   //攻击力和攻击范围
    bool isAttack;  //是否在战斗状态
    bool isAtkImg1; //是否在攻击动画的第一张图

    int allLife, existLife;//全部生命和现存生命
    bool isAlive;//是否存活

    int speed; //移动速度
    int moveInterval;//移动间隔，和speed想对应
    int roadIndex;//判断走的是哪条路径
    EnemyDirection enemyDirection;//面朝方向
    bool isImg1;//是否是步行的第一步

    defender *blockedDefender;//
    bool isBlocked;//是否被阻挡

    vector <enemyState> states;//敌人的buff状态


public:
    Map *my_map;
    EnemyType type;//敌人种类

    // 构造函数
    enemy();

    // 功能函数
    void beAttatked(int hurt);//受到攻击,切换成攻击状态
    bool statusChecking(); //生命值检查
















    // 下方一系列为set和get函数

    void set_attack(bool isAttack) { this->isAttack = isAttack; }

    bool get_attack() { return isAttack; }

    void set_rng(int rng) { this->rng = rng; }

    int get_rng() { return rng; }

    void set_atk(int atk) { this->atk = atk; }

    int get_atk() { return atk; }

    void set_atkImg(bool isAtkImg1) { this->isAtkImg1 = isAtkImg1; }

    bool get_atkImg() { return isAtkImg1; }

    void set_allLife(int allLife) { this->allLife = allLife; }

    int get_allLife() { return allLife; }

    void set_existLife(int existLife) { this->existLife = existLife; }

    int get_existLife() { return existLife; }

    void set_alive(bool isAlive) { this->isAlive = isAlive; }

    bool get_alive() { return isAlive; }

    void set_img1(bool isImg1) { this->isImg1 = isImg1; }

    bool get_img1() { return isImg1; }

    void set_speed(int speed) { this->speed = speed; }

    int get_speed() { return speed; }

    void set_index(int index) { this->roadIndex = index; }

    int get_index() { return roadIndex; }

    void set_interval(int interval) { this->moveInterval = interval; }

    int get_interval() { return moveInterval; }

    void set_direction(EnemyDirection dir) { this->enemyDirection = dir; }

    EnemyDirection get_direction() { return enemyDirection; }

    void set_defender(defender *def) { this->blockedDefender = def; }

    defender *get_defender() { return blockedDefender; }

    void set_blocked(bool blocked) { this->isBlocked = blocked; }

    bool get_blocked() { return isBlocked; }
};

#endif // ENEMY_H
