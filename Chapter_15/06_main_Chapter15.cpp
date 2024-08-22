// 知识点总结:
// 1. 该代码通过 C++ 的异常处理机制来管理错误，使用 `try-catch` 结构捕获并处理异常。
// 2. 当函数 `hmean` 遇到非法参数时，会抛出一个异常，调用者可以捕获并处理这个异常，从而避免程序崩溃。
// 3. 异常处理提高了程序的健壮性和安全性，特别适用于需要处理复杂错误情形的场合。

// 注意点:
// 1. 在编写抛出异常的代码时，需要确保抛出的异常类型和捕获的异常类型相匹配。
// 2. 异常处理应适度使用，避免过度使用导致程序性能下降或逻辑复杂化。
// 3. 在实际项目中，应考虑使用更详细的异常类型（如 `std::runtime_error`），而非简单的字符串类型。

#include <iostream>
#include <cstdlib> // 包含标准库函数的头文件

using namespace std;

// 函数声明：计算两个数的调和平均数
// 如果 a 和 b 互为相反数，函数会抛出一个异常
double hmean(double a, double b);

int main() {
    double x, y, z;
    cout << "Enter two numbers: "; // 提示用户输入两个数字
    while (cin >> x >> y) { // 读取用户输入的两个数字
        try {
            z = hmean(x, y); // 调用 hmean 函数计算调和平均数
        }
        catch(const char* s) { // 捕获 hmean 函数抛出的异常
            cout << s << endl; // 输出异常信息
            cout << "Enter a new pair of arguments:"; // 提示用户输入一组新的数字
            continue; // 继续下一个循环，重新读取输入
        }
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl; // 输出计算结果
        cout << "Enter next set of number: "; // 提示用户输入下一组数字
    }
    return 0; // 返回0，表示程序正常结束
}

// 函数定义：计算两个数的调和平均数
// 如果 a 和 b 互为相反数，抛出一个异常
double hmean(double a, double b) {
    if (a == -b) { // 检查参数是否合法，如果两个数互为相反数
        throw "bad hmean() arguments, a = -b not allowed"; // 抛出异常，返回错误信息
    }
    return 2.0 * a * b / (a + b); // 返回计算结果
}