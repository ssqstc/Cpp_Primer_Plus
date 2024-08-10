#ifndef __TEST04_HEAD_CHAPTER13_H__
#define __TEST04_HEAD_CHAPTER13_H__

#include "iostream"
using namespace std;

// Port 类：一个代表酒品牌的类，包含品牌名称、类型和瓶数
class Port {
private:
    char * brand; // 动态分配的品牌名称
    char style[20]; // 固定大小的字符串，表示类型
    int bottles; // 瓶数
public:
    // 构造函数，初始化品牌、类型和瓶数
    Port(const char * br = "none", const char * st = "none",

         int b = 0);
    Port(const Port & p); // 复制构造函数
    virtual ~Port() { delete [] brand; } // 析构函数，释放动态分配的内存
    Port & operator=(const Port & p); // 赋值操作符重载
    Port & operator+=(int b); // 增加瓶数
    Port & operator-=(int b); // 减少瓶数

    int bottleCount() const { return  bottles; } // 返回瓶数
    virtual void show() const; // 显示对象信息
    friend ostream & operator<<(ostream & os, const Port & p); // 重载 << 操作符，输出对象信息
};

// VintagePort 类：继承自 Port 类，代表一种特殊的葡萄酒类型，添加了昵称和年份
class VintagePort : public Port {
private:
    char * nickname; // 动态分配的昵称
    int year; // 年份
public:
    VintagePort(); // 默认构造函数
    VintagePort(const char * br, const char * st, int b, const char * nn, int y); // 构造函数
    VintagePort(const VintagePort & vp); // 复制构造函数
    virtual ~VintagePort() { delete [] nickname; } // 析构函数，释放动态分配的内存
    VintagePort & operator=(const VintagePort & vp); // 赋值操作符重载
    void show() const; // 显示对象信息
    friend ostream & operator<<(ostream & os, const VintagePort & vp); // 重载 << 操作符，输出对象信息
};

#endif //__TEST04_HEAD_CHAPTER13_H__