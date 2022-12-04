#include "arrowtower.h"

arrowTower::arrowTower() {
    if (!TowerImage.load(":/image/tower2.png")) {
        qDebug() << "picture load fail";
        return;
    }
    SetBase(TowerImage)
    setAttribute(Qt::WA_TransparentForMouseEvents);
    set_atk(200), set_rng(3);
    set_cost(80);
    set_allLife(3000), set_existLife(3000);
    my_range->set_r(get_rng() * 140);
}
