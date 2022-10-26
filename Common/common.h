#ifndef COMMON_H
#define COMMON_H

#include <bits/stdc++.h>

using namespace std;

#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QFile>
#include <QTimer>
#include <QPainter>


enum direction_type {
    d_right,
    d_left,
    d_front,
    d_back
};

enum road_type {
    ground_road,
    fly_road,
    stone_road
};

enum cell_type {
    remote_cell,
    stone_cell,
    close_cell,
    start_cell,
    end_cell
};

#endif // COMMON_H
