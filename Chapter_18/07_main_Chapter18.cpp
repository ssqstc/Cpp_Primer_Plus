/*
知识点：
1. **变参模板 (Variadic Template)**：通过模板参数包和展开参数包，实现能够接受任意数量参数的函数模板。
2. **递归调用**：变参模板通过递归调用自身来逐一处理参数列表中的每个参数，直至参数包展开完毕。

注意点：
1. 变参模板的最后递归调用需要有一个终止函数，即 `show_list()`，确保递归终止。
2. 在递归过程中，`show_list` 通过展开参数包逐一处理每个参数，最后输出格式可以根据需求调整。

*/

#include <iostream>
#include <string>
using namespace std;

// 空函数：递归终止条件，表示没有参数时调用
void show_list() {}

// 单参数模板：处理一个参数并输出
template<typename T>
void show_list(const T& value) {
    cout << value << endl;  // 输出最后一个参数（递归结束）
}

// 多参数模板：处理第一个参数，并递归调用处理剩余参数
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args) {
    cout << value << ", ";   // 输出当前参数
    show_list(args...);      // 递归调用，处理剩余参数
}

int main() {
    int n = 14;              // 整型变量
    double x = 2.71828;       // 双精度浮点型
    string mr = "Mr Joker ";  // 字符串

    // 调用 show_list 处理两个参数
    show_list(n, x);          // 输出格式：14, 2.71828

    // 调用 show_list 处理多个参数
    show_list(x * x, '!', 7, mr);  // 输出格式：7.38905, !, 7, Mr Joker

    return 0;
}