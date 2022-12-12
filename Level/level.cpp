#include "level.h"

int coins;// 剩余金币
QVector<bullet*> bullets;// 射出的子弹指针的集合

void level::FriDefenderInit() {
    // soldier单位的初始化以及按钮的设置
    soldierModel = new soldier;
    defenderInit(soldierModel, 950, 0, 930, 0);

    // guard单位的初始化以及按钮的设置
    guardModel = new guard;
    defenderInit(guardModel, 950, 120, 930, 120);

    // dragon单位的初始化以及按钮的设置
    dragonModel = new dragon;
    defenderInit(dragonModel, 880, 240, 930, 240);
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

    // 增益词条的加载
    draw(labels.berserk,950,360);
    draw(labels.glacial,950,380);
    draw(labels.massInjured,950,400);
    draw(labels.bleeding,950,420);


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

    for(auto b:bullets) {
        delete b;
    }
    bullets.clear();

    // 远程地块的清理
    for (int i = 0; i < my_map->allRemotes.size(); i++) {
        my_map->allRemotes[i]->setState(false);
    }
}

void level::putDown() {
    // soilder单位的再部署
    if (soldierModel->get_IsDep()) {
        AllDefender.append(soldierModel);
        soldierModel = new soldier;
        defenderInit(soldierModel, 950, 0, 930, 0);
        if(this->s1) {
            defenderState* d = new defenderState(soldierModel, Berserk);
            soldierModel->states.append(d);
            this->s1 = false;
        }
        else if(this->s2) {
            defenderState* d = new defenderState(soldierModel, Glacial);
            soldierModel->states.append(d);
            this->s2 = false;
        }
        else {
            defenderState* d = new defenderState(soldierModel, MassInjured);
            soldierModel->states.append(d);
            this->s3 = false;
        }
        soldierModel->statusChecking();
    }
    // guard单位的再部署
    if (guardModel->get_IsDep()) {
        AllDefender.append(guardModel);
        guardModel = new guard;
        defenderInit(guardModel, 950, 120, 930, 120);
        if(this->s1) {
            defenderState* d = new defenderState(soldierModel, Berserk);
            soldierModel->states.append(d);
            this->s1 = false;
        }
        else if(this->s2) {
            defenderState* d = new defenderState(soldierModel, Glacial);
            soldierModel->states.append(d);
            this->s2 = false;
        }
        else {
            defenderState* d = new defenderState(soldierModel, MassInjured);
            soldierModel->states.append(d);
            this->s3 = false;
        }
        soldierModel->statusChecking();
    }
    // dragon单位的再部署
    if (dragonModel->get_IsDep()) {
        AllDefender.append(dragonModel);
        dragonModel = new dragon;
        defenderInit(dragonModel, 880, 240, 930, 240);
        if(this->s1) {
            defenderState* d = new defenderState(soldierModel, Berserk);
            soldierModel->states.append(d);
            this->s1 = false;
        }
        else if(this->s2) {
            defenderState* d = new defenderState(soldierModel, Glacial);
            soldierModel->states.append(d);
            this->s2 = false;
        }
        else {
            defenderState* d = new defenderState(soldierModel, MassInjured);
            soldierModel->states.append(d);
            this->s3 = false;
        }
        soldierModel->statusChecking();
    }
}

level::level() {
    // 默认的构造函数，此处不再调用
}

level::level(int Level) {
    // 基础页面设置
    this->setFixedSize(1050, 630);
    this->setWindowIcon(QPixmap(":/image/Icon.png"));
    //---------------------------------------------------------------------------
    // 加载地图文件参数，构造地图地块的图片素材
    QString file = ":/mapfile/mapfile" + QString::number(Level) + ".txt";
    QString filename = "关卡" + QString::number(Level);
    my_map = new Map(file);
    my_map->update(this);
    this->setWindowTitle(filename);
    //---------------------------------------------------------------------------
    // 3种近战单位, 标签组件, 按钮组件的初始化
    FriDefenderInit(), labelInit(), buttonInit();
    // 结束初始等待时间后敌人开始出动
    timer0 = new QTimer(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer0->start(100);
    connect(timer0, &QTimer::timeout, this, &level::makeWar);
    // 远程部署地块的图层绘制
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
                if(this->s4) {
                    towerState* b = new towerState(t, Bleeding);
                    t->states.append(b);
                    this->s4 = false;
                }
                //-----------------------------------------
                // 防御塔单位的部署
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
                //-----------------------------------------
            });
            i++;
        }
    }
}

