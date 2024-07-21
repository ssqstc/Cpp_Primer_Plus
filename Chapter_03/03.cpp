#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 类型转换：不同数据类型之间的隐式转换。
 * - 浮点数和整数的存储及精度问题：浮点数转换为整数时会丢失小数部分。
 * - 科学计数法表示：用于表示非常大的数或非常小的数。

 * 注意点：
 * - 类型转换时的精度丢失：浮点数转换为整数时，小数部分会被舍弃。
 * - 科学计数法表示的数值过大时会超出整数的表示范围，可能会导致意外的结果。
 */

/*
 * 主函数：演示不同数据类型的隐式转换
 */
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置输出格式为固定浮点数格式

    float tree = 3; // 浮点数变量
    int guess = 3.9832; // 浮点数转换为整数，舍弃小数部分
    int debt = 7.2E12; // 科学计数法表示的数值过大，超出整数表示范围

    cout << "tree = " << tree << endl; // 输出浮点数变量 tree
    cout << "guess = " << guess << endl; // 输出整数变量 guess
    cout << "debt = " << debt << endl; // 输出整数变量 debt，可能会得到意外结果

    return 0;
}
