#include <iostream>
#include <initializer_list>
using namespace std;

/*
 * 知识点总结：
 * 1. `initializer_list`：一个类模板，用于支持以列表形式初始化容器或传递参数。允许将一组值作为初始化参数传递给函数。
 * 2. 范围for循环：用于遍历容器（如`initializer_list`）中的每一个元素，简化代码，提高可读性。
 * 3. 自动类型推导：`auto` 关键字使编译器自动推导变量类型，减少代码中类型声明的复杂性。
 *
 * 注意点：
 * 1. `initializer_list` 初始化：使用花括号 `{}` 初始化 `initializer_list` 对象时，可以在函数中直接传递给接受`initializer_list`的函数。
 * 2. 参数传递：`initializer_list` 通常是按值传递，即复制原始数据。对传递的 `initializer_list` 进行修改不会影响原始数据。
 * 3. 累加器初始值：计算总和时，务必初始化累加器（`total`），避免未定义行为。
 */

double sum(initializer_list<double> il); // 函数声明，计算 initializer_list<double> 的总和

int main() {
    // 创建 initializer_list<double> a 并初始化
    initializer_list<double> a({ 2.2, 3.3, 4.4, 5.5 });
    cout << "sum = " << sum(a); // 输出 a 的总和
    cout << endl;

    // 创建 initializer_list<double> b 并初始化
    initializer_list<double> b{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    cout << "sum = " << sum(b); // 输出 b 的总和
    cout << endl;

    return 0;
}

// 实现 sum 函数，计算 initializer_list<double> 中所有元素的总和
double sum(initializer_list<double> il) {
    double total = 0.0;
    for (auto p : il) { // 使用范围for循环遍历 initializer_list 中的每一个元素
        total += p; // 累加每个元素的值到 total 中
    }
    return total; // 返回总和
}