#include "02_head_Chapter11.h"

/*
 * 知识点总结：
 * - 运算符重载：通过重载运算符实现自定义类型的运算。
 * - 成员函数与友元函数：用于实现运算符重载。
 * - const成员函数：保证成员函数不会修改对象的状态。
 * - 友元函数：可以访问类的私有成员。

 * 注意点：
 * - 运算符重载时需注意操作数的类型及顺序。
 * - 保证重载运算符返回新对象，而不是修改原对象。
 * - 使用 const 成员函数保证函数不修改对象状态。
 */

/*
 * 主函数：演示 Time 类的运算符重载
 * - 创建 Time 对象
 * - 演示加法、减法、乘法运算
 */
int main(){
    Time coding(4, 35); // 初始化时间对象 coding
    Time fixing(2, 47); // 初始化时间对象 fixing
    Time total; // 用于存储总时间
    Time diff; // 用于存储时间差
    Time adjusted; // 用于存储调整后的时间

    cout << "coding time = ";
    coding.show(); // 显示 coding 时间

    cout << "fixing time = ";
    fixing.show(); // 显示 fixing 时间

    total = coding + fixing; // 重载+运算符
    cout << "total time = ";
    total.show(); // 显示 total 时间

    diff = coding - fixing; // 重载-运算符
    cout << "difference time = ";
    diff.show(); // 显示 diff 时间

    adjusted = coding * 1.5; // 重载*运算符
    cout << "adjusted time = ";
    adjusted.show(); // 显示 adjusted 时间

    adjusted = 1.5 * coding; // 重载友元函数*运算符
    cout << "adjusted time (friend function) = ";
    adjusted.show(); // 显示 adjusted 时间

    return 0;
}
