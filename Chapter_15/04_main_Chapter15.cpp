// 知识点总结:
// 1. 该代码实现了一个计算两个数的调和平均数（Harmonic Mean）的函数 `hmean`。
// 2. 调和平均数是一种平均数，适用于处理两个数的倒数和，其公式为 `H = 2ab / (a + b)`。
// 3. 在计算调和平均数时，当两个数互为相反数时，会导致分母为零的情况，这种情况下程序通过 `abort()` 函数终止执行。
// 4. 代码中使用了 `abort()` 函数来处理非法参数，这会立即终止程序运行，并返回一个非零状态给操作系统。

// 注意点:
// 1. `hmean` 函数中的参数检查：当参数 `a` 和 `b` 互为相反数时，计算将导致除以零，这是非法操作，因此函数直接终止程序运行。
// 2. `abort()` 函数是一个非正常退出程序的方法，实际开发中通常不建议直接使用，应该考虑用异常处理或其他机制来处理错误。

#include <iostream>
#include <cstdlib> // 包含 `abort()` 函数的头文件

using namespace std;

// 函数声明：计算两个数的调和平均数
double hmean(double a, double b);

int main() {
    double x, y, z;
    cout << "Enter two numbers: "; // 提示用户输入两个数字
    while (cin >> x >> y) { // 读取用户输入的两个数字
        z = hmean(x, y); // 调用 hmean 函数计算调和平均数
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of number: "; // 提示用户输入下一组数字
    }
    return 0; // 返回0，表示程序正常结束
}

// 函数定义：计算两个数的调和平均数
double hmean(double a, double b) {
    if (a == -b) { // 检查参数是否合法，如果两个数互为相反数
        cout << "invalid arguments to hmean()" << endl; // 输出错误信息
        abort(); // 终止程序运行
    }
    // 调和平均数计算公式：H = 2ab / (a + b)
    return 2.0 * a * b / (a + b);
}