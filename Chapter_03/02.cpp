#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 浮点数表示法：使用科学计数法表示大数。
 * - 浮点数精度问题：大数和小数相加时可能出现精度问题。
 * - 算术运算：浮点数的加减法运算。

 * 注意点：
 * - 浮点数精度：浮点数的精度有限，当两个数量级差距很大的数进行运算时，小数部分可能被舍入。
 */

/*
 * 主函数：演示浮点数的精度问题
 */
int main()
{
    float a = 2.34e22; // 使用科学计数法表示大数
    float b = a + 1.0; // 大数与小数相加

    cout << "a = " << a << endl; // 输出 a 的值
    cout << "b - a = " << b - a << endl; // 输出 b 与 a 的差值

    return 0;
}
