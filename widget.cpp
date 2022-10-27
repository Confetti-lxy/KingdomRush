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
    this->setWindowIcon(QPixmap(":/image/Icon.png"));
    Map my_map(":/file/mapfile.txt");
    this->setFixedSize(my_map.get_len(), my_map.get_height());
    ticket *start = new ticket(":/image/start1.png",
                               ":/image/start2.png");
    start->move(370, 315);
    start->setParent(this);
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
            state = true;
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


