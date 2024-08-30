#include <iostream>
#include <set>
using namespace std;

/*
 * 知识点总结：
 * 1. **集合（set）**：`set`是C++ STL中一种容器，存储的元素自动排序且无重复。常用操作包括插入、查找、删除等。
 * 2. **集合运算**：使用`set_union`函数将两个集合合并，并将结果存储在一个新集合中。
 * 3. **迭代器（iterator）**：在进行集合操作时，使用迭代器（如`insert_iterator`）可以将结果直接插入目标集合。

 * 注意点：
 * 1. **输入控制**：在输入朋友姓名时，确保“quit”命令能正确退出循环。
 * 2. **集合无重复**：同一名字的朋友只会在集合中出现一次，保证了集合的唯一性。
 * 3. **合并后的集合顺序**：`set_union`合并后的集合元素是按字典序排列的，不同于插入顺序。
 */

set<string> writeFriend() {
    set<string> temp;
    string name;
    cout << "Enter your friend's name (type 'quit' to stop): ";
    while (getline(cin, name) && name != "quit") {
        temp.insert(name); // 插入朋友名字到集合，自动排序且无重复
    }
    return temp; // 返回集合
}

int main() {
    set<string> Mat = writeFriend(); // 输入并存储Mat的朋友列表
    set<string> Pat = writeFriend(); // 输入并存储Pat的朋友列表
    set<string> merge;

    // 合并Mat和Pat的朋友集合，并存储在merge中
    set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(),
              insert_iterator<set<string>>(merge, merge.begin()));

    // 输出Mat的朋友
    cout << "Mat's friends: ";
    for (auto x : Mat) {
        cout << x << ' ';
    }
    cout << endl;

    // 输出Pat的朋友
    cout << "Pat's friends: ";
    for (auto x : Pat) {
        cout << x << ' ';
    }
    cout << endl;

    // 输出合并后的朋友列表
    cout << "Merged friends: ";
    for (auto x : merge) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}