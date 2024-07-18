#include <iostream>
#include "01_head_Chapter09.h"

using namespace std;

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