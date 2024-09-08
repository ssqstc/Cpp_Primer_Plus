/*
知识点：
1. **std::function**：可以存储可调用对象（如函数、Lambda 表达式、仿函数等），统一不同类型的函数接口。
2. **函数指针**：通过 `std::function` 封装普通函数指针，便于统一管理。
3. **Lambda 表达式与仿函数**：`std::function` 同时兼容 Lambda 表达式与重载 `operator()` 的仿函数对象。

注意点：
1. `std::function` 是一个泛型函数包装器，适合需要将多种可调用对象传递给同一函数模板的场景。
2. 使用 `std::function` 封装时，务必确保传递的函数签名匹配模板定义的参数类型。

*/

#include "05_head_Chapter18.h"
#include <functional>  // 引入 std::function 头文件

// 简单的函数，将输入参数乘以2
double dub(double x) { return 2.0 * x; }

// 计算输入参数的平方
double square(double x) { return x * x; }

int main() {
    double y = 1.21;  // 定义一个双精度变量

    // 使用 std::function 封装不同类型的可调用对象
    function<double(double)> ef1 = dub;     // 封装普通函数 dub
    function<double(double)> ef2 = square;  // 封装普通函数 square
    function<double(double)> ef3 = Fp(10);  // 封装仿函数 Fp
    function<double(double)> ef4 = Fq(10);  // 封装仿函数 Fq
    function<double(double)> ef5 = [](double u){ return u * u; };       // 封装 Lambda 表达式（平方）
    function<double(double)> ef6 = [](double u){ return u + u / 2.0; }; // 封装 Lambda 表达式（加上自身的一半）

    // 调用模板函数 use_f，并通过 std::function 传递函数对象
    cout << use_f(y, ef1) << endl;  // 调用封装的 dub 函数
    cout << use_f(y, ef2) << endl;  // 调用封装的 square 函数
    cout << use_f(y, ef3) << endl;  // 调用封装的 Fp 仿函数
    cout << use_f(y, ef4) << endl;  // 调用封装的 Fq 仿函数
    cout << use_f(y, ef5) << endl;  // 调用封装的 Lambda 表达式（平方）
    cout << use_f(y, ef6) << endl;  // 调用封装的 Lambda 表达式（加上自身的一半）

    return 0;
}