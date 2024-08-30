#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

/*
 * 知识点总结：
 * 1. **排序算法**：`sort`用于对容器进行排序，时间复杂度为O(n log n)，适用于随机访问迭代器的容器（如`vector`）。
 * 2. **容器类型**：`vector`适合快速随机访问，而`list`适合频繁插入和删除操作，但不支持随机访问。
 * 3. **性能对比**：本程序通过对`vector`和`list`排序的时间进行对比，展示了不同容器在排序中的性能差异。
 * 4. **重置容器**：通过`copy`函数将初始乱序数据重置到`list`容器中，确保多次排序结果的准确性。

 * 注意点：
 * 1. **排序性能**：`vector`使用`sort`排序比`list`直接调用`sort`更快，因为`vector`支持随机访问。
 * 2. **时间测量**：使用`clock()`函数测量代码运行时间，确保对不同部分代码执行时间的准确比较。
 * 3. **重置list容器**：在每次排序前，需将`list`容器的数据恢复为初始状态，避免排序影响结果。
 */

int main() {
    srand(time(0));  // 初始化随机数种子
    const int limit = 1000000;  // 数据量

    // 初始化vector容器vi0，并填充随机数
    vector<int> vi0(limit);
    for (auto& x : vi0) {
        x = rand() % 1000;
    }

    // 将vi0的数据复制到新的vector容器vi中，并初始化list容器li
    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    // 记录并输出vector排序时间
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "vector: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    // 记录并输出list排序时间
    start = clock();
    li.sort();
    end = clock();
    cout << "list: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "----------------Dividing----------------" << endl;

    // 重置list容器为乱序状态
    copy(vi0.begin(), vi0.end(), li.begin());
    start = clock();

    // 将list容器的数据复制到vector容器中排序，再复制回list容器
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());

    // 记录并输出上述操作的总时间
    end = clock();
    cout << "after list: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}