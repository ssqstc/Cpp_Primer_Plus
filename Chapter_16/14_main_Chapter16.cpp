/*
知识点总结：
1. `multimap` 容器：`multimap` 是 C++ STL 中的关联容器，允许键重复，即同一个键可以关联多个值。适用于需要处理键重复的场景。
2. `pair` 类型：`pair` 是一种用于存储一对值的标准模板类，常用于插入到 STL 容器中。
3. `equal_range`：`equal_range` 返回一个范围，表示具有指定键的所有元素的范围，可以用来遍历所有具有相同键的元素。
4. `count`：`count` 函数用于返回指定键的元素数量，常用于统计 `multimap` 或 `multiset` 中某个键的重复次数。

注意点：
1. `multimap` 中的元素是按键值自动排序的，但键值可以重复，所以插入元素时不会覆盖已有的元素。
2. 使用 `equal_range` 获取范围时，需要注意返回的是一个 `pair`，包含两个迭代器，分别指向范围的起始和结束位置。
3. 在 `for` 循环中使用迭代器遍历 `multimap` 时，应确保迭代器类型正确，注意避免对迭代器进行越界操作。
*/

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;
typedef multimap<int, string> MapCode;  // 定义 multimap 类型，键为 int，值为 string
typedef int KeyType;  // 定义键的类型为 int
typedef pair<KeyType, string> Pair;  // 定义 pair 类型，包含一个键值对

int main() {
    MapCode codes;  // 创建 multimap 容器
    // 插入键值对
    codes.insert(Pair(10, "Beijing"));
    codes.insert(Pair(21, "Shanghai"));
    codes.insert(Pair(22, "Tianjin"));
    codes.insert(Pair(23, "Chongqing"));
    codes.insert(Pair(24, "Shenyang"));
    codes.insert(Pair(22, "Nanjing"));  // 插入重复键值

    // 统计键为22的元素数量
    cout << "Number of cities with area code 22: " << codes.count(22) << endl;

    // 输出所有的键值对
    MapCode::iterator it;  // 定义迭代器
    cout << "Area code \t\t city" << endl;
    for (it = codes.begin(); it != codes.end(); it++) {
        cout << "\t" << (*it).first << "\t\t\t" << (*it).second << endl;  // 输出键和值
    }

    // 输出键为22的所有城市
    cout << "Cities with area code 22: " << endl;
    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(22);  // 获取键为22的范围
    for (it = range.first; it != range.second; it++) {
        cout << (*it).second << endl;  // 输出范围内的所有值
    }

    return 0;  // 返回0，表示程序成功结束
}