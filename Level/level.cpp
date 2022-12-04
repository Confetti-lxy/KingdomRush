#include "level.h"

int coins;// 剩余金币

void level::FriDefenderInit() {
    // soldier单位的初始化以及按钮的设置
    soldierModel = new soldier;
    defenderInit(soldierModel, 950, 20, 930, 20);

    // guard单位的初始化以及按钮的设置
    guardModel = new guard;
    defenderInit(guardModel, 950, 170, 930, 170);

    // dragon单位的初始化以及按钮的设置
    dragonModel = new dragon;
    defenderInit(dragonModel, 880, 320, 930, 320);
}

void level::labelInit() {
    QPixmap pix;

    // 一倍速图片素材的加载
    pix.load(":/image/speed1.png");
    pointerSet(labels.oneSpeed, 930, 450)

    // 二倍速图片素材的加载
    pix.load(":/image/speed2.png");
    pointerSet(labels.doubleSpeed, 930, 450)
    labels.doubleSpeed->hide();

    // 钱素材的加载
    coins = 500;
    pix.load(":/image/money.png");
    pointerSet(labels.moneyLabel, 930, 560)
    labels.moneyLabel->setStyleSheet("QPushButton{border:0px;}");
    labels.moneyLabel->setBaseSize(QSize(pix.width(), pix.height()));

    // 钱数字的加载
    labels.moneyNum = new QLabel;
    labels.moneyNum->setParent(this);
    labels.moneyNum->move(975, 560);
    labels.moneyNum->setFixedSize(pix.width(), pix.height());
    labels.moneyNum->setBaseSize(QSize(pix.width(), pix.height()));
    labels.moneyNum->raise();

    // 生命素材的加载
    existLife = 10;
    pix.load(":/image/life.png");
    pointerSet(labels.lifeLabel, 930, 520)
    labels.lifeLabel->setStyleSheet("QPushButton{border:0px;}");
    labels.lifeLabel->setBaseSize(QSize(pix.width(), pix.height()));

    // 生命数字的加载
    labels.lifeNum = new QLabel;
    labels.lifeNum->setParent(this);
    labels.lifeNum->move(975, 520);
    labels.lifeNum->setFixedSize(pix.width(), pix.height());
    labels.lifeNum->setBaseSize(QSize(pix.width(), pix.height()));
    labels.lifeNum->raise();

    // 胜利图片的加载
    pix.load(":/image/win.png");
    labels.victoryInterface = new QLabel;
    labels.victoryInterface->setParent(this);
    labels.victoryInterface->setGeometry(0, 0, pix.width(), pix.height());
    labels.victoryInterface->setPixmap(pix);
    labels.victoryInterface->move(0.5 * (this->width() - pix.width()), -pix.height());

    // 失败图片的加载
    pix.load(":/image/fail.png");
    labels.failureInterface = new QLabel;
    labels.failureInterface->setParent(this);
    labels.failureInterface->setGeometry(0, 0, pix.width(), pix.height());
    labels.failureInterface->setPixmap(pix);
    labels.failureInterface->move(0.5 * (this->width() - pix.width()), -pix.height());
}

void level::buttonInit() {
    QPixmap pix;
    // 返回按钮的加载
    pix.load(":/image/back.png");
    pointerSetIcon(buttons.back)
    connect(buttons.back, &QPushButton::clicked, this, [=]() {

        emit levelBack();
    });

    // 重新开始按钮的加载
    pix.load(":/image/again.png");
    pointerSetIcon(buttons.reopen)
    connect(buttons.reopen, &QPushButton::clicked, this, &level::restart);
}

void level::clearCompany() {
    // 时间单位的清除
    timer0->stop(), timer1->stop(), timer2->stop();

    // 友方以及敌方单位的清除
    for (auto tower: AllTower) {
        tower->hide();
    }
    AllTower.clear();
    for (auto defender: AllDefender) {
        defender->hide();
    }
    AllDefender.clear();
    for (auto enemy: AllEnemy) {
        enemy->set_alive(false);
        enemy->hide();
    }
    AllEnemy.clear();

    // 远程地块的清理
    for (int i = 0; i < my_map->allRemotes.size(); i++) {
        my_map->allRemotes[i]->setState(false);
    }
}

void level::putDown() {
    if (soldierModel->get_IsDep()) {
        AllDefender.append(soldierModel);
        soldierModel = new soldier;
        defenderInit(soldierModel, 950, 20, 930, 20);
    }
    if (guardModel->get_IsDep()) {
        AllDefender.append(guardModel);
        guardModel = new guard;
        defenderInit(guardModel, 950, 170, 930, 170);
    }
    if (dragonModel->get_IsDep()) {
        AllDefender.append(dragonModel);
        dragonModel = new dragon;
        defenderInit(dragonModel, 880, 320, 930, 320);
    }
}

