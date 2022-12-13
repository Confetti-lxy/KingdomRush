#include "map.h"


bool Map::load() {
    if (!StoneImg.load(":/image/stone_cell.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!CloseImg.load(":/image/close_cell.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!RemoteImg.load(":/image/remote_cell.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!StartImg.load(":/image/start.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    if (!EndImg.load(":/image/end.png")) {
        qDebug() << "picture load fail";
        return false;
    }
    return true;
}

void Map::updateParcels() {
    int x_loc = 0, y_loc = 0;// 每个格子的横纵坐标
    for (int i = 0; i < allRoads.size(); i++) {
        for (int j = 0; j < allRoads[i].get_len(); j++) {
            x_loc = allRoads[i].get_loc(j, 0);
            y_loc = allRoads[i].get_loc(j, 1);
            if (allRoads[i].get_type() == stone_road) {
                grid[x_loc][y_loc] = stone_cell;// 石头地块
            } else {
                if (j == 0) {
                    grid[x_loc][y_loc] = start_cell;// 起点地块
                } else if (j == allRoads[i].get_len() - 1) {
                    grid[x_loc][y_loc] = end_cell;// 终点地块
                } else {
                    grid[x_loc][y_loc] = close_cell;// 一般的路径地块
                }
            }
        }
    }
}


Map::Map(QString path) {
    // 图片加载
    if (!load()) {
        return;
    }
    // 文件读取,并根据读取的文件参数来构造地图结构，后续创建新地图时只需要填写相关的地图参数即可
    QFile FILE(path);
    // count为现在读到第count条路径
    int count = 0, type, num = 0, road_count = 0;
    int x_loc = 0, y_loc = 0;
    // 若地图构造失败，则自动退出
    if (!FILE.open(QIODevice::ReadOnly)) {
        qDebug() << FILE.errorString();
        exit(-1);
    }
    QString ifs = FILE.readLine();
    QTextStream read_01(&ifs);// 对路线数量的读取
    read_01 >> road_count;
    allRoads.resize(road_count);
    // 对路径的具体路线进行读取
    while (!FILE.atEnd()) {
        ifs = FILE.readLine();
        QVector <QVector<int>> route;// 路径坐标
        QTextStream read_02(&ifs);// 对路径的长度和种类的读取
        read_02 >> type >> num;
        allRoads[count].set_type(road_type(type));
        ifs = FILE.readLine();
        QTextStream read_03(&ifs);// 对一条路径每个坐标的读取
        while (!read_03.atEnd()) {
            read_03 >> x_loc >> y_loc;
            route.push_back({x_loc, y_loc});
        }
        route.pop_back();//去除尾部的"/0"
        allRoads[count].set_location(route);
        allRoads[count].set_map(this);
        count++;
    }
    // 根据路径坐标对地块进行更新
    updateParcels();
}


void Map::update(QWidget *page) {
    int num = 0;
    // -2是因为最右的2个竖排为界面显示栏，不属于地图区域
    for (int i = 0; i < m_len / width - 2; i++) {
        for (int j = 0; j < m_height / width; j++) {
            QLabel *label = new QLabel;
            if (grid[i][j] == stone_cell) {
                label->setPixmap(StoneImg);
            } else if (grid[i][j] == close_cell) {
                label->setPixmap(CloseImg);
            } else if (grid[i][j] == remote_cell) {
                num++;
            } else if (grid[i][j] == start_cell) {
                label->setPixmap(StartImg);
            } else {
                label->setPixmap(EndImg);
            }
            label->setStyleSheet("QPushButton{border:Opx;}");
            label->setFixedSize(width, width);
            label->setParent(page), label->move(i * width, j * width);
            label->show();
        }
    }
    allRemotes.resize(num);
    num = 0;
    for (int i = 0; i < m_len / width - 2; i++) {
        for (int j = 0; j < m_height / width; j++) {
            if (grid[i][j] == remote_cell) {
                // 远程部署单位的地块设置
                allRemotes[num] = new build(page);
                allRemotes[num]->move(i * width, j * width - 30);
                allRemotes[num]->setParent(page);
                num++;
            }
        }
    }
}
