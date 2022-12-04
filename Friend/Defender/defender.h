#ifndef DEFENDER_H
#define DEFENDER_H

#include "Map/map.h"
#include "Common/Button/deploy.h"
#include "Common/Blood/blood.h"
#include "Enemy/enemy.h"

class enemy;

class defender : public QLabel {
private:
    int atk, rng;   // 攻击力和攻击范围
    int attackInterval;// 攻击间隔（攻速）
    bool isAttack;  // 是否在战斗状态
    bool isAtkImg1; // 是否在攻击动画的第一张图


    int allLife, existLife;// 全部生命和现存生命
    bool isAlive;// 是否存活
    blood *life;// 血条

    int block_num;// 最大阻挡数
    QVector<enemy *> blockedEnemys;// 所阻挡的敌人

    int cost;// 部署费用
    bool isDeploy = false; // 是否成功部署

    virtual bool load() = 0;// 图片加载函数，在子类中重写

public:
    Map *my_map;
    DefenderType Type; // 防御者种类
    deploy *my_deploy;// 鼠标的部署动作

    int defender_x_loc, defender_y_loc;//defender的坐标
    int relative_x, relative_y;//格子坐标


    // 构造函数
    defender();

    // 功能函数

    // 虚函数，在子类中细化
    virtual void attackAnimation(enemy *blockedEnemy) = 0; // 攻击动画
    void defenderDeploy(QMouseEvent *click);// 鼠标点击部署位置，下方单位
    virtual void attack() = 0;// 攻击敌人


    // 实函数，在所有子类中共用
    bool statusChecking(); // 生命值检查
    void beAttacked(int atk);// 受到攻击，失去生命值
    bool judge_attack(int x, int y);// 判断是否在攻击范围内，以此判断是否攻击
    double distance_cal(int enemy_x, int enemy_y);// 计算与敌人的距离
    virtual bool add_enemy(enemy *e);// 添加阻挡的敌人


    //鼠标动作，相关的部署函数

    // 虚函数，在子类中细化
    virtual bool location_check(QMouseEvent *click) = 0;// 位置检查

    // 实函数，在所有子类中共用
    void mouseReleaseEvent(QMouseEvent *click);// 单位部署


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

    deploy *get_deploy() { return my_deploy; }

    void set_IsDep(bool isDeploy) { this->isDeploy = isDeploy; }

    bool get_IsDep() { return isDeploy; }

    void set_map(Map *my_map) { this->my_map = my_map; }

    void set_cost(int cost) { this->cost = cost; }

};

#endif // DEFENDER_H
