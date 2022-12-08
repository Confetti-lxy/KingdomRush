#ifndef ENEMY_H
#define ENEMY_H

#include "Map/map.h"
#include "EnemyState/enemystate.h"
#include "Friend/Defender/defender.h"
#include "Common/Blood/blood.h"

class defender;

class enemyState;

class enemy : public QLabel {
protected:

    int atk, rng;   // 攻击力和攻击范围
    bool isAttack;  // 是否在战斗状态
    bool isAtkImg1; // 是否在攻击动画的第一张图

    int allLife, existLife;// 全部生命和现存生命
    bool isAlive;// 是否存活
    blood *life;// 血条

    int speed; // 移动速度
    int moveInterval;// 移动间隔，和speed想对应
    int roadIndex;// 判断走的是哪条路径
    EnemyDirection enemyDirection;// 面朝方向
    bool isImg1;// 是否是步行的第一步

    defender *blockedDefender;// 阻挡的敌人
    bool isBlocked;// 是否被阻挡

    bool isArrive;// 是否到达重点

    int distance;// 某种距离

public:
    Map *my_map;
    EnemyType Type;// 敌人种类

    //----------------------------------------------------
    // buff栏的专用词条
    QVector <enemyState*> states;// 敌人的buff状态
    bool openFlash = false;// 若为true表明开启了flash能力
    bool flashCooling = false;// 在openFlash = true的情况下若flashCooling为true表明在冷却阶段，闪现能力不会生效
    defender * flashDen;// flash的敌人
    //----------------------------------------------------

    // 构造函数
    enemy();

    // 功能函数
    void beAttatked(int hurt);// 受到攻击,切换成攻击状态
    bool statusChecking(); // 生命值检查
    double distance_cal(int friend_x, int friend_y);// 计算与我方单位的距离
    bool enterEnd();// 是否抵达终点
    virtual bool judge_defender(defender *d) = 0;// 选择攻击的敌人
    virtual void moveAnimation() = 0;// 移动动画
    virtual void attackAnimation() = 0; // 攻击动画
    virtual void enemyMove(int road_loc, int step) = 0;// 敌人的移动

    // 下方一系列为set和get函数
    Map *get_map() { return this->my_map; }

    void set_map(Map *map) { this->my_map = map; }

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

    bool get_arrive() { return enterEnd(); }

    void set_arrive(bool arrive) { this->isArrive = arrive; }

    int get_dis() { return this->distance; }

    void add_dis(int l) { this->distance += l; }

    void be_blocked() { distance -= speed; }
};

#endif // ENEMY_H
