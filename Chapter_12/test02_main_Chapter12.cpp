#include "test02_head_Chapter12.h"

/*
知识点总结:
1. **类的构造函数和析构函数**: 包括默认构造函数、带参数的构造函数、拷贝构造函数和析构函数。
2. **运算符重载**: 重载赋值运算符、比较运算符、插入运算符、提取运算符以及加法运算符。
3. **友元函数**: 友元函数的使用如重载的提取运算符和插入运算符。
4. **字符串处理**: 包括字符串的大小写转换、字符统计等功能。
5. **动态内存管理**: 动态分配和释放字符数组的内存。

注意点:
1. **内存管理**: 确保动态分配的内存在析构函数和赋值运算符中被正确释放，避免内存泄漏。
2. **字符串操作**: 确保字符串复制时的边界处理，避免越界操作。
3. **自赋值检查**: 赋值运算符重载中需要处理自赋值的情况，避免不必要的操作。
*/

int main() {
    String s1(" and I am a C++ student.");  // 带参数的构造函数
    String s2 = "Please enter your name: ";  // 赋值构造
    String s3;  // 默认构造函数
    cout << s2;  // 输出提示信息
    cin >> s3;  // 输入姓名
    s2 = "My name is " + s3;  // 字符串连接
    cout << s2 << ".\n";  // 输出连接后的字符串
    s2 = s2 + s1;  // 连接两个字符串
    s2.stringUp();  // 转换为大写
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";  // 统计'A'字符个数
    s1 = "red";  // 赋值操作

    String rgb[3] = { String(s1), String("green"), String("blue") };  // 初始化数组
    cout << "Enter the name of a primary color for mixing light: ";  // 提示信息
    String ans;  // 默认构造函数
    bool success = false;  // 用于标记是否找到匹配的颜色
    while (cin >> ans) {
        ans.stringLow();  // 转换为小写
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i]) {  // 比较字符串
                cout << "That's right!\n";  // 匹配成功
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";  // 匹配失败，提示重新输入
    }
    cout << "Bye\n";  // 结束提示
    return 0;
}