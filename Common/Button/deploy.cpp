#include "deploy.h"

deploy::deploy(QString defenderPath) {
    defenderImg = defenderPath;
    QPixmap pix;
    if (!pix.load(defenderImg)) {
        qDebug() << "picture load fail";
        return;
    }
    set(pix);
}
