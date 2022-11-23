#ifndef MAP_H
#define MAP_H

#include "./Common/Button/build.h"
#include "../Map/road.h"

class road;

class Map {

private:
    int m_len = 1050, m_height = 630, width = 70;// 地图长宽和每个格子的边长，必要时可以修改
    QVector <QVector<cell_type>> grid = QVector < QVector < cell_type >> (13, QVector<cell_type>(9));//地块类型的数组
    QPixmap StoneImg, RemoteImg, CloseImg, StartImg, EndImg; // 图片加载

    bool load();// 图片素材的加载

    void updateParcels();// 地块更新函数

public:

    QVector <road> allRoads;// 所有的路线数组
    QVector<build *> allRemotes;// 远程塔的部署单位数组

    Map();// 基础构造函数

    Map(QString path);// 构造函数，根据地图文件参数来构造

    void update(QWidget *page);// 根据grid数组来生成地图的图片素材












    // 一系列的get和set函数
    int get_len() const { return m_len; }

    int get_width() const { return width; }

    int get_height() const { return m_height; }

    cell_type get_grid(int x, int y) const { return grid[x][y]; }

    int get_road() { return allRoads.size(); }

    int get_remote() { return allRemotes.size(); }


};

#endif // MAP_H
