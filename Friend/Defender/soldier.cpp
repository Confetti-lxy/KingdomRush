#include "soldier.h"

void soldier::load() {
    defenderDeploy = new deploy(":/Image/soldier1_btn.jpg");
    if (!defenderImage.soldierImg.load(":/Image/soldier1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!defenderImage.soldierattackleft1_Img.load(":/Image/soldier1attackleft1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!defenderImage.soldierattackleft2_Img.load(":/Image/soldier1attackleft2.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!defenderImage.soldierattackright1_Img.load(":/Image/soldier1attackright1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!defenderImage.soldierattackright2_Img.load(":/Image/soldier1attackright2.png")) {
        qDebug() << "picture load fail";
        return;
    }
}

soldier::soldier() {
    soldier::load();
    setBase(defenderImage.soldierImg);
    Type = Soldier;
    set_atk(400), set_rng(1);
    set_allLife(5000), set_existLife(5000);
    set_block(2);
}


void soldier::attackAnimation(enemy *blockedEnemy) {
    if (x() < blockedEnemy->x()) {
        if (!get_atkImg()) {
            setPixmap(defenderImage.soldierattackright1_Img);
            raise();
            set_atkImg(true);
        } else {
            setPixmap(defenderImage.soldierattackright2_Img);
            raise();
            set_atkImg(false);
        }
    } else {
        if (!get_atkImg()) {
            setPixmap(defenderImage.soldierattackleft1_Img);
            raise();
            set_atkImg(true);
        } else {
            setPixmap(defenderImage.soldierattackleft2_Img);
            raise();
            set_atkImg(false);
        }
    }
}













































