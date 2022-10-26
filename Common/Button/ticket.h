#ifndef TICKET_H
#define TICKET_H

#include "Common/common.h"

class ticket : public QPushButton {

private:
    Q_OBJECT
            QString
    routineImg,
    activationImg;

public:
    ticket(QString routineImg, QString activationImg);

    void zoomUp();

    void zoomDown();
};

#endif // TICKET_H
