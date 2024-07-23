#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 循环与条件判断：while 循环用于持续获取用户输入，直到条件不满足。
 * - 函数的定义与调用：演示了如何定义和调用函数，以及函数参数的传递。
 * - 数据类型：使用 long double 类型进行高精度计算。

 * 注意点：
 * - 确保输入的有效性：用户输入的 picks 不应超过 total。
 * - 循环和递归计算：确保循环条件和计算公式的正确性。
 */

/*
 * probability 函数：计算中奖概率
 * - 参数：number（游戏卡上的总数），picks（允许选择的数量）
 * - 返回值：中奖的概率
 */
long double probability(unsigned int number, unsigned int picks);

int main() {
    unsigned int total, choices;
    cout << "Enter the total number of choices on the game card and the number of picks allowed:" << endl; // 提示用户输入游戏卡上的总数和允许选择的数量
    while ((cin >> total >> choices) && choices <= total) { // 循环直到用户输入无效或 picks 大于 total
        cout << "You have one chance in " << probability(total, choices) << " of winning." << endl; // 调用函数并输出中奖概率
        cout << "Please enter next two numbers (q to quit): "; // 提示用户再次输入或退出
    }
    cout << "Bye" << endl;
    return 0;
}

long double probability(unsigned int number, unsigned int picks) {
    double n, p;
    long double result = 1.0;
    for (n = number, p = picks; p > 0; n--, p--) { // 计算组合数公式：C(number, picks)
        result = result * n / p;
    }
    return result;
}
