#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 函数参数：理解如何向函数传递参数。
 * - 返回值：函数可以返回一个计算结果。
 * - 输入输出：使用 cin 和 cout 进行用户交互。

 * 注意点：
 * - 确保函数声明与定义匹配。
 * - 注意变量的作用域和生命周期，避免使用未初始化的变量。
 */

/*
 * cheers 函数：输出指定次数的 "Cheers "
 * - 参数：n（要输出的次数）
 */
void cheers(int n);

/*
 * cube 函数：计算立方值
 * - 参数：x（要计算的数）
 * - 返回值：x 的立方值
 */
double cube(double x);

/*
 * 主函数：演示函数调用和用户交互
 * - 调用 cheers 函数输出 "Cheers "
 * - 获取用户输入并计算立方值
 * - 输出计算结果
 */
int main() {
    cheers(5); // 调用 cheers 函数输出 5 次 "Cheers "
    cout << "Give me a number:"; // 提示用户输入一个数字

    double side;
    cin >> side; // 获取用户输入
    double volume = cube(side); // 计算立方值
    cout << side << " side cube = " << volume << endl; // 输出立方值

    cheers(cube(2)); // 调用 cheers 函数，参数为 2 的立方值

    return 0;
}

void cheers(int n) {
    for (int i = 0; i < n; ++i) // 循环输出指定次数的 "Cheers "
        cout << "Cheers ";
    cout << endl;
}

double cube(double x) {
    return x * x * x; // 返回 x 的立方值
}
