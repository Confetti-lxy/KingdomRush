#ifndef TOWER_H
#define TOWER_H

#include "./Map/map.h"
#include "./Common/Blood/blood.h"
#include "./Enemy/enemy.h"
#include "./Friend/Tower/range.h"

class tower : public QLabel {
protected:
    int allLife, existLife;// 全部生命和现存生命
    blood *life;

    int cost;// 部署费用

    int atk, rng;   // 攻击力和攻击范围
    int attackInterval = 500;// 攻击间隔（攻速）
    bool isAttack;  // 是否在战斗状态


    bool isDeploy = false; // 是否成功部署

    enemy *target_enemy;// 锁定的敌人
    build *my_build;// 防御塔所在的地块

    bool isRange;// 是否正在显示攻击范围
public:
    Map *my_map;
    QPixmap TowerImage;// 图片素材
    range *my_range;// 攻击范围圈

    tower();// 构造函数

    // 功能函数

    void attack();// 攻击函数

    void beAttacked(int atk);// 被攻击

    bool statusChecking(); // 生命值检查

    bool show_rng(int x, int y);// 显示攻击范围

    double distance_cal(int enemy_x, int enemy_y);// 计算与敌人的距离

    bool judge_enemy(enemy *e);// 选取攻击的单位

    // 一系列的get和set函数
    void set_attack(bool isAttack) { this->isAttack = isAttack; }

    bool get_attack() { return isAttack; }

    void set_atk(int atk) { this->atk = atk; }

    int get_atk() { return atk; }

    void set_rng(int rng) { this->rng = rng; }

    int get_rng() { return rng; }

    void set_allLife(int allLife) { this->allLife = allLife; }

    int get_allLife() { return allLife; }

    void set_existLife(int existLife) { this->existLife = existLife; }

    int get_existLife() { return existLife; }

    void set_map(Map *my_map) { this->my_map = my_map; }

    void set_IsDep(bool isDeploy) { this->isDeploy = isDeploy; }

    bool get_IsDep() { return isDeploy; }

    void set_cost(int cost) { this->cost = cost; }

    int get_cost() { return this->cost; }

    void set_build(build *b) { this->my_build = b; }

    void set_range(bool isR) { this->isRange = isR; }

    bool get_range() { return this->isRange; }
};

#endif // TOWER_H
