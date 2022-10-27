#ifndef MAP_H
#define MAP_H

#include "./Common/Button/build.h"
#include "../Map/road.h"

class road;

class Map {

private:
    int m_len = 1050, m_height = 630, width = 70;//地图长度，必要时可以修改
    QVector <QVector<cell_type>> grid = QVector < QVector < cell_type >> (13, QVector<cell_type>(9));//地块类型的数组
    QPixmap StoneImg, RemoteImg, CloseImg, StartImg, EndImg; // 图片加载
    QVector<build *> allRemotes;


    void load();

    void updateParcels();

public:

    QVector <road> allRoads;

    Map();

    Map(QString path);

    int get_len() const;

    int get_width() const;

    int get_height() const;

    cell_type get_grid(int x, int y) const;

    int get_road() const;

    int get_remote() const;

    void update(QWidget *page);

};

#endif // MAP_H
