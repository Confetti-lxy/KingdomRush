#include "map.h"


void Map::load() {
    if (!StoneImg.load(":/image/stone_cell.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!CloseImg.load(":/image/close_cell.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!RemoteImg.load(":/image/remote_cell.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!StartImg.load(":/image/start.png")) {
        qDebug() << "picture load fail";
        return;
    }
    if (!EndImg.load(":/image/end.png")) {
        qDebug() << "picture load fail";
        return;
    }
}

void Map::updateParcels() {
    int x_loc = 0, y_loc = 0;
    for (int i = 0; i < allRoads.size(); i++) {
        for (int j = 0; j < allRoads[i].get_len(); j++) {
            x_loc = allRoads[i].get_loc(i, 0);
            y_loc = allRoads[i].get_loc(i, 1);
            if (allRoads[i].get_type() == stone_road) {
                grid[x_loc][y_loc] = stone_cell;
            } else {
                if (j == 0) {
                    grid[x_loc][y_loc] = start_cell;
                } else if (j == allRoads[i].get_len() - 1) {
                    grid[x_loc][y_loc] = end_cell;
                } else {
                    grid[x_loc][y_loc] = close_cell;
                }
            }
        }
    }
}


Map::Map(QString path) {
    // 图片加载
    load();
    // 文件读取
    QFile FILE(path);
    int count = 0, type, num = 0, road_count = 0;
    int x_loc = 0, y_loc = 0;
    if (!FILE.open(QIODevice::ReadOnly)) {
        qDebug() << FILE.errorString();
    }
    QString ifs = FILE.readLine();
    QTextStream read_01(&ifs);
    read_01 >> road_count;
    allRoads.resize(road_count);
    while (!FILE.atEnd()) {
        ifs = FILE.readLine();
        QVector <QVector<int>> route;
        QTextStream read_02(&ifs);
        read_02 >> type >> num;
        allRoads[count].set_type(road_type(type));
        ifs = FILE.readLine();
        QTextStream read_03(&ifs);
        while (!read_03.atEnd()) {
            read_03 >> x_loc >> y_loc;
            route.push_back({x_loc, y_loc});
        }
        route.pop_back();//去除尾部的"/0"
        allRoads[count].set_location(route);
        allRoads[count].set_map(this);
        count++;
    }
    // 地块更新
    updateParcels();
}


void Map::update(QWidget *page) {
    for (int i = 0; i < m_len / width - 2; i++) {
        for (int j = 0; j < m_height / width; j++) {
            QLabel *label = new QLabel;
            if (grid[i][j] == stone_cell) {
                label->setPixmap(StoneImg);
            } else if (grid[i][j] == close_cell) {
                label->setPixmap(CloseImg);
            } else if (grid[i][j] == remote_cell) {
                build *new_remote = new build(page);
                new_remote->move(i * width, j * width);
                new_remote->setParent(page);
                allRemotes.push_back(new_remote);
            } else if (grid[i][j] == start_cell) {
                label->setPixmap(StartImg);
            } else {
                label->setPixmap(EndImg);
            }
            label->setStyleSheet("QPushButton{border:Opx;}");
            label->setFixedSize(width, width);
            label->setParent(page);
            label->move(i * width, j * width);
            label->show();
        }
    }
}

int Map::get_height() const {
    return m_height;
}

int Map::get_width() const {
    return width;
}

int Map::get_len() const {
    return m_len;
}


cell_type Map::get_grid(int x, int y) const {
    return grid[x][y];
}

int Map::get_road() const {
    return allRoads.size();
}

int Map::get_remote() const {
    return allRemotes.size();
}






















