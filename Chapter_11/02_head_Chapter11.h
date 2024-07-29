#ifndef __02_HEAD_CHAPTER11_H__
#define __02_HEAD_CHAPTER11_H__

#include <iostream>
using namespace std;

/*
 * Time 类定义
 * 模拟时间的基本运算：加法、减法、乘法
 */
class Time{
private:
    int hours;
    int minutes;
public:
    Time(); // 构造函数
    Time(int h, int m = 0); // 带参数的构造函数
    void AddMin(int m); // 添加分钟
    void AddHr(int h); // 添加小时
    void Reset(int h = 0, int m = 0); // 重置时间
    Time operator+(const Time &t) const; // 重载+运算符
    Time operator-(const Time &t) const; // 重载-运算符
    Time operator*(const double multi) const; // 重载*运算符
    void show() const; // 显示时间
    friend Time operator*(double multi, const Time &t); // 友元函数，重载*运算符
};

#endif //__02_HEAD_CHAPTER11_H__