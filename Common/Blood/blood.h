#ifndef BLOOD_H
#define BLOOD_H

#include "Common/common.h"


class blood : public QLabel {
private:
    int len = 70;// 总长度
    int t = 0;//

public:
    QColor color;
    blood();// 构造函数
    void paintEvent(QPaintEvent *);

    // 一系列的get和set函数
    void set_len(int len) { this->len = len; }

    int get_len() { return this->len; }

    void set_t(int t) { this->t = t; }

    int get_t() { return this->t; }
};

#endif // BLOOD_H
