#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 类型转换：不同数据类型之间的显式和隐式转换。
 * - 强制类型转换：使用C风格和C++风格的强制类型转换。
 * - ASCII码：字符和其对应的ASCII码值的转换。

 * 注意点：
 * - C风格类型转换和C++风格类型转换的区别：C++建议使用`static_cast`等更安全的转换方式。
 * - 浮点数转换为整数时会舍弃小数部分。
 */

/*
 * 主函数：演示不同数据类型的转换和字符的ASCII码表示
 */
int main()
{
    int auks, bats, coots;

    auks = 19.99 + 11.99; // 隐式转换，结果为整数
    bats = (int) 19.99 + (int) 11.99; // C风格强制类型转换，将浮点数转换为整数
    coots = int (19.99) + int (11.99); // 另一种C风格强制类型转换，将浮点数转换为整数
    cout << "auks = " << auks << " bats = " << bats << " coots = " << coots << endl; // 输出转换结果

    char ch = 'Z'; // 字符变量
    cout << "The code for " << ch << " is " << int (ch) << endl; // 将字符转换为对应的ASCII码
    cout << static_cast<int>(ch) << endl; // 使用C++风格的`static_cast`进行类型转换

    return 0;
}
