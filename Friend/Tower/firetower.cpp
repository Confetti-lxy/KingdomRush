#include "firetower.h"

fireTower::fireTower() {
    if (!TowerImage.load(":/image/tower1.png")) {
        qDebug() << "picture load fail";
        return;
    }
    SetBase(TowerImage)
    setAttribute(Qt::WA_TransparentForMouseEvents);
    set_atk(700), set_rng(1);
    set_cost(80);
    set_allLife(3000), set_existLife(3000);
    my_range->set_r(get_rng() * 140);
}
