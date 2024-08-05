#ifndef __TEST02_HEAD_CHAPTER12_H__
#define __TEST02_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstring"
#include "cctype"
using namespace std;

class String {
private:
    static int const CINLIMIT = 60;
    char *m_str;  // 字符串指针
    int m_len;  // 字符串长度
public:
    String();  // 默认构造函数
    String(const char *a_ch);  // 带参数的构造函数
    String(const String &a_st);  // 拷贝构造函数
    ~String();  // 析构函数

    void stringLow();  // 转换为小写
    void stringUp();  // 转换为大写
    int has(const char a_n) const;  // 统计字符个数

    String &operator=(const String &a_st);  // 赋值运算符重载
    String &operator=(const char *a_ch);  // 赋值运算符重载
    String operator+(const String &a_st) const;  // 加法运算符重载

    friend istream &operator>>(istream &a_is, String &a_st);  // 输入运算符重载
    friend ostream &operator<<(ostream &a_os, const String &a_st);  // 输出运算符重载
    friend String operator+(const char *a_ch, const String &a_st);  // 加法运算符重载
    friend bool operator==(const String &a_st1, const String &a_st2);  // 比较运算符重载
};



#endif //__TEST02_HEAD_CHAPTER12_H__
