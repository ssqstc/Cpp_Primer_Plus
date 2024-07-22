#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 使用数组存储月份和销量数据。
2. 通过 sizeof 计算数组的大小，避免硬编码数组大小。
3. 使用 for 循环来读取每个月的销量数据，并计算总销量。

注意点：
- 数组的大小计算：`sizeof array / sizeof array[0]`。
- 确保每次循环时输入的数据正确并累加到总销量中。

字符串翻译：
- "Enter" 翻译为 "输入"
- "sales volume" 翻译为 "销售量"
- "total" 翻译为 "总计"
*/

int main()
{
    const string Month[] = {"1月","2月","3月","4月","5月","6月","7月","8月","9月","10月","11月","12月"};
    int sales_volume[sizeof Month / sizeof Month[0]], total = 0; // 使用 sizeof 计算数组大小

    // 读取每个月的销售量
    for (int i = 0; i < sizeof Month / sizeof Month[0]; ++i) {
        cout << "输入 " << Month[i] << "《C++ For Fools》书籍销售量：";
        cin >> sales_volume[i];
    }

    // 计算总销售量
    for (int i = 0; i < sizeof sales_volume / sizeof sales_volume[0]; ++i) {
        total += sales_volume[i];
    }

    // 输出总销售量
    cout << "今年销售总量：" << total;
    return 0; // 返回0表示程序正常结束
}
