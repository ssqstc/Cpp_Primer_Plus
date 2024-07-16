#include "iostream"
using namespace std;

/*
这个程序展示了模板函数和非模板函数的重载以及显式实例化。
主要知识点和注意事项：
1. 函数模板和非模板函数的重载。
2. 模板函数的显式实例化。
3. 不同函数调用的优先级。

注意：
1. 编译器会优先选择非模板函数，如果参数完全匹配。
2. 使用显式实例化时，可以强制调用模板函数而不是非模板函数。
3. 显式实例化时，如果类型不匹配，可能会导致隐式转换。
*/

// 模板函数的定义，返回两个值中较小的一个
template <typename T>
T lesser(T a, T b){
    return a < b ? a : b; // 返回较小的值
}

// 非模板函数的定义，处理整数类型，返回绝对值较小的一个
int lesser(int a, int b){
    a = a < 0 ? -a : a; // 将 a 变为绝对值
    b = b < 0 ? -b : b; // 将 b 变为绝对值
    return a < b ? a : b; // 返回绝对值较小的值
}

int main(){
    int m = 20, n = -30;
    double x = 15.5, y = 25.9;

    cout << lesser(m, n) << endl;   // 20 调用非模板函数

    cout << lesser(x, y) << endl;   // 15.5 调用模板函数

    cout << lesser<>(m, n) << endl;   // -30 指定调用模板函数
    cout << lesser<int>(x, y) << endl;    // 15 将 x 和 y 强制转换为 int 类型代入到模板函数中处理

    return 0;
}
