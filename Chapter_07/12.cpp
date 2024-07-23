#include "iostream"
#include "cmath"        // 数学库，用于sqrt和atan2函数
using namespace std;

/*
 * 知识点：
 * 1. 结构体：使用结构体存储极坐标和直角坐标数据。
 * 2. 数学运算：利用sqrt和atan2函数进行坐标转换。
 * 3. 函数：定义并调用函数实现坐标转换和显示。
 *
 * 注意点：
 * 1. 坐标转换：注意直角坐标到极坐标的转换公式。
 * 2. 输入输出：输入时要注意数据类型匹配，输出时注意格式。
 */

struct polar{
    double distance;    // 距离
    double angle;       // 角度
};

struct rect{
    double x;           // x 坐标
    double y;           // y 坐标
};

polar rect_to_polar(rect xypos);  // 直角坐标转换为极坐标的函数声明
void show_polar(polar dapos);     // 显示极坐标的函数声明

int main(){
    rect rplace{};        // 定义直角坐标结构体
    polar pplace{};       // 定义极坐标结构体
    cout << "Enter the x and y values: ";  // 输入x和y的值

    while (cin >> rplace.x >> rplace.y){   // 输入循环，按q退出
        pplace = rect_to_polar(rplace);    // 调用函数转换坐标
        show_polar(pplace);                // 显示转换后的极坐标
        cout << "Next two number (q to quit):"; // 提示输入下一组数
    }
    return 0;
}

polar rect_to_polar(rect xypos){ // 直角坐标转换为极坐标的函数定义
    polar answer{};
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);  // 计算距离
    answer.angle = atan2(xypos.y, xypos.x);  // 计算角度
    return answer;
}

void show_polar(polar dapos){ // 显示极坐标的函数定义
    const double Rad_to_deg = 57.29577951;  // 弧度转换为角度的常量
    cout << "Distance = " << dapos.distance << endl;  // 输出距离
    cout << "Angle = " << dapos.angle * Rad_to_deg << " degree" << endl;  // 输出角度并转换为度
}
