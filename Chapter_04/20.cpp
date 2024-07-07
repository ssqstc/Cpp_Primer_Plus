#include "iostream"
using namespace std;
#include "vector"
#include "array"

int main()
{
    double a1[4] = {1.2, 2.4, 3.6, 4.8}; // 传统的C数组，大小固定，分配在栈上

    vector<double> a2(4); // vector是一个动态数组类，分配在堆上，大小可以动态改变
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41}; // array是一个固定大小的数组类，大小在编译时确定，分配在栈上
    array<double, 4> a4;
    a4 = a3; // array支持直接赋值操作

    cout << "a1[2] = " << a1[2] << " at " << &a1[2] << endl; // 数据存储在栈
    cout << "a2[2] = " << a2[2] << " at " << &a2[2] << endl; // 数据存储在堆
    cout << "a3[2] = " << a3[2] << " at " << &a3[2] << endl; // 数据存储在栈
    cout << "a4[2] = " << a4[2] << " at " << &a4[2] << endl; // 数据存储在栈

    a1[-2] = 20.2; // 访问越界，但不会报错，可能导致未定义行为
    cout << "a1[-2] = " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2] = " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] = " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}
