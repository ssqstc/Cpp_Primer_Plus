#include "iostream"
#include "cmath"        // 数学函数库
using namespace std;
// 构造体函数->引用
struct polar{           // 极坐标
    double distance;    // 距离
    double angle;   // 角度
};
struct rect{        // 直角
    double x;
    double y;
};
void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar *pda);

int main(){
    rect rplace{};        // 创建直角坐标系对象
    polar pplace{};       // 创建极坐标系对象
    cout << "Enter the x and y values: ";

    while (cin >> rplace.x >> rplace.y){            // 输入直角系坐标x，y
        rect_to_polar(&rplace, &pplace);        // 直角坐标转换极坐标
        show_polar(&pplace);
        cout << "Next two number (q to quit):";
    }
    return 0;
}
void rect_to_polar(const rect *pxy, polar *pda){
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy-> y);      // sqrt()平方根函数
    pda->angle = atan2(pxy->y, pxy->x);        // atan2()反正切函数  返回值是弧度
}
void show_polar(const polar *pda){
    const double Rad_to_deg = 57.29577951;       // 弧度转角度的常量值
    cout << "Distance = " << pda->distance << endl;        // 输出距离
    cout << "Angle = " << pda->angle * Rad_to_deg << "degree" << endl;         // 输出角度
}