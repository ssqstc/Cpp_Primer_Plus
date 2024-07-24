#ifndef __01_HEAD_CHAPTER09_H__
#define __01_HEAD_CHAPTER09_H__

struct polar{           // 定义极坐标结构体
    double distance;    // 距离
    double angle;       // 角度
};

struct rect{        // 定义矩形坐标结构体
    double x;
    double y;
};

polar rect_to_polar(rect xypos); // 矩形坐标转换为极坐标
void show_polar(polar dapos); // 显示极坐标

#endif //__01_HEAD_CHAPTER09_H__