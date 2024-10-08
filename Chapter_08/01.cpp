#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 内联函数：定义和使用内联函数提高性能。
 * 2. 表达式求值：了解函数参数的求值顺序。
 * 3. 自增运算符：理解自增运算符在表达式中的使用及其副作用。
 * 4. 内联函数: 省略函数原型，将整个定义(即函数头和所有函数代码)放在本应提供原型的地方。
 * 5. 内联函数是值传递 C语言宏是文本替换
 *
 * 注意点：
 * 1. 内联函数：内联函数适合用于短小、频繁调用的函数，以减少函数调用开销。
 * 2. 表达式求值：复杂表达式在传递给函数时，需注意运算顺序，避免副作用。
 * 3. 自增运算符：后置自增运算符 `c++` 会先使用 `c` 的值，再进行自增，可能导致结果与预期不符。
 */

// 内联函数定义，计算平方
inline double square(double x) { return x * x; } // 整个函数定义充当了函数原型，内联函数的定义

int main() {
    double a, b;
    double c = 13.0;

    a = square(5.0);        // 调用内联函数，计算5.0的平方
    b = square(4.5 + 7.5);  // 调用内联函数，计算(4.5 + 7.5)的平方

    cout << "a = " << a << ", b = " << b << endl; // 输出 a 和 b 的值
    cout << "c = " << c << endl;                 // 输出 c 的初始值
    cout << "c square = " << square(c++) << endl; // 调用内联函数计算 c 的平方，后置自增
    cout << "Now c = " << c << endl;              // 输出自增后的 c 的值

    return 0;
}
