#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 结构体定义和使用：
   - 结构体允许将不同类型的数据组合在一起。
   - 使用结构体可以方便地管理和操作相关联的数据。

2. 指针与结构体：
   - 可以使用指针指向结构体，并通过指针访问结构体成员。
   - 使用指针数组可以指向多个结构体实例。

3. 数组与结构体：
   - 可以创建结构体数组，以管理多个结构体实例。
   - 通过数组下标访问结构体数组的成员。

4. 常量指针与结构体：
   - 常量指针指向结构体时，不允许修改指针所指向的内容。
   - 指针的指针用于间接访问结构体数组的成员。

注意点：
- 结构体成员的访问可以通过点运算符（.）或者箭头运算符（->）。
- 使用指针数组和指针的指针时要注意指针指向的正确性。
- 使用`auto`关键字可以自动推导变量类型，但需要确保类型的正确性。
*/

struct antarctica_year_end
{
    int year;  // 年份
};

int main()
{
    // 定义结构体变量并初始化
    antarctica_year_end s01, s02, s03;
    s01.year = 1998;

    // 使用指针访问结构体成员
    antarctica_year_end * pa = &s02;
    pa->year = 1999;

    // 定义结构体数组并初始化第一个成员
    antarctica_year_end trio[3];
    trio[0].year = 2003;
    cout << trio->year << endl;  // 输出第一个结构体成员的年份

    // 定义常量指针数组，指向结构体变量
    const antarctica_year_end *arp[3] = {&s01, &s02, &s03};
    cout << arp[1]->year << endl;  // 输出第二个结构体成员的年份

    // 使用指针的指针访问结构体成员
    const antarctica_year_end **ppa = arp;
    cout << (*ppa)->year << endl;  // 输出第一个结构体成员的年份

    // 使用auto关键字自动推导类型
    auto ppb = arp;
    cout << (*(ppb + 1))->year;  // 输出第二个结构体成员的年份

    return 0;  // 返回0表示程序正常结束
}
