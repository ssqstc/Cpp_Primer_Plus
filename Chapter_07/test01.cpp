#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 调和平均数：计算两个数的调和平均数公式为 (2 * num1 * num2) / (num1 + num2)。
 * 2. 循环和条件判断：使用 while 循环读取用户输入，直到输入的任意一个数字为零。
 *
 * 注意点：
 * 1. 输入有效性检查：确保输入的数字不为零，以避免除零错误。
 * 2. 循环控制：在 while 循环中同时检查两个条件，确保循环正确终止。
 */

double harmonic_mean(double num1, double num2);

int main() {
    double number1, number2;
    cout << "Enter two numbers, until one of them is zero:" << endl;  // 提示用户输入两个数字，直到其中一个为零
    while (cin >> number1 >> number2 && number1 != 0 && number2 != 0) {  // 读取输入，并检查输入是否不为零
        cout << "Harmonic mean = " << harmonic_mean(number1, number2) << endl;  // 计算并输出调和平均数
    }

    return 0;
}

double harmonic_mean(double num1, double num2) {  // 计算调和平均数的函数
    return 2.0 * num1 * num2 / (num1 + num2);  // 调和平均数公式
}
