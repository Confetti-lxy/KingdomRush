#include "widget.h"
#include "ui_widget.h"
#include "Map/map.h"
#include "Common/Button/ticket.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QLabel *status = new QLabel;
    QPixmap level;
    this->setWindowTitle("Kingdom Rush！");
    this->setWindowIcon(QPixmap("C:/Users/hp/Desktop/KingdomRush/image/Icon.png"));
    Map my_map("C:/Users/hp/Desktop/KingdomRush/MapFile/mapfile.txt");
    this->setFixedSize(my_map.get_len(), my_map.get_height());
    ticket *start = new ticket("C:/Users/hp/Desktop/KingdomRush/image/start1.png",
                               "C:/Users/hp/Desktop/KingdomRush/image/start2.png");
    start->move(370, 315);
    start->setParent(this);
    bool ret = level.load("C:/Users/hp/Desktop/KingdomRush/image/levelchoose.png");
    if (!ret) {
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
        QTimer::singleShot(200, [=]() {
            status->show();
            state = true;
        });
    });
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("C:/Users/hp/Desktop/KingdomRush/image/map1.png"));
    painter.drawPixmap(0, 0, QPixmap("C:/Users/hp/Desktop/KingdomRush/image/menu.jpg"));
}


