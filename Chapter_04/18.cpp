#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. **动态内存分配：**
   - 使用 `new` 操作符动态分配内存，并使用 `delete[]` 释放内存，防止内存泄漏。
   - 动态分配的内存使用完后必须释放，避免内存泄漏。

2. **字符数组与字符串处理：**
   - 临时字符数组 `tmp` 用于存储用户输入的字符串。
   - 使用 `strlen` 计算字符串长度，并分配相应大小的内存。
   - 使用 `strcpy` 将临时数组中的字符串复制到动态分配的内存中。

3. **函数返回指针：**
   - 函数 `getname` 返回动态分配的字符数组指针。

注意点：
- 使用 `cin` 读取字符串时，确保输入不会超过数组的大小。
- 动态分配内存后必须使用 `delete[]` 释放，以防止内存泄漏。
- 返回指针的函数要确保返回的指针是有效的，不能返回指向局部变量的指针。
*/

char * getname(); // 声明函数

int main()
{
    char *name;

    // 第一次调用getname函数
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete []name; // 释放动态分配的内存

    // 第二次调用getname函数
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete []name; // 释放动态分配的内存

    return 0;
}

char * getname()
{
    char tmp[80]; // 临时数组用于存储用户输入
    cout << "Enter your name: ";
    cin >> tmp; // 读取用户输入的字符串

    // 动态分配内存用于存储输入的字符串
    char *pn = new char[strlen(tmp) + 1]; // +1用于存储字符串结束符
    strcpy(pn, tmp); // 将临时数组中的字符串复制到动态分配的内存中

    return pn; // 返回指向动态分配内存的指针
}
