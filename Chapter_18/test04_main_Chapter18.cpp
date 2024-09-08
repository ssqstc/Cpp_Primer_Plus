/*
知识点：
1. **Lambda 表达式**：匿名函数，用于简单的函数处理。`outInt` 和 `TooBig` 都是通过 Lambda 表达式定义的匿名函数，用于输出和条件判断。
2. **`std::list` 容器**：`list` 是 C++ STL 中的双向链表，支持高效的插入和删除操作。
3. **`remove_if` 算法**：用于删除满足特定条件的元素。`remove_if` 会根据给定的条件删除列表中的元素，调整容器内容。

注意点：
1. **Lambda 的用法**：匿名函数的灵活性很强，适合在局部作用域内快速定义简单功能。
2. **`remove_if` 的作用**：`remove_if` 直接修改 `list` 容器，而不是返回新的容器。
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Lambda 表达式：输出整数
auto outInt = [] (int x) { cout << x << ' '; };

// Lambda 表达式：判断是否大于 200
auto TooBig = [](int x) { return x > 200; };

int main() {
    // 初始化数组
    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

    // 使用数组初始化两个 list 容器
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);

    // 输出原始列表
    cout << "Original lists: " << endl;
    for_each(yadayada.begin(), yadayada.end(), outInt);  // 输出 yadayada
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outInt);  // 输出 etcetera

    // 移除 yadayada 中大于 100 的元素
    cout << "\nTrimmed lists: " << endl;
    yadayada.remove_if([](int x) { return x > 100; });
    for_each(yadayada.begin(), yadayada.end(), outInt);  // 输出处理后的 yadayada
    cout << endl;

    // 移除 etcetera 中大于 200 的元素
    etcetera.remove_if(TooBig);
    for_each(etcetera.begin(), etcetera.end(), outInt);  // 输出处理后的 etcetera

    return 0;
}