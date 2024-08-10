/*
 * test03_head_Chapter13.h - 类声明文件
 * 
 * 包含抽象基类ABC及其派生类`baseDMA`, `lacksDMA`, `hasDMA`的声明。
 * 提供了类的构造函数、复制构造函数、赋值运算符、析构函数，以及多态的`view`虚函数。
 */

#ifndef __TEST03_HEAD_CHAPTER13_H__
#define __TEST03_HEAD_CHAPTER13_H__

#include "iostream" // 包含输入输出流库
#include "cstring" // 包含C风格字符串处理函数
using namespace std;

// ABC类：抽象基类，提供基本的标签和评分管理功能
class ABC {
private:
    char *m_label; // 标签指针，指向动态分配的字符串
    int m_rating; // 评分
protected:
    // 保护成员函数，返回标签和评分
    const char *label() const { return m_label; }
    int rating() const { return m_rating; }
public:
    // 构造函数、复制构造函数、析构函数和赋值运算符的声明
    ABC(const char *label = "null", int rating = 0);
    ABC(const ABC &abc);
    virtual ~ABC();
    ABC &operator=(const ABC &abc);
    virtual void view() const = 0; // 纯虚函数，用于显示对象信息
};

// baseDMA类：ABC类的派生类，继承标签和评分功能
class baseDMA : public ABC {
public:
    baseDMA(const char *label = "null", int rating = 0) : ABC(label, rating) {} // 构造函数
    baseDMA(const baseDMA &baseDma) : ABC(baseDma) {} // 复制构造函数
    virtual void view() const; // 重写view函数，显示标签和评分
};

// lacksDMA类：ABC类的派生类，增加颜色属性
class lacksDMA : public ABC {
private:
    enum { COL_LEN = 40 }; // 常量定义，表示颜色字符串的最大长度
    char m_color[COL_LEN]; // 颜色字符串
public:
    lacksDMA(const char *label = "null", int rating = 0, const char *color = "blank"); // 构造函数
    lacksDMA(const ABC &abc, const char *color = "blank"); // 基于基类对象的构造函数
    virtual ~lacksDMA() {} // 析构函数
    lacksDMA &operator=(const lacksDMA &lacksDma); // 赋值运算符重载
    virtual void view() const; // 重写view函数，显示标签、评分和颜色
};

// hasDMA类：ABC类的派生类，增加风格属性
class hasDMA : public ABC {
private:
    char *m_style; // 风格字符串，动态分配内存
public:
    hasDMA(const char *label = "null", int rating = 0, const char *style = "none"); // 构造函数
    hasDMA(const ABC &abc, const char *style); // 基于基类对象的构造函数
    hasDMA(const hasDMA &hasDma); // 复制构造函数
    hasDMA &operator=(const hasDMA &hasDma); // 赋值运算符重载
    virtual ~hasDMA(); // 析构函数
    virtual void view() const; // 重写view函数，显示标签、评分和风格
};

#endif //__TEST03_HEAD_CHAPTER13_H__