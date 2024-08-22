// 知识点总结:
// 1. 该代码通过函数 `mean` 计算两个数的算术平均数、调和平均数和几何平均数，并返回这些平均数的总体平均值。
// 2. 使用了自定义异常类 `bad_hmean` 和 `bad_gmean`，并在 `mean` 函数中处理这些异常。
// 3. 异常处理机制用于捕捉在计算调和平均数和几何平均数时可能发生的错误，从而避免程序崩溃。

// 注意点:
// 1. 当 `mean` 函数捕获异常时，它只输出错误信息，并继续计算其他部分。需要注意的是，如果 `hmean` 或 `gmean` 失败，返回值可能不准确。
// 2. 如果 `hmean` 或 `gmean` 出现异常，计算流程仍将继续，因此 `mean` 的返回值可能不是预期的结果，这可能需要重新设计错误处理逻辑。
// 3. 在异常处理中应避免重复的错误信息提示，并确保所有可能的异常情况都被妥善处理。

#include <cmath> // 包含数学函数库，例如 sqrt()
#include <iostream> // 包含输入输出流库
#include "08_head_Chapter15.h" // 包含自定义的头文件

// 函数声明：计算两个数的调和平均数
double hmean(double a, double b);

// 函数声明：计算两个数的几何平均数
double gmean(double a, double b);

// 函数声明：计算两个数的平均值，包括算术、调和和几何平均数
double mean(double a, double b);

int main() {
    double x, y, z;
    cout << "Enter two numbers: "; // 提示用户输入两个数字
    while (cin >> x >> y) { // 读取用户输入的两个数字
        try {
            z = mean(x, y); // 调用 mean 函数计算平均值
            cout << "The mean of " << x << " and " << y << " is " << z << endl;
        }
        catch(bad_hmean& bh) { // 捕获 hmean 函数抛出的异常
            bh.mesg(); // 输出异常信息
            cout << "2) exception" << endl;
            cout << "Enter a new pair of arguments:"; // 提示用户输入一组新的数字
            continue; // 继续下一个循环，重新读取输入
        }
        catch(bad_gmean& gh) { // 捕获 gmean 函数抛出的异常
            cout << gh.mesg() << endl; // 输出异常信息
            cout << "Value used: " << gh.v1 << ", " << gh.v2 << endl; // 输出出错时的具体值
            cout << "Sorry, quit now" << endl; // 终止程序
            break; // 跳出循环
        }

        cout << "Enter next set of number: "; // 提示用户输入下一组数字
    }
    return 0; // 返回0，表示程序正常结束
}

// 函数定义：计算两个数的调和平均数
// 如果 a 和 b 互为相反数，抛出 bad_hmean 异常
double hmean(double a, double b) {
    if (a == -b) { // 检查参数是否合法
        throw bad_hmean(a, b); // 抛出异常
    }
    return 2.0 * a * b / (a + b); // 返回计算结果
}

// 函数定义：计算两个数的几何平均数
// 如果 a 或 b 为负数，抛出 bad_gmean 异常
double gmean(double a, double b) {
    if (a < 0 || b < 0) { // 检查参数是否合法
        throw bad_gmean(a, b); // 抛出异常
    }
    return sqrt(a * b); // 返回计算结果
}

// 函数定义：计算两个数的平均值
// 平均值包括算术平均数、调和平均数和几何平均数
// 返回这三者的总体平均值
double mean(double a, double b) {
    double am, hm, gm;
    am = (a + b) / 2.0; // 计算算术平均数
    try {
        hm = hmean(a, b); // 计算调和平均数
        gm = gmean(a, b); // 计算几何平均数
    }
    catch(bad_hmean& bh) { // 捕获 hmean 函数抛出的异常
        bh.mesg(); // 输出异常信息
        cout << "1) exception" << endl;
    }
    cout << "Hello world\n"; // 调试信息输出
    return (am + hm + gm) / 3.0; // 返回三者平均值
}