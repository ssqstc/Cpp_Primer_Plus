#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 指针和字符串：
   - 字符数组可以直接用作字符串，指向字符数组的指针也可以处理字符串。
   - 指向字符串常量的指针不能修改字符串内容。

2. 动态内存分配：
   - `new` 运算符用于在堆上分配内存，`delete` 运算符用于释放内存。
   - 动态分配的内存需要手动释放，避免内存泄漏。

3. 字符串复制：
   - `strcpy` 用于复制字符串，需要确保目标数组有足够的空间。

注意点：
- 确保动态分配的内存使用后被释放。
- 输入字符串时要注意缓冲区的大小，避免缓冲区溢出。
- 使用 `strcpy` 时要确保目标指针有足够的空间容纳源字符串。
*/

int main()
{
    char animal[20] = "bear"; // 定义并初始化一个字符数组
    const char *bird = "wren"; // 定义并初始化一个指向字符串常量的指针
    char *ps; // 定义一个字符指针

    cout << animal << " and " << bird << endl; // 输出animal数组和bird指针指向的字符串

    cout << "Enter a kind of animal: ";
    cin >> animal; // 读取用户输入的动物名称并存储到animal数组中
    cout << animal << endl; // 输出animal数组中的内容

    // ps = animal，指针ps指向animal数组的首地址
    ps = animal;
    cout << ps << endl; // 输出ps指向的字符串
    cout << animal << " location: " << (int*) animal << endl; // 输出animal数组的地址
    cout << ps << " location: " << (int*) ps << endl; // 输出ps指针的地址

    cout << "After using strcpy\n";
    ps = new char[strlen(animal) + 1]; // 动态分配与animal长度相同的内存空间
    strcpy(ps, animal); // 将animal中的字符串复制到动态分配的内存中
    cout << animal << " location: " << (int*) animal << endl; // 输出animal数组的地址
    cout << ps << " location: " << (int*) ps << endl; // 输出动态分配内存的地址

    delete[] ps; // 释放动态分配的内存

    return 0;
}
