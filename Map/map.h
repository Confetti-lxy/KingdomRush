#ifndef MAP_H
#define MAP_H

#include "./Common/Button/build.h"
#include "../Map/road.h"

class road;

class Map {

private:
    int m_len = 1050, m_height = 630, width = 70;
    QVector <QVector<cell_type>> grid = QVector < QVector < cell_type >> (13, QVector<cell_type>(9));
    QPixmap StoneImg, RemoteImg, CloseImg, StartImg, EndImg;
    int road_count;
    QVector<build *> allRemotes;
    QVector <road> allRoads;

public:

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
