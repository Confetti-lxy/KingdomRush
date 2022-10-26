#ifndef WIDGET_H
#define WIDGET_H

#include "Common/common.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    bool state = false;

    void paintEvent(QPaintEvent *);

    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
