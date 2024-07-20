#include "test06_head_Chapter10.h"

/*
 * 知识点总结：
 * - 构造函数初始化：使用构造函数初始化对象的成员变量。
 * - 成员函数：定义类的成员函数以操作对象的数据。
 * - this指针：用于指向调用成员函数的对象。
 * - 对象作为参数：在成员函数中接收对象并进行操作。
 * - 默认参数：为成员函数提供默认参数值。

 * 注意点：
 * - 成员变量的初始化：确保成员变量在构造函数中正确初始化。
 * - 对象操作：在add函数中使用this指针访问调用对象的成员变量。
 * - 输入检查：在读取用户输入时要进行必要的检查和处理。
 */

/*
 * 主函数：演示 Move 类的使用
 * - 包括对象的初始化、成员函数调用和对象操作
 */
int main(){
    double x, y; // 用户输入的新的 x 和 y 值
    Move m1(11.1, 22.2); // 创建 Move 对象 m1
    Move m2(10.0, 20.0); // 创建 Move 对象 m2
    Move m3; // 创建默认构造的 Move 对象 m3
    m1.showmove(); // 显示 m1 的 x 和 y
    m2.showmove(); // 显示 m2 的 x 和 y

    cout << "Enter new x and y: "; // 提示用户输入新的 x 和 y
    cin >> x >> y; // 读取用户输入
    cout << "Reset m1: " << endl; // 提示用户重置 m1
    m1.reset(x, y); // 重置 m1 的 x 和 y
    m1.showmove(); // 显示重置后的 m1 的 x 和 y

    m3 = m1.add(m2); // 将 m1 和 m2 相加，结果赋值给 m3
    cout << "Show m3: " << endl; // 提示用户显示 m3
    m3.showmove(); // 显示 m3 的 x 和 y

    return 0;
}
