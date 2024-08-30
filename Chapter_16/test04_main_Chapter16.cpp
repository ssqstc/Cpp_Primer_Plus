#include <iostream>
#include <set>
#include <algorithm> // 包含sort和unique函数
using namespace std;

/*
 * 知识点总结：
 * 1. 数组排序与去重：使用`sort`对数组进行排序，`unique`去除数组中的重复元素。
 * 2. 指针运算：`unique`返回去重后的数组结尾指针，通过指针差计算新数组大小。
 * 3. 返回数组有效大小：函数返回去重后数组的有效大小，以便后续处理。

 * 注意点：
 * 1. `unique`函数仅去重相邻的重复元素，因此在调用前必须先对数组进行排序。
 * 2. 函数返回的是新数组的有效长度，使用该长度遍历数组时应避免越界。
 * 3. 去重后的数组内容会被修改，应在操作前保存原始数据或深拷贝（如果需要保留原数据）。
 */

int reduce(long ar[], int n) {
    sort(ar, ar + n); // 对数组进行排序
    long *pt = unique(ar, ar + n); // 去除重复元素
    return pt - ar; // 返回去重后数组的新长度
}

int main() {
    long ar[]{ 2, 5, 1, 6, 2, 8, 6, 6, 6, 6 }; // 初始化数组
    int size = reduce(ar, 10); // 调用reduce函数并获取新数组长度
    for (int i = 0; i < size; ++i) { // 输出去重后的数组内容
        cout << ar[i] << ' ';
    }
    return 0;
}