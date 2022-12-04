#include "mercenarytower.h"

mercenaryTower::mercenaryTower() {
    if (!TowerImage.load(":/image/tower3.png")) {
        qDebug() << "picture load fail";
        return;
    }
    SetBase(TowerImage)
    setAttribute(Qt::WA_TransparentForMouseEvents);
    set_atk(400), set_rng(2);
    set_cost(80);
    set_allLife(4000), set_existLife(4000);
    my_range->set_r(get_rng() * 140);
}
