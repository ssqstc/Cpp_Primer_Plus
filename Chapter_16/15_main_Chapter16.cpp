/*
知识点总结：
1. 模板类 `TooBig`：模板类允许用户定义一个通用的类，可以用于多种数据类型。`TooBig` 类实现了函数对象，用于筛选大于指定值的元素。
2. 函数对象（仿函数）：`TooBig` 类通过重载 `operator()` 实现了一个函数对象（仿函数），可以像普通函数一样使用，但具有状态（即类的成员变量）。
3. `list` 容器：`list` 是一种双向链表容器，适合频繁的插入、删除操作。在本例中，用于存储和操作整数序列。
4. `remove_if`：`remove_if` 是一个 STL 算法函数，它根据提供的谓词函数（如 `TooBig` 仿函数）删除容器中符合条件的元素。

注意点：
1. 使用模板类时，需明确指定数据类型，例如 `TooBig<int>` 用于处理 `int` 类型数据。
2. `remove_if` 函数会根据提供的谓词函数筛选出符合条件的元素并将其删除，原容器会被修改。
3. 在调用仿函数时，仿函数的状态（如 `cutoff` 值）会参与运算，因此可以灵活定义不同的筛选条件。
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

// 模板类 TooBig，用于筛选大于指定值的元素
template<typename T>
class TooBig {
private:
    T cutoff;  // 截止值
public:
    // 构造函数，接受一个截止值
    TooBig(const T& t) : cutoff(t) {}
    // 重载函数调用操作符，用于判断值是否大于截止值
    bool operator()(const T& v) { return v > cutoff; }
};

// 输出整数的函数
void outInt(int n) {
    cout << n << ' ';
}

int main() {
    TooBig<int> f100(100);  // 创建仿函数对象，截止值为100
    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };  // 初始化数组

    // 使用数组元素初始化两个 list 容器
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);

    // 输出原始列表
    cout << "Original lists: " << endl;
    for_each(yadayada.begin(), yadayada.end(), outInt);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outInt);

    // 使用仿函数 f100 删除大于 100 的元素
    cout << "\nTrimmed lists: " << endl;
    yadayada.remove_if(f100);
    for_each(yadayada.begin(), yadayada.end(), outInt);
    cout << endl;

    // 使用临时仿函数对象删除大于 200 的元素
    etcetera.remove_if(TooBig<int>(200));
    for_each(etcetera.begin(), etcetera.end(), outInt);

    return 0;  // 程序结束，返回0
}