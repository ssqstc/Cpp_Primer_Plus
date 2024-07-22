#include "iostream"
using namespace std;

const int Cities = 5;  // 城市数量
const int Years = 4;   // 年份数量

/*
知识点总结和注意点：
1. 二维数组：
   - 定义和初始化一个二维数组，用于存储不同城市在不同年份的最高温度。
   - 使用嵌套循环遍历和访问二维数组中的元素。

2. 字符串数组：
   - 定义和初始化一个字符串数组，用于存储城市名称。
   - 使用字符串数组输出城市名称。

3. 循环：
   - 使用嵌套的 `for` 循环来遍历城市和年份，以输出每个城市每年的最高温度。

注意点：
- 保持数组索引在有效范围内，以避免越界错误。
- 使用 `const char*` 数组存储字符串，以节省内存。
*/

int main()
{
    // 定义一个字符串数组，存储城市名称
    const char* cities[Cities] =
            {
                    "Gribble City",
                    "Gribble Town",
                    "New Gribble",
                    "San Gribble",
                    "Gribble Vista",
            };

    // 定义一个二维数组，存储不同年份和不同城市的最高温度
    int maxtemps[Years][Cities] =
            {
                    {96, 100, 87, 101, 105},
                    {96, 98, 91, 107, 104},
                    {97, 101, 93, 108, 107},
                    {98, 103, 95, 109, 108}
            };

    // 输出标题
    cout << "City: Maximum temperature for 2008 - 2011" << endl;

    // 使用嵌套循环输出每个城市每年的最高温度
    for (int city = 0; city < Cities; ++city) {
        cout << cities[city] << ":\t";  // 输出城市名称
        for (int year = 0; year < Years; ++year) {
            cout << maxtemps[year][city] << "\t";  // 输出对应年份的最高温度
        }
        cout << endl;  // 换行
    }

    return 0;  // 返回0表示程序正常结束
}
