#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. **结构体和指针：**
   - `struct inflatable` 定义了一个包含三个成员的结构体：字符数组 `name`、浮点型 `volume` 和双精度型 `price`。
   - `inflatable *ps = new inflatable;` 动态分配内存给 `ps` 指针，使其指向一个 `inflatable` 类型的结构体。

2. **成员访问：**
   - `cin.get(ps->name, 20);` 使用箭头操作符 `->` 访问结构体指针的成员。
   - `cin >> (*ps).volume;` 和 `cin >> ps->price;` 可以使用箭头操作符 `->` 或者解引用操作符 `*` 访问结构体成员。

3. **内存管理：**
   - 动态分配内存后必须使用 `delete` 释放，以防止内存泄漏。

注意点：
- 在使用 `cin.get()` 读取字符串时，确保缓冲区足够大以存储输入。
- 读取字符串后紧接着读取其他数据类型时，需注意 `cin` 的缓冲区问题，可以在适当位置清理缓冲区。
- 动态分配的内存一定要使用 `delete` 释放。
*/

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    inflatable *ps = new inflatable;  // 动态分配内存
    cout << "Enter name: ";
    cin.get(ps->name, 20);  // 读取名字到结构体成员
    cout << "Enter volume: ";
    cin >> (*ps).volume;  // 读取体积到结构体成员
    cout << "Enter price: ";
    cin >> ps->price;  // 读取价格到结构体成员

    // 输出结构体成员内容
    cout << "name: " << (*ps).name << " , volume: " << ps->volume << " , price: " << (*ps).price << endl;

    delete ps;  // 释放动态分配的内存
    return 0;
}
