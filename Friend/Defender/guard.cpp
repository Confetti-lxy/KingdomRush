#include "guard.h"

bool guard::load() {
    my_deploy = new deploy(":/image/soldier2_btn.png");
    if (!guardImg.load(":/image/soldier2.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

guard::guard() {
    // 图片加载，若失败则直接返回
    if (!guard::load()) {
        return;
    }

    // 图片设置
    SetBase(guardImg);

    // soldier单位的数值设计
    Type = Guard;
    set_atk(0), set_rng(0);
    set_allLife(10000), set_existLife(10000);
    set_block(3);
}

void guard::attackAnimation(enemy *blockedEnemy) {
    // 坚果墙类型的单位，不会攻击，因此攻击动画设置为空函数
}

void guard::attack() {
    // 坚果墙类型的单位，不会攻击，因此攻击函数设置为空函数
}

void guard::defenderDeploy(QMouseEvent *click) {
    this->move(click->pos().x() + 895, click->pos().y() + 130);
    this->show();
    this->raise();
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
}

bool guard::location_check(QMouseEvent *click) {
    int Width = my_map->get_width(), Height = my_map->get_height(), Length = my_map->get_len();
    int x_loc = (click->pos().x() + 940) / Width, y_loc = (click->pos().y() + 150) / Width;
    if (x_loc >= 0 && x_loc < Length / Width && y_loc >= 0 && y_loc < Height / Width) {
        if (my_map->get_grid(x_loc, y_loc) == close_cell) {
            defender_x_loc = x_loc * 70, defender_y_loc = y_loc * 70;
            relative_x = x_loc + 0.5 * (Width - width());
            relative_y = y_loc + 0.5 * (Width - height());
            move(x_loc * Width + 0.5 * (Width - width()), y_loc * Width + 0.5 * (Width - height()));
            return true;
        }
    }
    return false;
}



































