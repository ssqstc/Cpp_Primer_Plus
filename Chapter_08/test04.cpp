#include "iostream"
using namespace std;
#include "cstring" // 包含字符串处理函数

/*
这个程序展示了结构体的使用、动态内存分配、函数重载和默认参数的使用。
主要知识点和注意事项：
1. 结构体的定义和使用。
2. 动态内存分配与释放。
3. 函数重载，提供不同类型参数的处理。
4. 默认参数的使用，简化函数调用。

注意：
1. 动态内存分配后应在适当时机释放，防止内存泄漏。
2. `strcpy` 用于字符串复制，需要确保目标数组有足够的空间。
3. 函数重载要确保不同参数类型的正确处理。
*/

// 结构体定义，用于存储字符串和长度
struct stringy {
    char *str; // 动态分配的字符串
    int ct; // 字符串的长度
};

// 函数声明，设置 stringy 结构体
void set(stringy &stry, const char arr[]); // 设置 stringy 结构体
// 函数声明，显示 stringy 结构体中的字符串
void show(stringy &stry, int n = 1); // 显示 stringy 结构体中的字符串，默认显示一次
// 函数声明，显示字符数组
void show(const char str[], int n = 1); // 显示字符数组，默认显示一次

int main() {
    stringy beany{}; // 定义并初始化 stringy 结构体
    char testing[] = "Reality isn't what it used to be."; // 定义字符数组

    set(beany, testing); // 设置 beany 结构体

    show(beany); // 显示 beany 结构体中的字符串
    show(beany, 2); // 显示 beany 结构体中的字符串两次
    testing[0] = 'D'; // 修改字符数组中的第一个字符
    testing[1] = 'u'; // 修改字符数组中的第二个字符
    show(testing); // 显示修改后的字符数组
    show(testing, 3); // 显示修改后的字符数组三次
    show("Done!"); // 显示字符串 "Done!"

    return 0;
}

// 函数定义，设置 stringy 结构体
void set(stringy &stry, const char arr[]) {
    stry.ct = strlen(arr) + 1; // 计算字符串长度，加1是为了包含终止符
    stry.str = new char[stry.ct]; // 动态分配内存
    strcpy(stry.str, arr); // 复制字符串到动态分配的内存中
}

// 函数定义，显示 stringy 结构体中的字符串
void show(stringy &stry, int n) {
    for (int i = 0; i < n; ++i) { // 循环显示 n 次
        cout << stry.str << endl; // 输出字符串
    }
}

// 函数定义，显示字符数组
void show(const char str[], int n) {
    for (int i = 0; i < n; ++i) { // 循环显示 n 次
        cout << str << endl; // 输出字符数组
    }
}
