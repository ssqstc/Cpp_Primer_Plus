#ifndef __05_HEAD_CHAPTER13_H__
#define __05_HEAD_CHAPTER13_H__

#include "iostream"
#include "cstring"
using namespace std;

// baseDMA类，管理基本的动态内存分配和释放
class baseDMA {
private:
    char *m_label; // 动态分配的字符串，存储标签
    int m_rating; // 评分
public:
    baseDMA(const char *label = "null", int rating = 0); // 构造函数
    baseDMA(const baseDMA &baseDma); // 复制构造函数
    virtual ~baseDMA(); // 虚析构函数
    baseDMA &operator=(const baseDMA &baseDma); // 赋值运算符重载
    friend ostream &operator<<(ostream &os, const baseDMA &baseDma); // 输出运算符重载
};

// lacksDMA类，继承自baseDMA，管理固定长度的color字符串
class lacksDMA : public baseDMA {
private:
    enum { COL_LEN = 40 };
    char m_color[COL_LEN]; // 固定长度的颜色字符串
public:
    lacksDMA(const char *label = "null", int rating = 0, const char *color = "blank"); // 构造函数
    lacksDMA(const baseDMA &baseDma, const char *color = "blank"); // 复制构造函数
    friend ostream &operator<<(ostream &os, const lacksDMA &lacksDma); // 输出运算符重载

};

// hasDMA类，继承自baseDMA，管理动态分配的style字符串
class hasDMA : public baseDMA {
private:
    char *m_style; // 动态分配的字符串，存储样式
public:
    hasDMA(const char *label = "null", int rating = 0, const char *style = "none"); // 构造函数
    hasDMA(const baseDMA &baseDma, const char *style); // 复制构造函数
    hasDMA(const hasDMA &hasDma); // 复制构造函数
    hasDMA &operator=(const hasDMA &hasDma); // 赋值运算符重载
    virtual ~hasDMA(); // 虚析构函数
    friend ostream &operator<<(ostream &os, const hasDMA &hasDma); // 输出运算符重载
};
#endif //__05_HEAD_CHAPTER13_H__
