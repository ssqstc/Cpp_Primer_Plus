#ifndef __04_HEAD_CHAPTER11_H__
#define __04_HEAD_CHAPTER11_H__

#include <iostream>
using namespace std;

class Time {
private:
    int hours;    // 小时
    int minutes;  // 分钟
public:
    Time();               // 默认构造函数
    Time(int h, int m = 0);  // 带参数构造函数
    void AddMin(int m);   // 增加分钟数
    void AddHr(int h);    // 增加小时数
    void Reset(int h = 0, int m = 0);  // 重置时间
    Time operator+(const Time &t) const;  // 运算符重载 +
    Time operator-(const Time &t) const;  // 运算符重载 -
    Time operator*(double multi) const;   // 运算符重载 *
    friend Time operator*(double multi, const Time &t);  // 友元函数，运算符重载 *
    friend ostream &operator<<(ostream &os, const Time &t);  // 友元函数，运算符重载 <<
};

#endif //__04_HEAD_CHAPTER11_H__