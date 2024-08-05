#ifndef __02_HEAD_CHAPTER12_H__
#define __02_HEAD_CHAPTER12_H__

#include "iostream"
using namespace std;

class String {
private:
    char *str;  // 字符串指针
    int len;  // 字符串长度
    static int num_strings;  // 静态成员变量，统计对象数量
    static const int CINLIM = 80;  // 输入限制

public:
    String();  // 默认构造函数
    String(const char *s);  // 带参构造函数
    ~String();  // 析构函数

    int lenth() const { return len; }  // 返回字符串长度

    String(const String &st);  // 复制构造函数
    String &operator=(const String &st);  // 赋值运算符重载
    String &operator=(const char *ch);  // 赋值运算符重载
    char &operator[](int i);  // 索引运算符重载
    const char &operator[](int i) const;  // 索引运算符重载

    friend bool operator<(const String &str1, const String &str2);  // 比较运算符重载
    friend bool operator>(const String &str1, const String &str2);  // 比较运算符重载
    friend bool operator==(const String &str1, const String &str2);  // 比较运算符重载

    friend ostream &operator<<(ostream &os, const String &st);  // 输出运算符重载
    friend istream &operator>>(istream &is, String &st);  // 输入运算符重载

    static int howMany();  // 返回当前 String 对象数量
};

#endif //__02_HEAD_CHAPTER12_H__