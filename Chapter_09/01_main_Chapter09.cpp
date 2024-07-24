#include <iostream>
#include "01_head_Chapter09.h"

using namespace std;

/*
知识点：
1. 结构体：使用结构体 `rect` 和 `polar` 存储矩形坐标和极坐标。
2. 函数：定义了 `rect_to_polar` 和 `show_polar` 函数进行坐标转换和显示。
3. 头文件：通过头文件分离声明和定义，增强代码的可读性和模块化。
4. 数学计算：使用数学函数 `sqrt` 和 `atan2` 进行坐标转换。

注意点：
1. 输入检查：需要确保输入的 x 和 y 是有效数字。
2. 极角度转换：注意角度转换过程中使用正确的弧度到角度的转换系数。
3. 内存管理：确保没有内存泄漏，尽管在此代码中没有动态内存分配。
*/

int main(){
    rect rplace{};  // 定义矩形坐标结构体
    polar pplace{}; // 定义极坐标结构体
    cout << "Enter the x and y values: ";

    while (cin >> rplace.x >> rplace.y){            // 输入 x 和 y 坐标
        pplace = rect_to_polar(rplace);             // 将矩形坐标转换为极坐标
        show_polar(pplace);                         // 显示极坐标
        cout << "Next two number (q to quit):";
    }
    return 0;
}
