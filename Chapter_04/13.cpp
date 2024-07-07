#include "iostream"
using namespace std;

/**
 * 主函数，演示动态内存分配和指针操作
 *
 * 此程序展示了如何使用`new`关键字动态分配整型和双精度浮点型变量，
 * 并通过指针访问它们的值和地址。同时，它还展示了`sizeof`运算符的用法。
 *
 * @return int 返回0，表示程序正常结束
 */
int main()
{
    // 定义一个整型变量nights并初始化
    int nights = 1001;

    // 动态分配一个整型变量，并用指针pt指向它
    int *pt = new int;
    *pt = 1001;

    // 输出nights的值和地址
    cout << "night value:" << nights << " : location = " << &nights << endl;

    // 输出pt所指变量的值和pt的地址
    cout << "*pt value:" << *pt << " : location = " << pt << endl;

    // 动态分配一个双精度浮点型变量，并用指针pd指向它
    double *pd = new double;
    *pd = 10000001.0;

    // 输出pd所指变量的值和pd的地址
    cout << "*pd value:" << *pd << " : location = " << pd << endl;

    // 输出pd指针本身的地址
    cout << "location of pointer pd:" << &pd << endl;

    // 输出指针和指针所指变量的大小
    cout << "size of pt: " << sizeof(pt) << endl;
    cout << "size of *pt : " << sizeof(*pt) << endl;
    cout << "size of pd: " << sizeof(pd) << endl;
    cout << "size of *pd : " << sizeof(*pd) << endl;

    // 释放动态分配的内存
    delete pt;
    delete pd;

    // 程序正常结束
    return 0;
}
