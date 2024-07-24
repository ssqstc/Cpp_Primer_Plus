#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 值传递：函数参数通过值传递，对参数的修改不会影响实际参数。
 * 2. 常量引用传递：函数参数通过常量引用传递，不能修改实际参数，但可以避免值传递的开销。
 *
 * 注意点：
 * 1. 值传递：函数内部对参数的修改仅作用于参数的副本，实际参数不受影响。
 * 2. 常量引用传递：不能修改引用的实际参数，但可以用来避免拷贝大对象带来的性能开销。
 */

double cube(double a);   // 值传递，计算立方值
double recube(const double &ra);  // 常量引用传递，计算立方值

int main() {
    double x = 3.0;  // 定义 double 类型变量 x 并初始化为 3.0
    const double y = 5.0;  // 定义常量 double 类型变量 y 并初始化为 5.0

    cout << cube(x) << " = cube of " << x << endl;  // 调用 cube 函数并输出结果
    cout << recube(x)  << " = cube of " << x << endl;  // 调用 recube 函数并输出结果

    cout << cube(5.0) << " = cube of " << 5.0 << endl;  // 直接传递常量 5.0 给 cube 函数

    cout << cube(5.0 + x) << " = cube of " << "5.0 + x" << endl;  // 传递表达式 5.0 + x 给 cube 函数

    cout << recube(5.0)  << " = cube of " << 5.0 << endl;  // 直接传递常量 5.0 给 recube 函数
    cout << recube(5.0 + x)  << " = cube of " << "5.0 + x" << endl;  // 传递表达式 5.0 + x 给 recube 函数

    cout << recube(y)  << " = cube of " << y << endl;  // 传递常量变量 y 给 recube 函数

    return 0;
}

// 值传递，计算立方值
double cube(double a) {
    a *= a * a;  // 计算 a 的立方值
    return a;  // 返回立方值
}

// 常量引用传递，计算立方值
double recube(const double &ra) {
    return ra * ra * ra;  // 计算 ra 的立方值并返回
}
