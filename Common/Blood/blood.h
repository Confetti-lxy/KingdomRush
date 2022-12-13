#ifndef BLOOD_H
#define BLOOD_H

#include "Common/common.h"


class blood : public QLabel {
private:
    int len = 70,t = 0;// 总长度

public:
    QColor color;// 用于buff进行血条颜色的调整

    blood();// 构造函数

    void paintEvent(QPaintEvent *);// 血条上色函数

    // 一系列的get和set函数
    void set_len(int len) { this->len = len; }

    int get_len() { return this->len; }

    void set_t(int t) { this->t = t; }

    int get_t() { return this->t; }
};

#endif // BLOOD_H
