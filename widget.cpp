#include "widget.h"
#include "ui_widget.h"
#include "Map/map.h"
#include "Common/Button/ticket.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("Kingdom Rush！");// 设置标题
    this->setWindowIcon(QPixmap(":/image/Icon.png"));// 设置图标
    Map my_map(":/mapfile/mapfile1.txt");
    this->setFixedSize(my_map.get_len(), my_map.get_height());
    ticket *start = new ticket(":/image/start1.png", ":/image/start2.png");// 游戏开始的那个栏目
    start->move(370, 315), start->setParent(this);
    // 播放背景音乐
    QSoundEffect * startSound = new QSoundEffect(this);//创建对象
    startSound->setSource(QUrl::fromLocalFile(":/music/backMusic.wav"));//添加资源
    startSound->setLoopCount(QSoundEffect::Infinite);//设置循环次数int；  QSoundEffect::Infinite 枚举值 无限循环
    startSound->play();//软件启动自动播放
    status = new QLabel;
    // 加载选关界面
    QPixmap level;
    if (!level.load(":/image/levelchoose.png")) {
        qDebug() << "picture load fail";
        return;
    }
    status->setParent(this);
    status->setPixmap(level);
    status->hide(), status->setBaseSize(level.width(), level.height());
    // 点击时上下震动的动作
    connect(start, &QPushButton::clicked, [=]() {
        start->zoom();
        QTimer::singleShot(300, [=]() {
            status->show(), set_state(true);
        });
    });
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *) {
    // 绘制底层模块和游戏封面
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/image/menu.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *click) {
    // 鼠标选关界面，点击具体的地点可以进入对应的关卡
    if (state) {
        if (click->pos().x() >= 222 && click->pos().x() <= 327
            && click->pos().y() >= 180 && click->pos().y() <= 280) {
            level *L1 = new level(1);levelConnect(L1);
        } else if (click->pos().x() >= 486 && click->pos().x() <= 564
                   && click->pos().y() >= 63 && click->pos().y() <= 162) {
            level *L2 = new level(2);levelConnect(L2);
        } else {
            qDebug() << "no epoch";
        }
    }
}
