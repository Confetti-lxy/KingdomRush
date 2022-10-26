#include "build.h"


build::build(QWidget *page) {
    this->page = page;
    if (!RemoteCellImg.load("C:/Users/hp/Desktop/KingdomRush/image/remote_cell.png")) {
        qDebug() << "picture loaded failed";
        return;
    }
    if (!CircleImg.load("C:/Users/hp/Desktop/KingdomRush/image/circle.png")) {
        qDebug() << "picture loaded failed";
        return;
    }

    Circle = new QLabel;
    Circle->hide();
    Circle->setParent(page);
    Circle->setFixedSize(CircleImg.width(), CircleImg.height());
    Circle->setStyleSheet("QPushButton{border:Opx;}");
    Circle->setPixmap(CircleImg);
    Circle->setBaseSize(QSize(CircleImg.width(), CircleImg.height()));
    Circle->setAttribute(Qt::WA_TransparentForMouseEvents);
    setFixedSize(RemoteCellImg.width(), RemoteCellImg.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(RemoteCellImg);
    setIconSize(QSize(RemoteCellImg.width(), RemoteCellImg.height()));
    setAttribute(Qt::WA_TransparentForMouseEvents);
    show();

    auto *tower1 = new architecture("C:/Users/hp/Desktop/KingdomRush/image/tower_1_btn.png"),
            *tower2 = new architecture("C:/Users/hp/Desktop/KingdomRush/image/tower_2_btn.png"),
            *tower3 = new architecture("C:/Users/hp/Desktop/KingdomRush/image/tower_3_btn.png");
    buttons.push_back(tower1);
    buttons.push_back(tower2);
    buttons.push_back(tower3);
    for (auto button: buttons) {
        button->setParent(page);
        button->hide();
    }
}

void build::PressEvent(int x, int y) {
    if (state) {
        if (isClicked) {
            isClicked = false;
            Circle->hide();
            for (auto button: buttons) {
                button->hide();
            }
        } else {
            if (x >= this->x() && x <= this->x() + this->width()
                && y >= this->y() && y <= this->y() + this->height()) {

                double x_ = this->x() + 0.5 * this->width() - 0.5 * Circle->width();
                double y_ = this->y() + 0.5 * this->height() - 0.5 * Circle->height();
                Circle->move(int(x_), int(y_));
                Circle->show();
                Circle->raise();
                // 参数待定
                buttons[0]->move(Circle->x() + 47, Circle->y() + 2);
                buttons[1]->move(Circle->x() + 85, Circle->y() + 55);
                buttons[2]->move(Circle->x() + 9, Circle->y() + 55);


                for (auto button: buttons) {
                    button->show();
                    button->raise();
                }
                isClicked = true;
            }
        }
    }
}

void build::setState(bool s) {
    this->state = s;
}

void build::setRng(int r) {
    this->rng = r;
}
