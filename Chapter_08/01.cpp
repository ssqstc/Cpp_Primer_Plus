#include "iostream"
using namespace std;

// 内联函数: 省略函数原型，将整个定义(即函数头和所有函数代码)放在本应提供原型的地方。
// 内联函数是值传递 C语言宏是文本替换
inline double square(double x) { return x * x; } // 整个函数定义充当了函数原型，内联函数的定义

int main() {
    double a, b;
    double c = 13.0;

    // 调用内联函数
    a = square(5.0);             // 传递5.0，结果为5.0*5.0 = 25.0
    b = square(4.5 + 7.5);       // 传递12.0，结果为12.0*12.0 = 144.0

    cout << "a = " << a << ", b = " << b << endl; // 输出 a = 25, b = 144
    cout << "c = " << c << endl;                 // 输出 c = 13

    // 调用内联函数，同时后置递增运算符会先计算 square(c++)，然后 c 增加 1
    cout << "c square = " << square(c++) << endl; // 输出 c square = 169 (13*13)
    cout << "Now c = " << c << endl;              // 输出 Now c = 14

    return 0;
}
