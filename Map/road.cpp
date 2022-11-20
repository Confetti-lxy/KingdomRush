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
    // width为格子的边长，temp为中间操作量
    int width = my_map->get_width(), temp = 0;
    int x_loc = location[0][0] * width, y_loc = location[0][1] * width;
    direction_type ans = d_left;
    for (int i = 0; i < location.size() && step != 0; i++) {
        ans = direction(i);
        if (step > width) {
            // 若剩余的step大于width,则会走过这一格
            temp = width;
            step -= width;
        } else {
            // 反之则会停留在这一格
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





