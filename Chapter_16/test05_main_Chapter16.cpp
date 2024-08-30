#include <iostream>
#include <list>
using namespace std;

/*
 * 知识点总结：
 * 1. 模板函数：使用模板函数可以使`reduce`函数适用于不同数据类型的数组（如整型数组和字符串数组）。
 * 2. 使用`std::list`处理数组：`std::list`具备自动调整大小和便捷的去重操作（通过`sort`和`unique`）。
 * 3. 容器的转换与使用：模板函数将数组转换为`std::list`，在`list`中操作后再将数据传回数组。

 * 注意点：
 * 1. 在转换时需注意模板类型一致性：确保模板函数的类型参数`T`在`reduce`函数的不同部分保持一致。
 * 2. `list`容器的操作：`list`的`sort`和`unique`成员函数用于排序和去重，处理过程中自动修改容器内容。
 * 3. 使用迭代器更新原数组：将去重后的数据从`list`迭代器写回到原数组中，并返回去重后的有效大小。
 */

template <typename T>
int reduce(T ar[], int n) {
    list<T> ls; // 创建一个列表以便后续操作

    // 将数组元素插入列表
    for (int i = 0; i < n; ++i) {
        ls.push_back(ar[i]);
    }

    ls.sort();   // 对列表进行排序
    ls.unique(); // 移除重复元素

    // 将去重后的列表元素传回原数组
    auto pt = ls.begin();
    for (int i = 0; i < ls.size(); ++i, ++pt) {
        ar[i] = *pt;
    }

    return ls.size(); // 返回去重后的有效大小
}

int main() {
    // 测试long数组
    long ar[] { 2, 5, 1, 6, 2, 8, 6, 6, 6, 6 };
    int size_ar = reduce(ar, 10);
    for (int i = 0; i < size_ar; ++i) {
        cout << ar[i] << ' ';
    }
    cout << endl;

    // 测试string数组
    string str[] { "ssq", "stc", "dtc", "ssq", "shen" };
    int size_str = reduce(str, 5);
    for (int i = 0; i < size_str; ++i) {
        cout << str[i] << ' ';
    }
    return 0;
}