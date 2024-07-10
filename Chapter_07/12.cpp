#include "iostream"
#include "cmath"        // 数学函数库
using namespace std;
// 构造体函数
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

int main(){
    rect rplace{};        // 创建直角坐标系对象
    polar pplace{};       // 创建极坐标系对象
    cout << "Enter the x and y values: ";

    while (cin >> rplace.x >> rplace.y){            // 输入直角系坐标x，y
        pplace = rect_to_polar(rplace);        // 直角坐标转换极坐标
        show_polar(pplace);
        cout << "Next two number (q to quit):";
    }
    return 0;
}
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