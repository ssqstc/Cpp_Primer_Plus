#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 动态内存分配：使用new操作符分配字符数组。
 * 2. 指针操作：操作动态分配的内存。
 * 3. 字符串处理：构建指定字符重复的字符串。
 *
 * 注意点：
 * 1. 内存管理：动态分配内存后要及时释放，避免内存泄漏。
 * 2. 字符串终止符：在构建字符串时要确保最后一个字符为字符串终止符'\0'。
 * 3. 输入验证：确保输入的数据类型与变量类型一致。
 */

char *buildstr(char c, int n); // 构建重复字符的字符串

int main(){
    char ch;
    int times;
    cout << "Enter a character: "; // 输入一个字符
    cin >> ch;
    cout << "Enter an integer: "; // 输入一个整数
    cin >> times;

    char *ps = buildstr(ch, times); // 构建包含重复字符的字符串
    cout << ps << endl; // 输出构建的字符串

    delete []ps; // 释放动态分配的内存
    return 0;
}

char *buildstr(char c, int n){ // 构建包含重复字符的字符串的函数定义
    char *pstr = new char[n + 1]; // 动态分配内存，包含字符串终止符
    pstr[n] = '\0'; // 设置字符串终止符
    for (int i = 0; i < n; ++i) { // 填充字符
        pstr[i] = c;
    }
    return pstr; // 返回构建的字符串
}
