/*
知识点总结:
1. **数组与向量拷贝**：使用 `std::copy` 将数组 `casts` 的内容复制到向量 `dice` 中。
2. **迭代器**：使用普通迭代器、反向迭代器以及输出流迭代器操作和遍历向量数据。
3. **标准库算法**：使用 `std::copy` 函数进行数据复制，并通过输出流迭代器将数据直接输出到 `cout`。

注意点:
1. **迭代器类型匹配**：确保 `copy` 函数中源和目标容器的迭代器类型匹配，避免编译错误。
2. **反向迭代器使用**：在遍历向量时，`reverse_iterator` 需要配合 `rbegin()` 和 `rend()` 函数使用，确保反向遍历的正确性。
*/

#include <iostream>   // 标准输入输出流库
#include <iterator>   // 标准迭代器库，包含 ostream_iterator, reverse_iterator
#include <vector>     // 标准向量库
using namespace std;

int main() {
    int casts[10] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};  // 初始化数组
    vector<int> dice(10);  // 创建大小为 10 的向量 dice
    copy(casts, casts + 10, dice.begin());  // 将数组 casts 的内容复制到向量 dice 中

    // 创建输出流迭代器，将输出数据格式化为以空格分隔
    ostream_iterator<int, char> out_iter(cout, " ");
    // 将向量 dice 的内容复制到输出流迭代器，输出到控制台
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;
    cout << "----------------Dividing----------------" << endl;

    // 反向复制向量 dice 的内容并输出到控制台
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;
    cout << "----------------Dividing----------------" << endl;

    // 使用反向迭代器遍历向量 dice 并输出内容
    vector<int>::reverse_iterator ri;
    for (ri = dice.rbegin(); ri != dice.rend(); ri++) {
        cout << *ri << ' ';
    }
    cout << endl;

    return 0;
}