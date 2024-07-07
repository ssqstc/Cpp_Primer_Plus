#include <iostream>
using namespace std;

int main()
{
    int auks, bats, coots;

    // auks: 直接将浮点数相加，结果为31.98，赋值给整型变量时被截断为31
    auks = 19.99 + 11.99;

    // bats: 先将浮点数转换为整型，然后相加，结果为19 + 11 = 30
    bats = (int) 19.99 + (int) 11.99;

    // coots: 与bats相同，使用另一种类型转换的语法
    coots = int (19.99) + int (11.99);

    cout << "auks = " << auks << " bats = " << bats << " coots = " << coots << endl;

    char ch = 'Z';

    // 输出字符Z的ASCII码值，int (ch)将字符转换为整型值
    cout << "The code for " << ch << " is " << int (ch) << endl;

    // 使用static_cast<int>进行类型转换，效果相同
    cout << static_cast<int>(ch) << endl;

    return 0;
}
