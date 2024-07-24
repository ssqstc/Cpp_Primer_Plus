#include <iostream>
#include <cmath>
#include "01_head_Chapter09.h"

using namespace std;

polar rect_to_polar(rect xypos){
    polar answer{};
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);      // 计算距离
    answer.angle = atan2(xypos.y, xypos.x);        // 计算角度
    return answer;
}

void show_polar(polar dapos){
    const double Rad_to_deg = 57.29577951;       // 定义弧度到角度的转换系数
    cout << "Distance = " << dapos.distance << endl;        // 显示距离
    cout << "Angle = " << dapos.angle * Rad_to_deg << " degree" << endl;         // 显示角度
}