#include "test07_head_Chapter11.h"

/**
 * 知识点总结:
 * 1. 类构造函数: `complex` 类提供了默认构造函数和参数构造函数。
 * 2. 运算符重载: 重载了 `+`, `-`, `*`, `~`, `>>`, `<<` 运算符，支持复数的基本运算和输入输出。
 * 3. 友元函数: 重载的 `>>` 和 `<<` 运算符作为友元函数，以便访问类的私有成员。
 *
 * 注意点:
 * 1. 运算符重载返回类型: 复数运算符重载应返回新的 `complex` 对象。
 * 2. 复数共轭: `~` 运算符用于计算复数的共轭，改变虚部的符号。
 * 3. 输入输出格式: `>>` 和 `<<` 运算符的重载应符合复数的表示习惯，输出格式为 `(real,imaginary i)`。
 */

int main() {
    complex a(3.0, 4.0);  // 使用参数构造函数初始化复数
    complex c;  // 默认构造函数初始化复数

    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c) {  // 从标准输入流中读取复数
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';  // 输出复数的共轭
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';  // 输出复数加法结果
        cout << "a - c is " << a - c << '\n';  // 输出复数减法结果
        cout << "a * c is " << a * c << '\n';  // 输出复数乘法结果
        cout << "2 * c is " << 2 * c << '\n';  // 输出复数与实数乘法结果
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";

    return 0;
}
