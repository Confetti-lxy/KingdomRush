#include "road.h"


direction_type road::direction(int loc) const {
    if (location[loc + 1][0] == location[loc][1] + 1) {
        return d_right;
    } else if (location[loc + 1][0] == location[loc][1] - 1) {
        return d_left;
    } else if (location[loc + 1][1] == location[loc][1] + 1) {
        return d_back;
    } else {
        return d_front;
    }
}

int road::transToLoc(int step, int &x, int &y) const {
    int width = my_map->get_width();
    int x_loc = location[0][0] * width, y_loc = location[0][1] * width;
    direction_type ans = d_left;
    int temp = 0;
    for (int i = 0; i < location.size(); i++) {
        ans = direction(i);
        if (step > width) {
            temp = width;
            step -= width;
        } else {
            temp = step;
            step = 0;
        }
        if (ans == d_right) {
            x_loc += temp;
        } else if (ans == d_left) {
            x_loc -= temp;
        } else if (ans == d_back) {
            y_loc += temp;
        } else {
            y_loc -= temp;
        }
    }
    x = x_loc;
    y = y_loc;
    return ans;
}

void road::set_type(road_type type) {
    this->type = type;
}

void road::set_location(QVector <QVector<int>> loc) {
    this->location = loc;
}


road_type road::get_type() const {
    return this->type;
}

int road::get_len() const {
    return location.size();
}

int road::get_loc(int x, int y) const {
    return location[x][y];
}

