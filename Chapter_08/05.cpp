#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 值传递：函数参数通过值传递，对参数的修改不会影响实际参数。
 * 2. 引用传递：函数参数通过引用传递，对参数的修改会直接影响实际参数。
 *
 * 注意点：
 * 1. 值传递：函数内部对参数的修改仅作用于参数的副本，实际参数不受影响。
 * 2. 引用传递：引用传递使得函数内部对参数的修改直接影响实际参数，需谨慎使用。
 */

double cube(double a);   // 值传递，计算立方值
double recube(double &ra);  // 引用传递，计算立方值并修改原值

int main() {
    double x = 3.0;  // 定义 double 类型变量 x 并初始化为 3.0
    cout << cube(x) << " = cube of " << x << endl;  // 调用 cube 函数并输出结果
    cout << recube(x) << " = cube of " << x << endl;  // 调用 recube 函数并输出结果
    return 0;
}

// 值传递，计算立方值
double cube(double a) {
    a *= a * a;  // 计算 a 的立方值
    return a;  // 返回立方值
}

// 引用传递，计算立方值并修改原值
double recube(double &ra) {
    ra *= ra * ra;  // 计算 ra 的立方值并修改原值
    return ra;  // 返回立方值
}
