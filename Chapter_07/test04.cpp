#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 概率计算：计算从给定数量中抽取指定数量的不重复事件的概率。
 * 2. 乘法法则：独立事件概率的乘积计算。
 *
 * 注意点：
 * 1. 循环计算：确保循环体的正确执行以计算组合概率。
 * 2. 函数返回：确保函数在循环结束后正确返回结果，而不是在循环内部返回。
 */

long double probability(unsigned int number, unsigned int picks);

int main() {
    long double field = probability(47, 5); // 计算从47个数中选5个数的概率
    long double special = probability(27, 1); // 计算从27个数中选1个数的概率
    long double result = field * special; // 组合概率
    cout << result << endl; // 输出结果
    cout << "Bye" << endl; // 输出结束语
    return 0;
}

long double probability(unsigned int number, unsigned int picks) {
    long double result = 1.0; // 初始化结果为1.0
    for (unsigned int n = number, p = picks; p > 0; n--, p--) { // 从number中选picks个数
        result = result * n / p; // 计算组合概率
    }
    return result; // 返回结果
}
