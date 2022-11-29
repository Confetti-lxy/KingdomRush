#include "level.h"

int existMoney;// 剩余金币

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
    existMoney = 500;
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
    connect(buttons.back, &QPushButton::clicked, this, [=]() { emit levelBack(); });

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
    timer0 = new QTimer;
    timer0->start(100);
    connect(timer0, &QTimer::timeout, this, &level::makeWar);

    // 远程部署地块的图层绘制
//    for(auto remoteSell: my_map->allRemotes) {
//        for(auto buildSell:remoteSell->architectures) {
//            // 防御塔图片素材的加载
//        }
//    }


}

void level::gameStart() {
    timer1 = new QTimer(this);
    timer1->start(1000);
    connect(timer1, &QTimer::timeout, [=]() {
        existMoney += 10;
    });
    EnemyDistribution(10, 5, 5, 5);
}


void level::makeWar() {
    labels.moneyNum->setText(QString::number(existMoney));
    labels.lifeNum->setText(QString::number(existLife));
    // 游戏结束的结算
    if (isWin || (existLife <= 0 && !isOver)) {
        clearCompany();
        if (isWin) {
            // 胜利结算页面
            FaceBounce(labels.victoryInterface)
            labels.victoryInterface->raise();
            QTimer::singleShot(1000, [=]() {
                buttons.back->move(556, labels.victoryInterface->y() + 448);
                buttons.back->show();
                buttons.reopen->move(436, labels.victoryInterface->y() + 448);
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
    putDown();
    int deadNum = 0;
    for (auto enemy: AllEnemy) {
        if (!enemy->get_alive()) {
            deadNum++;
            enemy->hide();
        } else {
            if (enemy->Type == Barbarian || enemy->Type == Remoteenemy) {
                enemy->moveAnimation();
                if (enemy->get_arrive()) {
                    existLife--;
                }
            }
        }
        for (auto defender: AllDefender) {
            if (enemy->judge_defender(defender)) {
                break;
            }
        }
    }
    // 友方单位的攻击
    for (auto defender: AllDefender) {
        if (defender->get_alive()) {
            for (auto enemy: AllEnemy) {
                if (defender->add_enemy(enemy)) {
                    defender->attack();
                    break;
                }
            }
        }
    }


}


void level::restart() {
    isDoubleSpeed = false, isOver = false, isWin = false;
    enemyNum = 100, existMoney = 500, existLife = 10;
    for (int i = 0; i < my_map->allRemotes.size(); i++) {
        my_map->allRemotes[i]->setState(true);
        my_map->allRemotes[i]->setRng(0);
    }
    timer0->start(100), timer1->start(1000);
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
    timer2 = new QTimer;
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
            if (barbarianModel->get_alive())
                barbarianModel->show();
        });
        Sleep(sleepTime);
    }
}





















































