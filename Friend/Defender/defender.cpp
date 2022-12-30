#include "defender.h"

int extern coins;

defender::defender() {
    isAlive = true;
    isAttack = false;
    isAtkImg1 = true;
    blockedEnemys.clear();
    life = new blood;
    life->setParent(this);
    life->show();
    life->raise();
}

bool defender::statusChecking() {
    //---------------------------------------------------
    // 防止dragon单位出现莫名奇妙的位移
    if (Type == Dragon && get_alive() && x() < 0) {
        move(x() + 4623, y());
    }
    //---------------------------------------------------
    if (existLife > 0 && isAlive) {
        if(states.size() == 1) {
            if(states[0]->Type == Berserk) {
                this->life->color.setNamedColor("black");
            }
            else if(states[0]->Type == Glacial) {
                this->life->color.setNamedColor("blue");
            }
            else {
                this->life->color.setNamedColor("green");
            }
        }
        life->set_len(70.0 * existLife / allLife);
        return true;
    } else {
        isAlive = false;
        for (auto blockedEnemy: blockedEnemys) {
            blockedEnemy->set_blocked(false);
        }
        this->blockedEnemys.clear(), this->hide();
        return false;
    }
}

void defender::beAttacked(int atk) {
    existLife -= atk;
}

void defender::mouseReleaseEvent(QMouseEvent *click) {
    if (location_check(click) && coins >= cost) {
        show(), coins -= cost;
        set_IsDep(true);
    } else {
        close();
    }
}

void defender::defenderDeploy(QMouseEvent *click) {
    if (Type == Soldier) {
        this->move(click->pos().x() + 895, click->pos().y() - 20);
    }
    if (Type == Guard) {
        this->move(click->pos().x() + 895, click->pos().y() + 130);
    }
    if (Type == Dragon) {
        this->move(click->pos().x() + 830, click->pos().y() + 280);
    }
    this->show(), this->raise();
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
}

double defender::distance_cal(int enemy_x, int enemy_y) {
    int x = enemy_x - defender_x_loc;
    int y = enemy_y - defender_y_loc;
    return sqrt(x * x + y * y);
}

bool defender::judge_attack(int x, int y) {
    int width = my_map->get_width();
    if (block_num == blockedEnemys.size()) {
        return false;
    }
    else if (distance_cal(x, y) <= width * rng) {
        return true;
    }
    else {
        return false;
    }
}

bool defender::add_enemy(enemy *e) {
    if (e->statusChecking() && blockedEnemys.size() < block_num) {
        if (e->Type == Remoteenemy || e->Type == Barbarian) {
            if(e->openFlash && e->flashCooling) {
                e->flashCooling = false, e->flashDen = this;
            }
            else  {
                if (!e->get_blocked() && judge_attack(e->x(), e->y()) && e->flashDen != this) {
                    blockedEnemys.append(e);
                    e->set_blocked(true), e->flashDen = nullptr;
                    e->flashCooling = true;
                    return true;
                }
            }
        }
    }
    return false;
}























