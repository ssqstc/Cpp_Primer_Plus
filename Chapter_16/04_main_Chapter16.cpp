/*
知识点总结:
1. **字符串初始化**：通过初始化方式创建不同大小的字符串，并展示字符串的内容和容量。
2. **size() 和 capacity()**：`size()` 函数返回字符串的实际长度，`capacity()` 函数返回当前字符串分配的存储容量。
3. **reserve() 函数**：通过 `reserve()` 函数预留字符串的存储空间，以提高性能或避免不必要的内存重新分配。

注意点:
1. **容量和大小的区别**：字符串的容量 `capacity()` 是当前分配的内存空间，可能比字符串的实际大小 `size()` 大，以容纳未来的增长。
2. **预留空间**：使用 `reserve()` 可以在字符串大小增长之前提前预留空间，减少内存重新分配的次数。
*/

#include <iostream>  // 标准输入输出流库
#include <string>    // 标准字符串库

using namespace std;

int main() {
    string empty;  // 初始化一个空字符串
    string small = "bit";  // 初始化一个小字符串
    string larger = "Elephants are a girl's best friend";  // 初始化一个较大的字符串

    // 输出字符串的长度
    cout << "Sizes: " << endl;
    cout << "\t empty: " << empty.size() << endl;  // 输出空字符串的长度
    cout << "\t small: " << small.size() << endl;  // 输出小字符串的长度
    cout << "\t larger: " << larger.size() << endl;  // 输出较大字符串的长度

    // 输出字符串的容量
    cout << "Capacities: " << endl;
    cout << "\t empty: " << empty.capacity() << endl;  // 输出空字符串的容量
    cout << "\t small: " << small.capacity() << endl;  // 输出小字符串的容量
    cout << "\t larger: " << larger.capacity() << endl;  // 输出较大字符串的容量

    empty.reserve(50);  // 预留空字符串的容量为50
    cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;  // 输出空字符串预留空间后的容量

    return 0;  // 程序结束
}