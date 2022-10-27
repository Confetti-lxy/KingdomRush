#ifndef ROAD_H
#define ROAD_H

#include "../Common/common.h"

#include "../Map/map.h"


class Map;

class road {

private:
    QVector <QVector<int>> location = QVector < QVector < int >> (200, QVector<int>(2, 0));
    road_type type = ground_road;
    Map *my_map;

public:

    road() {};

    void set_type(road_type type);

    void set_location(QVector <QVector<int>> loc);

    void set_map(Map *my_map);

    road_type get_type() const;

    int get_len() const;

    int get_loc(int x, int y) const;

    direction_type direction(int loc) const;

    int transToLoc(int step, int &x, int &y) const;
};

#endif // ROAD_H
