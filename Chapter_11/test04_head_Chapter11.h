#ifndef __TEST04_HEAD_CHAPTER11_H__
#define __TEST04_HEAD_CHAPTER11_H__

#include <iostream>
using namespace std;

class Time {
private:
    int hours;  // 小时
    int minutes;  // 分钟
public:
    Time();  // 默认构造函数
    Time(int h, int m = 0);  // 带参数构造函数
    void AddMin(int m);  // 增加分钟数
    void AddHr(int h);  // 增加小时数
    void Reset(int h = 0, int m = 0);  // 重置时间
    friend Time operator+(const Time &s, const Time &t);  // 重载加法运算符
    friend Time operator-(const Time &s, const Time &t);  // 重载减法运算符
    friend Time operator*(double multi, const Time &t);  // 重载乘法运算符
    friend Time operator*(const Time &t, double multi);  // 重载乘法运算符

    friend ostream &operator<<(ostream &os, const Time &t);  // 重载输出运算符
};

#endif //__TEST04_HEAD_CHAPTER11_H__