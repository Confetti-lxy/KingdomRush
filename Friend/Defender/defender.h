#ifndef DEFENDER_H
#define DEFENDER_H

#include "Map/map.h"
#include "Common/Button/deploy.h"
#include "Enemy/enemy.h"

class enemy;

class defender : public QLabel {
private:
    int atk, rng;   //攻击力和攻击范围
    int attackInterval;//攻击间隔（攻速）
    bool isAttack;  //是否在战斗状态
    bool isAtkImg1; //是否在攻击动画的第一张图


    int allLife, existLife;//全部生命和现存生命
    bool isAlive;//是否存活

    int block_num;//阻挡数
    QVector<enemy *> blockedEnemys;//所阻挡的敌人

    virtual void load() = 0;

public:
    Map *my_map;
    DefenderType Type; // 防御者种类

    // 构造函数
    defender();

    // 功能函数
    virtual void attackAnimation(enemy *blockedEnemy) = 0; //攻击动画
    bool statusChecking(); //生命值检查












    // 以下是一系列set和get函数
    void set_attack(bool isAttack) { this->isAttack = isAttack; }

    bool get_attack() { return isAttack; }

    void set_atk(int atk) { this->atk = atk; }

    int get_atk() { return atk; }

    void set_rng(int rng) { this->rng = rng; }

    int get_rng() { return rng; }

    void set_atkImg(bool isAtkImg1) { this->isAtkImg1 = isAtkImg1; }

    bool get_atkImg() { return isAtkImg1; }

    void set_allLife(int allLife) { this->allLife = allLife; }

    int get_allLife() { return allLife; }

    void set_existLife(int existLife) { this->existLife = existLife; }

    int get_existLife() { return existLife; }

    void set_alive(bool isAlive) { this->isAlive = isAlive; }

    bool get_alive() { return isAlive; }

    void set_block(int block_num) { this->block_num = block_num; }

    int get_block() { return block_num; }

    void set_blockedEnemy(QVector<enemy *> blockedEnemys) { this->blockedEnemys = blockedEnemys; }

    QVector<enemy *> get_blockEnemy() { return blockedEnemys; }

};

#endif // DEFENDER_H
