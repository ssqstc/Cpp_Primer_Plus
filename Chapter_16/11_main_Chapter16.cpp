/*
知识点总结：
1. `string` 类：C++ 标准库中的 `string` 类用于表示和操作字符串。
2. `vector` 容器：`vector` 是 C++ 标准模板库(STL)中的序列容器，支持动态数组，能够在运行时改变大小。
3. `copy` 函数：`copy` 是 STL 中的算法，用于将一段范围内的元素复制到另一个范围。
4. `iterator` 迭代器：
   - `back_insert_iterator`：一种插入迭代器，将元素添加到容器的末尾。
   - `insert_iterator`：一种插入迭代器，允许在容器的指定位置插入元素。
5. `for_each` 函数：STL 算法，用于对指定范围内的每个元素执行某个操作。

注意点：
1. 使用 `vector<string>` 容器时，要确保容器有足够的空间来容纳所有元素。
2. `copy` 函数使用时，目标范围不能重叠源范围，并且要保证目标迭代器有足够的空间。
3. `back_insert_iterator` 和 `insert_iterator` 迭代器的使用时机不同，前者适合在容器末尾插入元素，后者则用于在指定位置插入。
4. 迭代器操作要注意容器的有效性，尤其在插入或删除元素时，需确保容器状态稳定。
*/
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

// 输出字符串的函数
void outPut(string& s) {
    cout << s << ' ';  // 输出字符串，并在其后加一个空格
}

int main() {
    // 初始化字符串数组 s1、s2 和 s3
    string s1[4] = { "abc", "def", "ghi", "jkl" };  // s1 包含 4 个元素
    string s2[2] = { "hello", "world" };            // s2 包含 2 个元素
    string s3[2] = { "good", "morning" };           // s3 包含 2 个元素

    // 创建一个包含 4 个元素的 vector 容器，初始化为 s1 的值
    vector<string> words(4);
    copy(s1, s1 + 4, words.begin());  // 将 s1 数组中的元素复制到 words 容器中
    for_each(words.begin(), words.end(), outPut);  // 输出 words 容器中的所有元素
    cout << endl;

    // 使用 back_insert_iterator 在 words 容器的末尾插入 s2 的值
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), outPut);  // 输出添加了 s2 元素后的 words 容器中的所有元素
    cout << endl;

    // 使用 insert_iterator 在 words 容器的开头插入 s3 的值
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), outPut);  // 输出添加了 s3 元素后的 words 容器中的所有元素
    cout << endl;

    return 0;  // 返回 0，表示程序成功结束
}