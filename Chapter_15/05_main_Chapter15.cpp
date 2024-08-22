// 知识点总结:
// 1. 此代码通过修改后的 `hmean` 函数实现了调和平均数的计算，并使用了指针参数来返回结果。
// 2. 使用布尔类型返回值来指示计算是否成功，这种设计增加了函数的灵活性和安全性。
// 3. 使用了指针来传递结果值，从而避免了直接返回计算结果带来的额外开销。

// 注意点:
// 1. 在使用指针传递结果时，确保指针已经被正确初始化，并且指向有效的内存地址。
// 2. 通过返回布尔值，程序可以有效地处理计算失败的情况，避免不必要的程序中断。

#include <iostream>
#include <cstdlib> // 包含 `exit()` 函数的头文件

using namespace std;

// 函数声明：计算两个数的调和平均数，结果通过指针 `ans` 返回
// 返回值为 `true` 表示计算成功，`false` 表示计算失败
bool hmean(double a, double b, double* ans);

int main() {
    double x, y, z;
    cout << "Enter two numbers: "; // 提示用户输入两个数字
    while (cin >> x >> y) { // 读取用户输入的两个数字
        // 调用 hmean 函数计算调和平均数，并检查返回值是否为 true
        if (hmean(x, y, &z)) { // 如果计算成功，输出结果
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        } else { // 如果计算失败，提示用户输入的值非法
            cout << "One value should not be the negative of the other, try again." << endl;
        }
        cout << "Enter next set of number: "; // 提示用户输入下一组数字
    }

    return 0; // 返回0，表示程序正常结束
}

// 函数定义：计算两个数的调和平均数
bool hmean(double a, double b, double* ans) {
    if (a == -b) { // 检查参数是否合法，如果两个数互为相反数
        return false; // 返回 `false` 表示计算失败
    } else {
        *ans =  2.0 * a * b / (a + b); // 通过指针 `ans` 返回计算结果
        return true; // 返回 `true` 表示计算成功
    }
}