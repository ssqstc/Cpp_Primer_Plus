#ifndef __TEST01_HEAD_CHAPTER12_H__
#define __TEST01_HEAD_CHAPTER12_H__

#include "cstring"
#include "iostream"
using namespace std;

class Cow {
private:
    char m_name[20];  // 名称
    char *m_hobby;  // 爱好
    double m_weight;  // 体重
public:
    Cow();  // 默认构造函数
    Cow(const char *a_name, const char *a_hobby, double a_weight);  // 带参数的构造函数
    Cow(const Cow &a_cow);  // 拷贝构造函数
    ~Cow();  // 析构函数
    Cow & operator=(const Cow &a_cow);  // 赋值运算符重载
    void showCow() const;  // 显示Cow对象的信息
};

#endif //__TEST01_HEAD_CHAPTER12_H__