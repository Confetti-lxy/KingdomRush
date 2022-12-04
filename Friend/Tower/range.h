#ifndef RANGE_H
#define RANGE_H

#include "./Common/common.h"

class range : public QLabel {
private:
    int r = 0, x_r = 0, y_r = 0;// 班级，坐标参数

public:
    range();// 构造函数

    void paintEvent(QPaintEvent *);

    // 一系列的get和set函数

    int get_r() { return this->r; }

    void set_r(int r) { this->r = r; }

    int get_xr() { return this->x_r; }

    void set_xr(int xr) { this->x_r = xr; }

    int get_yr() { return this->y_r; }

    void set_yr(int yr) { this->y_r = yr; }
};

#endif // RANGE_H