level::level() {

}

level::level(int Level) {
    // 基础页面设置
    this->setFixedSize(1050, 630);
    this->setWindowIcon(QPixmap(":/image/Icon.png"));

    // 加载地图文件参数，构造地图地块的图片素材
    QString file = ":/mapfile/mapfile" + QString::number(Level) + ".txt";
    QString filename = "关卡" + QString::number(Level);
    my_map = new Map(file);
    my_map->update(this);
    this->setWindowTitle(filename);

    // 3种近战单位, 标签组件, 按钮组件的初始化
    FriDefenderInit(), labelInit(), buttonInit();

    // 结束初始等待时间后敌人开始出动
    timer0 = new QTimer(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer0->start(100);
    connect(timer0, &QTimer::timeout, this, &level::makeWar);

//     远程部署地块的图层绘制
    for (auto remoteSell: my_map->allRemotes) {
        int i = 1;
        for (auto buildSell: remoteSell->architectures) {
            // 防御塔图片素材的加载
            connect(buildSell, &architecture::clicked, [=]() {
                tower *t;
                if (i == 1) {
                    t = new fireTower;
                } else if (i == 2) {
                    t = new arrowTower;
                } else {
                    t = new mercenaryTower;
                }
                t->set_map(my_map);
                if (coins >= t->get_cost()) {
                    t->setParent(this);
                    t->set_build(remoteSell);
                    t->move(remoteSell->x(), remoteSell->y());
                    AllTower.append(t);
                    t->show();
                    coins -= t->get_cost();
                    remoteSell->PressEvent(-1, -1);
                    remoteSell->setState(false);
                } else {
                    remoteSell->PressEvent(-1, -1);
                }
            });
            i++;
        }
    }
}

void level::gameStart() {
    timer1->start(1000);
    connect(timer1, &QTimer::timeout, [=]() {
        coins += 10;
    });
    EnemyDistribution(10, 5, 5, 5);
}

void level::makeWar() {
    labels.moneyNum->setText(QString::number(coins));
    labels.lifeNum->setText(QString::number(existLife));
    // 游戏结束的结算
    if (isWin || (existLife <= 0 && !isOver)) {
        clearCompany();
        if (isWin) {
            // 胜利结算页面
            FaceBounce(labels.victoryInterface)
            labels.victoryInterface->raise();
            QTimer::singleShot(1000, [=]() {
                buttons.back->move(560, labels.victoryInterface->y() + 448);
                buttons.back->show();
                buttons.reopen->move(440, labels.victoryInterface->y() + 448);
                buttons.reopen->show();
                buttons.back->raise();
                buttons.reopen->raise();
            });
        } else {
            // 失败结算页面
            isOver = true;
            FaceBounce(labels.failureInterface)
            QTimer::singleShot(1000, [=]() {
                buttons.back->move(550, labels.failureInterface->y() + 407);
                buttons.back->show();
                buttons.reopen->move(430, labels.failureInterface->y() + 407);
                buttons.reopen->show();
                buttons.back->raise();
                buttons.reopen->raise();
            });
        }
    }

    // 再部署
    putDown();
    int deadNum = 0;
    for (auto enemy: AllEnemy) {
        if (!enemy->statusChecking()) {
            deadNum++;
            enemy->hide();
        } else {
            enemy->moveAnimation();
            if (enemy->get_arrive()) {
                existLife--;
            }

        }
        for (auto defender: AllDefender) {
            if (enemy->judge_defender(defender)) {
                break;
            }
        }
    }
    // 判断游戏胜利
    if (deadNum == enemyNum) {
        isWin = true;
    }
    // 友方单位的攻击
    for (auto defender: AllDefender) {
        if (defender->statusChecking()) {
            for (auto enemy: AllEnemy) {
                if (defender->add_enemy(enemy)) {
                    defender->attack();
                    break;
                }
            }
        }
    }
    // 友方防御塔的攻击
    for (auto tower: AllTower) {
        if (tower->statusChecking()) {
            for (auto enemy: AllEnemy) {
                if (tower->judge_enemy(enemy)) {
                    break;
                }
            }
        }
    }
}

void level::restart() {
    isDoubleSpeed = false, isOver = false, isWin = false;
    enemyNum = 100, coins = 500, existLife = 10;
    for (int i = 0; i < my_map->allRemotes.size(); i++) {
        my_map->allRemotes[i]->setState(true);
        my_map->allRemotes[i]->setRng(0);
    }
    timer0->start(100), timer1->start(1000), timer2->start(100);
    labels.doubleSpeed->hide();
    labels.oneSpeed->show();
    labels.failureInterface->hide();
    labels.victoryInterface->hide();
    buttons.back->hide();
    buttons.reopen->hide();
    EnemyDistribution(10, 5, 5, 5);
}

void level::EnemyDistribution(int num1, int num2, int num3, int num4) {
    int groundNum = 0, sleepTime;
    enemyNum = num1 + num3 + num4;
    for (auto road: my_map->allRoads) {
        if (road.get_type() == ground_road) {
            groundNum++;
        }
    }
    timer2->start(100);
    for (int i = 0; i < num1; i++) {
        enemy *barbarianModel = new barbarian;
        barbarianModel->show();
        barbarianModel->my_map = this->my_map;
        AllEnemy.append(barbarianModel);
        sleepTime = (2000.0) / groundNum;
        barbarianModel->setParent(this);
        int roadIdx = i % groundNum;
        barbarianModel->set_index(roadIdx);
        connect(timer2, &QTimer::timeout, [=]() {
            barbarianModel->add_dis(barbarianModel->get_speed());
            barbarianModel->enemyMove(roadIdx, barbarianModel->get_dis());
            if (barbarianModel->statusChecking())
                barbarianModel->show();
        });
        Sleep(sleepTime);
    }
    for (int i = 0; i < num3; i++) {
        enemy *remoteenemyModel = new remoteenemy;
        remoteenemyModel->show();
        remoteenemyModel->my_map = this->my_map;
        AllEnemy.append(remoteenemyModel);
        sleepTime = (2000.0) / groundNum;
        remoteenemyModel->setParent(this);
        int roadIdx = i % groundNum;
        remoteenemyModel->set_index(roadIdx);
        connect(timer2, &QTimer::timeout, [=]() {
            remoteenemyModel->add_dis(remoteenemyModel->get_speed());
            remoteenemyModel->enemyMove(roadIdx, remoteenemyModel->get_dis());
            if (remoteenemyModel->statusChecking())
                remoteenemyModel->show();
        });
        Sleep(sleepTime);
    }
    for (int i = 0; i < num2; i++) {
        enemy *gargoyleModel = new gargoyle;
        gargoyleModel->show();
        gargoyleModel->my_map = this->my_map;
        AllEnemy.append(gargoyleModel);
        sleepTime = (2000.0) / groundNum;
        gargoyleModel->setParent(this);
        int roadIdx = i % groundNum;
        gargoyleModel->set_index(roadIdx);
        connect(timer2, &QTimer::timeout, [=]() {
            gargoyleModel->add_dis(gargoyleModel->get_speed());
            gargoyleModel->enemyMove(roadIdx, gargoyleModel->get_dis());
            if (gargoyleModel->statusChecking())
                gargoyleModel->show();
        });
        Sleep(sleepTime);
    }
}

void level::Sleep(int sec) {
    QTime waitTime = QTime::currentTime().addMSecs(sec);
    while (QTime::currentTime() < waitTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void level::mousePressEvent(QMouseEvent *event) {
    for (auto remoteCell: my_map->allRemotes) {
        remoteCell->PressEvent(event->x(), event->y());
    }
    for (auto t: AllTower) {
        t->show_rng(event->x(), event->y());
    }
    if (!isDoubleSpeed && event->x() >= labels.oneSpeed->x()
        && event->x() <= labels.oneSpeed->x() + labels.oneSpeed->width()
        && event->y() >= labels.oneSpeed->y()
        && event->y() <= labels.oneSpeed->y() + labels.oneSpeed->height()) {
        isDoubleSpeed = true;
        labels.oneSpeed->hide();
        labels.doubleSpeed->show();
        timer2->setInterval(100);
        timer1->setInterval(100);
        timer0->setInterval(100);
        return;
    }
    if (isDoubleSpeed && event->x() >= labels.doubleSpeed->x()
        && event->x() <= labels.doubleSpeed->x() + labels.doubleSpeed->width()
        && event->y() >= labels.doubleSpeed->y()
        && event->y() <= labels.doubleSpeed->y() + labels.doubleSpeed->height()) {
        isDoubleSpeed = false;
        labels.doubleSpeed->hide();
        labels.oneSpeed->show();
        timer2->setInterval(200);
        timer1->setInterval(200);
        timer0->setInterval(200);
        return;
    }
}


















































