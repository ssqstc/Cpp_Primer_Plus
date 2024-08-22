// 知识点总结:
// 1. 该代码通过自定义异常类 `bad_hmean` 和 `bad_gmean` 来处理特定的数学错误。
// 2. `hmean` 函数和 `gmean` 函数分别计算两个数的调和平均数和几何平均数，并在输入无效时抛出对应的异常。
// 3. 使用异常类的 `mesg()` 方法输出错误信息，增强了程序的可读性和错误处理的灵活性。

// 注意点:
// 1. 自定义异常类时，要确保异常类能够清晰传达错误信息，并且异常类中的数据成员应合理定义。
// 2. 在异常处理时，应根据不同错误类型使用相应的 `catch` 块，并提供必要的错误处理逻辑。
// 3. 异常处理虽然能提高程序的健壮性，但应谨慎使用，避免过度依赖异常处理。

#include <cmath> // 包含数学函数库，例如 sqrt()
#include <iostream> // 包含输入输出流库
#include "07_head_Chapter15.h" // 包含自定义的头文件

// 函数声明：计算两个数的调和平均数
double hmean(double a, double b);

// 函数声明：计算两个数的几何平均数
double gmean(double a, double b);

int main() {
    double x, y, z;
    cout << "Enter two numbers: "; // 提示用户输入两个数字
    while (cin >> x >> y) { // 读取用户输入的两个数字
        try {
            z = hmean(x, y); // 调用 hmean 函数计算调和平均数
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x, y); // 调用 gmean 函数计算几何平均数
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
        }
        catch(bad_hmean& bh) { // 捕获 hmean 函数抛出的异常
            bh.mesg(); // 输出异常信息
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