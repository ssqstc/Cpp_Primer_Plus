/*
知识点：
1. **`initializer_list`**：一种标准库类模板，用于存储传递给函数的统一类型的初始化列表。它常用于允许函数接收可变数量的相同类型参数。
2. **自动类型推导 (auto)**：用于简化代码的自动推导类型，编译器根据表达式的类型自动推导变量类型。
3. **模板参数的显示指定**：通过 `average_list<double>({...})` 这种形式，可以明确指定模板参数类型，避免隐式类型转换的精度丢失问题。

注意点：
1. `initializer_list` 的所有元素必须是同一类型或者能够隐式转换为统一类型。
2. 注意当涉及字符或整型数混合时，可能会发生隐式类型转换，导致意想不到的结果（如 `auto ad = average_list<double>({ 'A', 70, 65.33 })` 中 `'A'` 被转换为 ASCII 码）。
*/

#include <iostream>
using namespace std;

// 模板函数：计算 initializer_list<T> 中元素的平均值
template<typename T>
T average_list(initializer_list<T> il) {
    T ave = 0;  // 初始化累加器
    for (auto x : il) {  // 遍历列表中的所有元素
        ave += x;        // 累加所有元素
    }
    ave /= il.size();    // 计算平均值
    return ave;
}

int main() {
    // 调用模板函数，传递浮点数列表，结果为浮点数
    auto q = average_list({ 15.4, 10.7, 9.0 });
    cout << q << endl;  // 输出：平均值 11.7

    // 调用模板函数，传递整型数列表，结果为整型
    cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;  // 输出：平均值 28

    // 调用模板函数，指定为 double 类型，并传递混合类型列表
    auto ad = average_list<double>({ 'A', 70, 65.33 });
    cout << ad << endl;  // 输出：平均值 66.11 （'A' 被转换为 ASCII 码 65）

    return 0;
}