// 头文件保护宏，防止重复包含
#ifndef __01_HEAD_CHAPTER11_H__
#define __01_HEAD_CHAPTER11_H__

#include <iostream>
using namespace std;

// 定义 Time 类
class Time{
private:
    int hours; // 小时
    int minutes; // 分钟
public:
    Time(); // 默认构造函数
    Time(int h, int m = 0); // 带参数构造函数
    void AddMin(int m); // 添加分钟
    void AddHr(int h); // 添加小时
    void Reset(int h = 0, int m = 0); // 重置时间
    Time Sum(const Time &t) const; // 计算总和
    Time operator+(const Time &t) const; // 重载加法运算符
    void show() const; // 显示时间
};

#endif //__01_HEAD_CHAPTER11_H__