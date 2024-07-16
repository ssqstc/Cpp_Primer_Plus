#include "iostream"
using namespace std;
// 引用的属性和特别之处
double cube(double a); // 值传递的方式声明立方函数
double recube(double &ra); // 引用的方式声明立方函数

int main() {
    double x = 3.0; // 定义并初始化变量 x
    // 输出 x 的立方和 x 的值
    cout << cube(x) << " = cube of " << x << endl; // 27 = cube of 3
    // 输出通过引用计算 x 的立方后的结果和 x 的值
    cout << recube(x) << " = cube of " << x << endl; // 27 = cube of 27
    return 0;
}

double cube(double a) { // 值传递的方式定义立方函数
    a *= a * a; // 计算 a 的立方
    return a;
}

double recube(double &ra) { // 引用的方式定义立方函数
    ra *= ra * ra; // 计算 ra 的立方，并直接修改 ra 的值
    return ra;
}
