#include "enemy.h"

enemy::enemy() {
    rng = 1;
    speed = 2;
    isAlive = true;
    isAttack = false;
    isImg1 = true;
    allLife = 100;
    existLife = 100;
}


EnemyType enemy::get_type() {
    return type;
}


EnemyDirection enemy::get_direction() {
    return enemyDirection;
}


void enemy::set_direction(EnemyDirection dir) {
    this->enemyDirection = dir;
}


bool enemy::get_attack() {
    return isAttack;
}

void enemy::set_attack(bool isAttack) {
    this->isAttack = isAttack;
}

void enemy::set_alive(bool isAlive) {
    this->isAlive = isAlive;
}

bool enemy::get_alive() {
    return isAlive;
}

bool enemy::get_img1() {
    return isImg1;
}

void enemy::set_img1(bool isImg1) {
    this->isImg1 = isImg1;
}


void enemy::set_allLife(int allLife) {
    this->allLife = allLife;
}

int enemy::get_allLife() {
    return allLife;
}

void enemy::set_existLife(int existLife) {
    this->existLife = existLife;
}

int enemy::get_existLife() {
    return existLife;
}

void enemy::set_atk(int atk) {
    this->atk = atk;
}

int enemy::get_atk() {
    return atk;
}

void enemy::set_rng(int rng) {
    this->rng = rng;
}

int enemy::get_rng() {
    return rng;
}
























