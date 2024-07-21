#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 指针与数组：
   - 指针可以指向数组的首地址，通过指针运算可以访问数组元素。
   - 使用指针可以遍历和操作数组。

2. 指针算术运算：
   - 指针加一后，指向下一个元素的地址，元素类型不同，步长也不同。
   - 注意指针算术运算后不要越界访问数组。

3. sizeof运算符：
   - `sizeof` 用于计算类型或对象的大小（以字节为单位）。
   - 对于数组，`sizeof` 返回整个数组的大小；对于指针，`sizeof` 返回指针本身的大小（通常是指针类型的大小）。

注意点：
- 操作指针时，确保指针没有越界访问数组。
- 使用 `sizeof` 计算数组大小时，应用在数组名上而不是指针。
*/

int main()
{
    double wages[] = { 10000.0, 20000.0, 30000.0 };  // 定义一个double类型的数组
    short stacks[] = {3, 2, 1};  // 定义一个short类型的数组

    double *pw = wages;  // 指向wages数组首元素的指针
    short *ps = &stacks[0];  // 指向stacks数组首元素的指针

    // 输出指针pw指向的地址和值
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw++;  // 指针后移，指向下一个元素
    // 输出指针pw后移后的地址和值
    cout << "pw+1后，pw = " << pw << ", *pw = " << *pw << endl;

    // 输出指针ps指向的地址和值
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps++;  // 指针后移，指向下一个元素
    // 输出指针ps后移后的地址和值
    cout << "ps+1后，ps = " << ps << ", *ps = " << *ps << endl;

    // 输出stacks数组的元素
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    // 使用指针访问stacks数组的元素
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;

    // 输出wages数组的大小
    cout << "size of wages array = " << sizeof(wages) << endl;
    // 输出指针pw的大小
    cout << "size of pw pointer = " << sizeof(pw) << endl;

    return 0;
}
