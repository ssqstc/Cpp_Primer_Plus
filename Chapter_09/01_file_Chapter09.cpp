#include <iostream>     // 尖括号 系统目录寻找头文件
#include <cmath>
#include "01_head_Chapter09.h"      // 引号 当前工程目录寻找头文件

using namespace std;

polar rect_to_polar(rect xypos){
    polar answer{};
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);      // sqrt()平方根函数
    answer.angle = atan2(xypos.y, xypos.x);        // atan2()反正切函数  返回值是弧度
    return answer;
}
void show_polar(polar dapos){
    const double Rad_to_deg = 57.29577951;       // 弧度转角度的常量值
    cout << "Distance = " << dapos.distance << endl;        // 输出距离
    cout << "Angle = " << dapos.angle * Rad_to_deg << "degree" << endl;         // 输出角度
}