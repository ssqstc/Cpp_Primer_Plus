#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. `for` 循环：
   - 使用 `for` 循环来计算每年的利息。
   - 初始条件为第 1 年，循环条件是复利小于等于单利，循环体内每年更新一次利息。

2. 利息计算：
   - 单利（simple interest）计算方式：每年利息为本金的 10%，每年累加。
   - 复利（compound interest）计算方式：每年利息为本金和之前所有复利的 5%。

注意点：
- 初始本金为 100 美元。
- 复利计算时需要考虑之前累积的复利和本金之和。
- 确保循环条件正确，直到复利超过单利。
*/

const int Principal = 100; // 定义初始本金

int main()
{
    double simple_interest = 0, compound_interest = 0; // 初始化单利和复利
    int year; // 定义年份计数器
    for (year = 1; compound_interest <= simple_interest ; ++year) { // 使用for循环计算利息直到复利超过单利
        simple_interest += Principal * 0.1; // 每年累加单利
        compound_interest += (compound_interest + Principal) * 0.05; // 每年累加复利
    }
    cout << "第" << year << "年，Cleo的投资价值超过Daphne。\n"
         << "此时，Daphne的单利: " << simple_interest << "$\tCleo的复利：" << compound_interest << "$";

    return 0; // 返回0表示程序正常结束
}
