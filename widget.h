#ifndef WIDGET_H
#define WIDGET_H

#include "Level/level.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT
private:
    Ui::Widget *ui;
    bool state = false;// 状态设置参数
    QLabel *status;
public:
    Widget(QWidget *parent = nullptr);// 构造函数

    void paintEvent(QPaintEvent *);// 绘制基础的图片素材

    void mousePressEvent(QMouseEvent *);// 游戏开始

    ~Widget();// 析构函数



    // 一系列的get和set函数
    void set_state(bool state) { this->state = state; }

    bool get_state() { return this->state; }

    signals:
            void openLevel();
};
#endif // WIDGET_H
