#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 浮点数精度：不同精度的浮点数（float 和 double）。
 * - 常量定义：使用 const 关键字定义常量。
 * - 标准输出格式：如何设置输出的浮点数格式。
 * - 科学计数法：使用科学计数法表示大数。

 * 注意点：
 * - 浮点数运算：注意浮点数的精度和舍入误差。
 * - 输出格式设置：使用 cout.setf() 设置浮点数的输出格式。
 */

/*
 * 主函数：演示浮点数的精度和输出格式
 */
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置输出格式为定点小数形式

    float tub = 10.0 / 3.0; // 浮点数计算
    double mint = 10.0 / 3.0; // 双精度浮点数计算
    const float Million = 1.0e6; // 常量定义，表示一百万
    cout << "tub = " << tub; // 输出 tub 的值
    cout << ", a Million tubs = " << Million * tub; // 输出一百万个 tub 的值
    cout << ", \nand ten Million tubs = "; // 输出换行符和字符串
    cout << 10 * Million * tub << endl; // 输出一千万个 tub 的值
    cout << "mint = " << mint << " and a Million mints = "; // 输出 mint 的值和字符串
    cout << Million * mint << endl; // 输出一百万个 mint 的值

    return 0;
}
