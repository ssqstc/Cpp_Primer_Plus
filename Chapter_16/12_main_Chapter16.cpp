/*
知识点总结：
1. `list` 容器：`list` 是 C++ STL 中的双向链表容器，支持快速插入和删除操作，适用于需要频繁插入/删除的场景。
2. `for_each` 函数：遍历容器中的元素，并对每个元素应用指定的操作，如输出或修改。
3. `insert` 函数：用于在容器中插入元素，可指定插入位置。
4. `remove` 函数：删除容器中所有与指定值匹配的元素。
5. `splice` 函数：将一个 `list` 容器的内容插入到另一个 `list` 容器中的指定位置。
6. `unique` 函数：删除连续重复的元素，仅保留第一个出现的元素。
7. `sort` 函数：对 `list` 容器中的元素进行排序。
8. `merge` 函数：将两个已排序的 `list` 容器合并为一个。

注意点：
1. `list` 容器不支持随机访问，使用时需要通过迭代器进行遍历操作。
2. `splice` 操作会改变源容器和目标容器的内容和结构，使用时需注意顺序和位置的影响。
3. `unique` 函数在调用前要确保容器已排序或已去重，否则无法去除非连续重复的元素。
4. `merge` 函数要求两个 `list` 容器必须是有序的，否则合并后的结果可能不符合预期。
*/
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

// 输出整数的函数
void outInt(int n) { cout << n << ' '; }

int main() {
    // 创建一个包含5个元素的 list 容器 one，所有元素都初始化为2
    list<int> one(5, 2);
    cout << "List one: ";
    for_each(one.begin(), one.end(), outInt);  // 输出 one 中的元素
    cout << endl;

    // 创建一个数组 stuff，并使用 insert 将其元素插入到 list 容器 two 中
    int stuff[5] = { 1, 2, 4, 8, 6 };
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    cout << "List two: ";
    for_each(two.begin(), two.end(), outInt);  // 输出 two 中的元素
    cout << endl;

    // 复制 list 容器 two 到 three，并在 three 的末尾插入数组 more 的元素
    int more[6] = { 6, 4, 2, 4, 6, 5 };
    list<int> three(two);
    three.insert(three.end(), more, more + 6);
    cout << "List three: ";
    for_each(three.begin(), three.end(), outInt);  // 输出 three 中的元素
    cout << endl;

    // 删除 three 中所有值为4的元素
    cout << "List three minus 4: ";
    three.remove(4);
    for_each(three.begin(), three.end(), outInt);  // 输出删除后的 three 中的元素
    cout << endl;

    // 将 list 容器 one 的内容插入到 three 的开头
    cout << "List three after splice: ";
    three.splice(three.begin(), one);
    for_each(three.begin(), three.end(), outInt);  // 输出 splice 操作后的 three 中的元素
    cout << endl;

    // 删除 three 中所有连续重复的元素
    cout << "List three after unique: ";
    three.unique();
    for_each(three.begin(), three.end(), outInt);  // 输出 unique 操作后的 three 中的元素
    cout << endl;

    // 对 three 进行排序后，再次删除所有连续重复的元素
    cout << "List three after sort & unique: ";
    three.sort();
    three.unique();
    for_each(three.begin(), three.end(), outInt);  // 输出排序和去重后的 three 中的元素
    cout << endl;

    // 对 two 进行排序后，合并到 three 中
    cout << "Sorted two merged into three: ";
    two.sort();
    three.merge(two);
    for_each(three.begin(), three.end(), outInt);  // 输出合并后的 three 中的元素
    cout << endl;

    return 0;  // 返回 0，表示程序成功结束
}