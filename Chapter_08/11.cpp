#include "iostream"
using namespace std;

/*
这个程序展示了C++中的模板函数的定义和使用。
主要知识点和注意事项：
1. 模板函数的定义和基本语法。
2. 函数模板的实例化和调用。
3. 引用参数的传递方式。
4. 模板函数对不同类型数据的适用性。
*/

// 定义一个模板函数 Swap，用于交换两个同类型变量的值
template <typename T>
void Swap(T &a, T &b);

int main(){
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    Swap(i, j); // 交换整数变量 i 和 j 的值
    cout << "After swap, now i, j = " << i << ", " << j << "." << endl;

    double x = 24.5, y = 81.7;
    cout << "x, y = " << x << ", " << y << "." << endl;
    Swap(x, y); // 交换双精度浮点数变量 x 和 y 的值
    cout << "After swap, now x, y = " << x << ", " << y << "." << endl;

    return 0;
}

// 模板函数的定义，用于交换两个同类型变量的值
template <typename T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
