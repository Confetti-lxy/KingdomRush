#ifndef DEFENDERSTATE_H
#define DEFENDERSTATE_H


#include "./Common/common.h"
#include "./Friend/Defender/defender.h"

class defender;

class defenderState:public QLabel{
private:
    defender* buffDefender;// 受到增幅的塔单位
    QPixmap buffImage;// 增幅状态的显示
public:
    DefenderBuff Type;// buff的类型
    defenderState(defender*d,DefenderBuff t);// 构造函数
};

#endif // DEFENDERSTATE_H
