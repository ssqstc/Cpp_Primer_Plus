/*
知识点总结：
1. `list` 容器：C++ 标准库中的 `list` 是一个双向链表容器，适合在序列中间进行插入和删除操作。由于其内部结构为双向链表，插入和删除操作的时间复杂度为 O(1)。
2. `remove` 方法和 `remove` 函数：
   - `remove(4)` 方法：直接从 `list` 容器中删除所有值为 4 的元素，不需要进一步调用 `erase`。
   - `remove` 函数：虽然在序列中移除了指定的元素，但并不改变容器的大小，返回一个指向新的逻辑结束位置的迭代器。要完全删除元素并缩小容器，需要进一步调用 `erase`。
3. `for_each` 函数：用于对容器中的每个元素执行指定操作，方便快捷地输出和处理容器中的数据。

注意点：
1. 使用 `remove` 函数时，需要结合 `erase` 函数来缩小容器的大小，否则容器大小不会改变，可能会造成数据的混淆。
2. `remove` 和 `erase` 的组合使用在性能上比 `remove_if` 更高效，特别是对于复杂数据类型。
3. 在调用 `erase` 函数时，要确保传入的迭代器范围是有效的，即迭代器指向的范围要在 `list` 容器中。

*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 定义一个函数用于展示每个元素
void show(int n);

const int LIM = 10; // 定义一个常量，用于数组大小

int main() {
    int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };  // 初始化一个数组
    list<int> la(ar, ar + LIM);  // 用数组初始化列表 la
    list<int> lb(ar, ar + LIM);  // 用数组初始化列表 lb

    cout << "Original list: " << endl;  // 输出原始列表
    cout << "la: ";
    for_each(la.begin(), la.end(), show);  // 使用 for_each 输出 la 列表的内容

    cout << "\nlb: ";
    for_each(lb.begin(), lb.end(), show);  // 使用 for_each 输出 lb 列表的内容

    // 使用 remove(4) 方法移除所有值为 4 的元素
    la.remove(4);
    cout << "\nAfter remove(4) method..." << endl;
    cout << "la: ";
    for_each(la.begin(), la.end(), show);  // 使用 for_each 输出 la 列表的内容

    // 使用 remove() 函数从 lb 中移除所有值为 4 的元素
    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4);
    cout << "\nAfter remove() function..." << endl;
    cout << "lb: ";
    for_each(lb.begin(), lb.end(), show);  // 使用 for_each 输出 lb 列表的内容

    // 使用 erase() 函数来移除逻辑删除后的无效元素
    lb.erase(last, lb.end());
    cout << "\nAfter erase() function..." << endl;
    cout << "lb: ";
    for_each(lb.begin(), lb.end(), show);  // 使用 for_each 输出 lb 列表的内容

    return 0;  // 结束程序
}

// 定义用于输出整数的函数
void show(int n) {
    cout << n << ' ';  // 逐个输出列表中的元素，并以空格分隔
}