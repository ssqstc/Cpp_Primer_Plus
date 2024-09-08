/*
知识点：
1. **可变参数模板 (Variadic Template)**：允许函数接收不定数量的参数。通过递归调用模板函数，实现对所有参数的累加。
2. **模板递归展开**：通过一个终止函数（即 `sum_value()` 的空参数版本），终止递归展开。每次递归调用处理一个参数，直到所有参数处理完毕。
3. **类型转换**：在累加过程中将所有参数强制转换为 `long double` 类型，以确保计算精度。

注意点：
1. 当传入不同类型的参数时，需要确保类型兼容性。在本例中，通过强制转换为 `long double`，能够避免精度损失或类型不匹配的问题。
2. 字符类型（如 `'a'` 和 `'b'`）在累加时会被转换为其对应的 ASCII 码值（'a' = 97, 'b' = 98），这是需要特别注意的地方。
*/

#include <iostream>
using namespace std;

// 递归终止条件：无参数时返回 0
long double sum_value() {
    return 0;
}

// 可变参数模板：逐个处理参数并递归调用自身
template <typename T, typename... Args>
long double sum_value(T t, Args... args) {
    return (long double)t + sum_value(args...);  // 将每个参数转换为 long double
}

int main() {
    // 调用 sum_value 函数，累加 1, 2, 3
    cout << sum_value(1, 2, 3) << endl;  // 输出 6

    // 调用 sum_value 函数，传入字符 'a'、'b' 及其他数字
    cout << sum_value('a', 'b', 2.2, 3.3, 5, 6, 7) << endl;  // 输出 218.5 ('a'=97, 'b'=98)

    return 0;
}