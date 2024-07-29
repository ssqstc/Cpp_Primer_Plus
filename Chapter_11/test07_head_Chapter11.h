#ifndef __TEST07_HEAD_CHAPTER11_H__
#define __TEST07_HEAD_CHAPTER11_H__
#include "iostream"
using namespace std;

class complex {
private:
    double real;  // 实部
    double imaginary;  // 虚部
    char i;  // 虚数单位
public:
    complex();  // 默认构造函数
    complex(double re, double im);  // 参数构造函数

    complex operator+(const complex &co) const;  // 加法运算符重载
    complex operator-(const complex &co) const;  // 减法运算符重载
    complex operator*(const complex &co) const;  // 乘法运算符重载
    complex operator~() const;  // 共轭运算符重载

    friend complex operator*(double n, const complex &co);  // 友元函数，实现实数与复数的乘法
    friend complex operator*(const complex &com, double n);  // 友元函数，实现复数与实数的乘法
    friend istream &operator>>(istream &is, complex &co);  // 输入运算符重载
    friend ostream &operator<<(ostream &os, const complex &co);  // 输出运算符重载
};

#endif //__TEST07_HEAD_CHAPTER11_H__