#ifndef ROAD_H
#define ROAD_H

#include "../Common/common.h"
#include "../Map/map.h"


class Map;

class road {

private:
    QVector <QVector<int>> location = QVector < QVector < int >> (200, QVector<int>(2, 0));// 这条路径所进过的路径坐标
    road_type type = ground_road;// 该条路径的类型
    Map *my_map;// 所依赖的上层地图

public:

    road() {};// 构造函数

    direction_type direction(int loc) const;// 获取第loc个坐标点的下一个点相对于该点的方向

    int transToLoc(int step, int &x, int &y) const;// 在这条路径上面移动step距离后所停留的位置，并将坐标保存到(x,y)里面去








    // 一系列的get和set函数
    void set_type(road_type type) { this->type = type; }

    void set_location(QVector <QVector<int>> loc) { this->location = loc; }

    void set_map(Map *my_map) { this->my_map = my_map; }

    road_type get_type() { return this->type; }

    int get_len() { return location.size(); }

    int get_loc(int x, int y) { return location[x][y]; }
};

#endif // ROAD_H
