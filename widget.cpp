#include "widget.h"
#include "ui_widget.h"
#include "Map/map.h"
#include "Common/Button/ticket.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent), ui(new Ui::Widget) {

    ui->setupUi(this);
    this->setWindowTitle("Kingdom Rush！");
    this->setWindowIcon(QPixmap(":/image/Icon.png"));
    Map my_map(":/mapfile/mapfile1.txt");
    this->setFixedSize(my_map.get_len(), my_map.get_height());
    ticket *start = new ticket(":/image/start1.png",
                               ":/image/start2.png");
    start->move(370, 315);
    start->setParent(this);
    status = new QLabel;
    QPixmap level;
    if (!level.load(":/image/levelchoose.png")) {
        qDebug() << "picture load fail";
        return;
    }
    status->setParent(this);
    status->setPixmap(level);
    status->hide();
    status->setBaseSize(level.width(), level.height());
    connect(start, &QPushButton::clicked, [=]() {
        start->zoomDown();
        start->zoomUp();
        QTimer::singleShot(300, [=]() {
            status->show();
            set_state(true);
        });
    });
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/image/map1.png"));
    painter.drawPixmap(0, 0, QPixmap(":/image/menu.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *click) {
    if (state) {
        if (click->pos().x() >= 222 && click->pos().x() <= 327
            && click->pos().y() >= 180 && click->pos().y() <= 280) {
            level *L1 = new level(1);
            levelConnect(L1);
        } else if (click->pos().x() >= 486 && click->pos().x() <= 564
                   && click->pos().y() >= 63 && click->pos().y() <= 162) {
            level *L2 = new level(2);
            levelConnect(L2)
        } else {
            qDebug() << "no epoch";
        }
    }
}







































