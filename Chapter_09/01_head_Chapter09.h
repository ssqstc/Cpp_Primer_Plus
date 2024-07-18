#ifndef __01_HEAD_CHAPTER09_H__
#define __01_HEAD_CHAPTER09_H__

struct polar{           // 极坐标
    double distance;    // 距离
    double angle;   // 角度
};
struct rect{        // 直角
    double x;
    double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif //__01_HEAD_CHAPTER09_H__