void level::gameStart() {
    // 游戏开始
    timer1->start(1000);
    connect(timer1, &QTimer::timeout, [=]() { coins += 10; });
    EnemyDistribution(10, 5, 5, 5);
}

void level::makeWar() {
    labels.moneyNum->setText(QString::number(coins));
    labels.lifeNum->setText(QString::number(existLife));
    if(this->s1) {
        labels.berserk->setText("berserk");
    }
    else {
        labels.berserk->setText("");
    }
    if(this->s2) {
        labels.glacial->setText("glacial");
    }
    else {
        labels.glacial->setText("");
    }
    if(this->s3) {
        labels.massInjured->setText("massInjured");
    }
    else {
        labels.massInjured->setText("");
    }
    if(this->s4) {
        labels.bleeding->setText("bleeding");
    }
    else {
        labels.bleeding->setText("");
    }

    //---------------------------------------------------
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
    //---------------------------------------------------
    // 再部署
    putDown();
    int deadNum = 0;
    //---------------------------------------------------
    // 敌我单位的动作，包括移动，攻击，死亡退场
    // 敌方单位的攻击
    for (auto enemy: AllEnemy) {
        if (!enemy->statusChecking()) {
            deadNum++;
            if(enemy->count1||enemy->count2||enemy->count3) {
                if(enemy->count1) {
                    this->s1 = true;
                    enemy->count1  = false;
                }
                else if(enemy->count2) {
                    this->s2 = true;
                    enemy->count2 = false;
                }
                else {
                    this->s3 = true;
                    enemy->count3 = false;
                }
                if(deadNum % 2 == 0 ) {
                    this->s4 = true;
                }
            }
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
    // 友方单位的攻击
    for (auto defender: AllDefender) {
        if (defender->statusChecking()) {
            //------------------------------------------------------------
            // 修改后可以持续攻击
            if(defender->get_blockEnemy().size() < defender->get_block()) {
                for (auto enemy: AllEnemy) {
                    if (defender->add_enemy(enemy)) {
                        defender->attack();
                    }
                    if(defender->get_blockEnemy().size() == defender->get_block()) {
                        break;
                    }
                }
            }
            defender->attack();
            //------------------------------------------------------------
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
    //---------------------------------------------------
    // 判断游戏胜利
    if (deadNum == enemyNum) {
        isWin = true;
    }
}

void level::restart() {
    // 游戏重新开始，将所有参数调整至初始状态
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
    int groundNum = 1, sleepTime;
    enemyNum = num1 + num2 + num3 + num4;
    for (auto road: my_map->allRoads) {
        if (road.get_type() == ground_road) {
            groundNum++;
        }
    }
    timer2->start(100);
    //-----------------------------------------------------------------------------
    // 4种敌方单位的出兵
    for (int i = 0; i < num1; i++) {
        enemy *barbarianModel = new barbarian;
        barbarianModel->show();
        barbarianModel->my_map = this->my_map;
        AllEnemy.append(barbarianModel);
        sleepTime = (2000.0) / groundNum;
        barbarianModel->setParent(this);
        int roadIdx = i % groundNum;
        barbarianModel->set_index(roadIdx);
        //--------------------------------------------------------
        // 添加标签
        if(i % 5 == 0) {
            enemyState * e;
            if((i / 5) % 3 == 0) {
                e= new enemyState(barbarianModel, Speed);
            }
            else if((i / 5) % 3 == 1) {
                e = new enemyState(barbarianModel, Powered);
            }
            else {
                e = new enemyState(barbarianModel, Flash);
            }
            barbarianModel->states.append(e);
        }
        //--------------------------------------------------------
        connect(timer2, &QTimer::timeout, [=]() {
            if(!barbarianModel->beFrozen) {
                barbarianModel->add_dis(barbarianModel->get_speed());
            }
            if(isDoubleSpeed) {
                barbarianModel->add_dis(barbarianModel->get_speed());
            }
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
        //--------------------------------------------------------
        // 添加标签
        if(i % 5 == 0) {
            enemyState * e   ;
            if((i / 5) % 3 == 0) {
                e= new enemyState(remoteenemyModel, Speed);
            }
            else if((i / 5) % 3 == 1) {
                e = new enemyState(remoteenemyModel, Powered);
            }
            else {
                e = new enemyState(remoteenemyModel, Flash);
            }
            remoteenemyModel->states.append(e);
        }
        //--------------------------------------------------------
        connect(timer2, &QTimer::timeout, [=]() {
            if(!remoteenemyModel->beFrozen) {
                remoteenemyModel->add_dis(remoteenemyModel->get_speed());
            }
            if(isDoubleSpeed) {
                remoteenemyModel->add_dis(remoteenemyModel->get_speed());
            }
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
        //--------------------------------------------------------
        // 添加标签
        if(i % 5 == 0) {
            enemyState * e;
            if((i / 5) % 2 == 0) {
                e= new enemyState(gargoyleModel, Speed);
            }
            else {
                e = new enemyState(gargoyleModel, Powered);
            }
            gargoyleModel->states.append(e);
        }
        //--------------------------------------------------------
        connect(timer2, &QTimer::timeout, [=]() {
            if(!gargoyleModel->beFrozen) {
                gargoyleModel->add_dis(gargoyleModel->get_speed());
            }
            if(isDoubleSpeed) {
                gargoyleModel->add_dis(gargoyleModel->get_speed());
            }
            gargoyleModel->enemyMove(roadIdx, gargoyleModel->get_dis());
            if (gargoyleModel->statusChecking())
                gargoyleModel->show();
        });
        Sleep(sleepTime);
    }
    for (int i = 0; i < num4; i++) {
        enemy *raptorModel = new raptor;
        raptorModel->show();
        raptorModel->my_map = this->my_map;
        AllEnemy.append(raptorModel);
        sleepTime = (2000.0) / groundNum;
        raptorModel->setParent(this);
        int roadIdx = i % groundNum;
        raptorModel->set_index(roadIdx);
        //--------------------------------------------------------
        // 添加标签
        if(i % 5 == 0) {
            enemyState * e;
            if((i / 5) % 2 == 0) {
                e= new enemyState(raptorModel, Speed);
            }
            else {
                e = new enemyState(raptorModel, Powered);
            }
            raptorModel->states.append(e);
        }
        //--------------------------------------------------------
        connect(timer2, &QTimer::timeout, [=]() {
            if(!raptorModel->beFrozen) {
                raptorModel->add_dis(raptorModel->get_speed());
            }
            if(isDoubleSpeed) {
                raptorModel->add_dis(raptorModel->get_speed());
            }
            raptorModel->enemyMove(roadIdx, raptorModel->get_dis());
            if (raptorModel->statusChecking())
                raptorModel->show();
        });
        Sleep(sleepTime);
    }
    //-----------------------------------------------------------------------------
}

void level::Sleep(int sec) {
    QTime waitTime = QTime::currentTime().addMSecs(sec);
    while (QTime::currentTime() < waitTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void level::mousePressEvent(QMouseEvent *event) {
    // 点击部署
    for (auto remoteCell: my_map->allRemotes) {
        remoteCell->PressEvent(event->pos().x(), event->pos().y());
    }
    // 点击显示塔的攻击范围
    for (auto t: AllTower) {
        t->show_rng(event->pos().x(), event->pos().y());
    }
    //------------------------------------------------------------------------------
    // 点击切换一倍速和二倍速
    if (!isDoubleSpeed && event->pos().x() >= labels.oneSpeed->x()
        && event->pos().x() <= labels.oneSpeed->x() + labels.oneSpeed->width()
        && event->pos().y() >= labels.oneSpeed->y()
        && event->pos().y() <= labels.oneSpeed->y() + labels.oneSpeed->height()) {
        isDoubleSpeed = true;
        labels.oneSpeed->hide();
        labels.doubleSpeed->show();
        timer2->setInterval(100);
        timer1->setInterval(100);
        timer0->setInterval(100);
        return;
    }
    if (isDoubleSpeed && event->pos().x() >= labels.doubleSpeed->x()
        && event->pos().x() <= labels.doubleSpeed->x() + labels.doubleSpeed->width()
        && event->pos().y() >= labels.doubleSpeed->y()
        && event->pos().y() <= labels.doubleSpeed->y() + labels.doubleSpeed->height()) {
        isDoubleSpeed = false;
        labels.doubleSpeed->hide();
        labels.oneSpeed->show();
        timer2->setInterval(200);
        timer1->setInterval(200);
        timer0->setInterval(200);
        return;
    }
    //------------------------------------------------------------------------------
}
