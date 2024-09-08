/*
知识点：
1. **模板函数**：`use_f` 是一个模板函数，可以接受不同类型的参数和函数对象。
2. **函数指针**：通过传递普通函数（如 `dub` 和 `square`）的指针来调用模板函数。
3. **仿函数**：`Fp` 和 `Fq` 类重载了 `operator()`，成为仿函数对象。
4. **Lambda表达式**：使用匿名函数通过 Lambda 表达式进行操作，直接在调用时定义函数逻辑。

注意点：
1. 模板函数中的 `static` 局部变量在多次调用中会保持其值，不会被重新初始化。
2. Lambda 表达式是 `C++11` 引入的特性，使用 `[]` 捕获外部变量，`()` 内为参数列表，`{}` 内为函数体。

*/

#include "05_head_Chapter18.h"

// 简单的函数，将输入参数乘以2
double dub(double x) { return 2.0 * x; }

// 计算输入参数的平方
double square(double x) { return x * x; }

int main() {
    double y = 1.21;  // 定义一个双精度变量

    // 使用函数指针传递给模板函数
    cout << use_f(y, dub) << endl;      // 传递函数 dub 的指针
    cout << use_f(y, square) << endl;   // 传递函数 square 的指针

    // 使用仿函数对象传递给模板函数
    cout << use_f(y, Fp(5.0)) << endl;  // 传递 Fp 类的对象
    cout << use_f(y, Fq(5.0)) << endl;  // 传递 Fq 类的对象

    // 使用 Lambda 表达式传递给模板函数
    cout << use_f(y, [](double u){ return u * u; }) << endl;       // Lambda 表达式计算平方
    cout << use_f(y, [](double u){ return u + u / 2.0; }) << endl; // Lambda 表达式计算 u + u / 2

    return 0;
}