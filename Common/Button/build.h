#ifndef BUILD_H
#define BUILD_H

#include "architecture.h"


class build : public QPushButton {

private:
    QPixmap RemoteCellImg, CircleImg;
    QLabel *Circle;
    QWidget *page;
    bool isClicked = false, state = true;
    int rng;
    vector<architecture *> architectures;

public:

    explicit build(QWidget *page);

    void PressEvent(int x, int y);

    void setState(bool s);

    void setRng(int r);
};

#endif // BUILD_H
