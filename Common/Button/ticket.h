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
    ticket(QString routineImg, QString activationImg = "");

    void zoomUp();

    void zoomDown();

    void press(QMouseEvent *event);

    void release(QMouseEvent *event);

    signals:
};

#endif // TICKET_H
