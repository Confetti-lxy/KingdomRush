#include "architecture.h"


architecture::architecture(const QString &architecturePath) {
    this->architectureLoc = architecturePath;
    QPixmap pix;
    if (!pix.load(architectureLoc)) {
        qDebug() << "picture load failed";
        return;
    }
    setFixedSize(pix.width(), pix.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(pix);
    setIconSize(QSize(pix.width(), pix.height()));
}
