#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 字符指针：使用字符指针遍历字符串。
 * 2. 字符串常量：字符串常量的处理。
 * 3. 函数返回值：通过函数返回字符出现的次数。
 *
 * 注意点：
 * 1. 指针操作：指针的自增操作遍历字符串时要注意避免越界。
 * 2. 字符比较：比较字符时要注意字符类型的一致性。
 * 3. 返回值类型：函数返回值为无符号整数，注意类型匹配。
 */

unsigned int c_in_str(const char *str, char ch); // 计算字符在字符串中出现次数的函数声明

int main(){
    char mmm[15] = "minimum"; // 定义字符串 mmm
    const char *wail = "ululate"; // 定义字符串常量 wail

    unsigned int ms = c_in_str(mmm, 'm'); // 计算字符 'm' 在 mmm 中出现的次数
    unsigned int us = c_in_str(wail, 'u'); // 计算字符 'u' 在 wail 中出现的次数

    cout << ms << " m character in " << mmm << endl; // 输出结果
    cout << us << " u character in " << wail << endl; // 输出结果
    return 0;
}

unsigned int c_in_str(const char *str, char ch){ // 计算字符在字符串中出现次数的函数定义
    int count = 0; // 初始化计数器
    while (*str){ // 遍历字符串，直到字符串结束
        if (*str == ch){ // 如果当前字符与目标字符相同
            count++; // 计数器加1
        }
        str++; // 指向下一个字符
    }
    return count; // 返回计数结果
}
