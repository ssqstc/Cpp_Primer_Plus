#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 动态内存分配：
   - 使用 `new` 运算符可以在运行时动态分配内存。
   - 分配内存后，需要使用指针来访问和操作这块内存。
   - 使用 `delete` 运算符释放动态分配的内存，防止内存泄漏。

2. 指针和动态内存的关系：
   - 定义一个指针，通过 `new` 运算符分配内存，将指针指向这块内存。
   - 通过解引用指针访问和修改内存中的值。
   - 释放内存后，指针不再指向有效的内存地址，应避免继续使用。

注意点：
- 动态内存分配后一定要释放内存，防止内存泄漏。
- 确保释放内存时指针指向有效的动态分配内存。
- 使用完指针后，最好将其置为 `nullptr`，防止野指针问题。
*/

int main()
{
    int nights = 1001;  // 定义整数变量nights并赋值为1001

    int *pt = new int;  // 动态分配一个整数大小的内存空间，pt指向该内存
    *pt = 1001;  // 将动态分配内存中的值设为1001

    // 输出nights的值和地址
    cout << "night value:" << nights << " : location = " << &nights << endl;

    // 输出指针pt指向的值和pt本身的地址
    cout << "*pt value:" << *pt << " : location = " << pt << endl;

    double *pd = new double;  // 动态分配一个双精度浮点数大小的内存空间，pd指向该内存
    *pd = 10000001.0;  // 将动态分配内存中的值设为10000001.0

    // 输出指针pd指向的值和pd本身的地址
    cout << "*pd value:" << *pd << " : location = " << pd << endl;

    // 输出指针pd的地址
    cout << "location of pointer pd:" << &pd << endl;

    // 输出指针pt的大小和指针pt指向的值的大小
    cout << "size of pt: " << sizeof(pt) << endl;
    cout << "size of *pt : " << sizeof(*pt) << endl;
    // 输出指针pd的大小和指针pd指向的值的大小
    cout << "size of pd: " << sizeof(pd) << endl;
    cout << "size of *pd : " << sizeof(*pd) << endl;

    delete pt;  // 释放动态分配的整数内存
    delete pd;  // 释放动态分配的双精度浮点数内存

    return 0;  // 返回0表示程序正常结束
}
