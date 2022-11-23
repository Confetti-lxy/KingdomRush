#include "architecture.h"


architecture::architecture(const QString &architecturePath) {
    this->architectureLoc = architecturePath;
    QPixmap pix;
    if (!pix.load(architectureLoc)) {
        qDebug() << "picture load failed";
        return;
    }
    SetIcon(pix);
}
