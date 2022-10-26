#ifndef ARCHITECTURE_H
#define ARCHITECTURE_H

#include "Common/common.h"


class architecture : public QPushButton {
public:
private:
    Q_OBJECT
            QString
    architectureLoc;

public:
    explicit architecture(const QString &architecturePath);

    signals:
};

#endif // ARCHITECTURE_H
