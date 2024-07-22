#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 多维数组：
   - `sales_volume[3][12]` 用于存储 3 年的每个月的销售量。
   - `total[3]` 用于存储每年的总销售量。

2. 输入和累加：
   - 使用嵌套 `for` 循环输入每年的每个月销售量。
   - 使用嵌套 `for` 循环计算每年的总销售量。

3. 总销售量计算：
   - 输出每年的总销售量。
   - 最后输出 3 年的总销售量。

注意点：
- 确保数组大小一致，避免越界访问。
- 使用适当的数据类型来存储和处理数组数据。
*/

int main()
{
    const string Month[] = {"1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"}; // 月份数组
    int sales_volume[3][12], total[3] = {}; // 销售量数组和每年的总销售量数组

    // 输入每年的每个月的销售量
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            cout << "Enter " << i + 1 << " year " << Month[j] << "《C++ For Fools》book sales volume：";
            cin >> sales_volume[i][j];
        }
    }

    // 计算每年的总销售量
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            total[i] += sales_volume[i][j];
        }
        cout << i + 1 << " year sales volume：" << total[i] << endl; // 输出每年的总销售量
    }

    // 计算并输出所有年的总销售量
    int grand_total = total[0] + total[1] + total[2];
    cout << "3年总销售额：" << grand_total << endl;

    return 0; // 返回0表示程序正常结束
}
