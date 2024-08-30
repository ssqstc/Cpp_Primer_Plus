/*
知识点总结：
1. `set` 容器：`set` 是 C++ STL 中的关联容器，元素自动按升序排序且不允许重复。常用于需要快速查找、插入和删除的场景。
2. `set_union`：计算两个集合的并集，并将结果插入到目标范围，结果包含两个集合的所有元素，且不包含重复元素。
3. `set_intersection`：计算两个集合的交集，结果只包含在两个集合中都存在的元素。
4. `set_difference`：计算两个集合的差集，结果包含在第一个集合中出现但在第二个集合中未出现的元素。
5. `insert_iterator`：适配器，用于在容器中插入元素，可以用于算法如 `set_union` 的目标容器。
6. `lower_bound` 和 `upper_bound`：`set` 容器提供的成员函数，用于查找特定范围内的元素，`lower_bound` 返回不小于指定元素的第一个位置，`upper_bound` 返回大于指定元素的第一个位置。

注意点：
1. `set` 容器中的元素是唯一的，重复插入的元素会被忽略。
2. 在使用集合算法如 `set_union`, `set_intersection`, `set_difference` 时，需要保证输入范围是有序的，否则结果可能不正确。
3. `insert_iterator` 可以确保将结果插入到目标容器中，而不会覆盖原有元素。
4. `lower_bound` 和 `upper_bound` 返回的迭代器范围为 [lower_bound, upper_bound)，注意该范围内的元素均小于 `upper_bound` 指定的元素。
*/
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    const int N = 6;  // 定义数组的大小
    string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for"};  // 字符串数组1，包含一些单词
    string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for"};  // 字符串数组2，包含一些单词

    // 将数组s1中的元素插入到set容器A中，自动去重和排序
    set<string> A(s1, s1 + N);
    // 将数组s2中的元素插入到set容器B中，自动去重和排序
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");  // 定义输出迭代器，用于将输出结果插入到标准输出流中

    // 输出集合A的元素
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);

    // 输出集合B的元素
    cout << "\nSet B: ";
    copy(B.begin(), B.end(), out);

    // 输出集合A和集合B的并集
    cout << "\nUnion of A and B: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);

    // 输出集合A和集合B的交集
    cout << "\nIntersection of A and B: ";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);

    // 输出集合A和集合B的差集
    cout << "\nDifference of A and B: ";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);

    // 创建集合C，并将A和B的并集结果插入到集合C中
    set<string> C;
    cout << "\nSet C: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);

    // 将字符串s3插入到集合C中
    string s3("grungy");
    C.insert(s3);
    cout << "\nSet C after insertion: ";
    copy(C.begin(), C.end(), out);

    // 显示集合C中范围为["ghost", "spook")的元素
    cout << "\nShowing a ranger: ";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);

    return 0;  // 返回0，表示程序成功结束
}