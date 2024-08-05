#ifndef __01_HEAD_CHAPTER12_H__
#define __01_HEAD_CHAPTER12_H__

#include "iostream"
using namespace std;

class StringBad {
private:
    char *str;  // 字符串指针
    int len;  // 字符串长度
    static int num_strings;  // 静态成员变量，统计对象数量
public:
    StringBad();  // 默认构造函数
    StringBad(const char *s);  // 带参构造函数
    ~StringBad();  // 析构函数

    StringBad(const StringBad &st);  // 复制构造函数
    StringBad &operator=(const StringBad &st);  // 赋值运算符重载

    friend ostream &operator<<(ostream &os, const StringBad &st);  // 输出运算符重载
};

#endif //__01_HEAD_CHAPTER12_H__