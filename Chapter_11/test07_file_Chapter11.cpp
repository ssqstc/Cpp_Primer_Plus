#include "test07_head_Chapter11.h"

complex::complex() {
    real = imaginary = 0.0;  // 初始化实部和虚部为0
    i = 'i';  // 初始化虚数单位
}

complex::complex(double re, double im) {
    real = re;  // 初始化实部
    imaginary = im;  // 初始化虚部
    i = 'i';  // 初始化虚数单位
}

complex complex::operator+(const complex &co) const {
    return complex(real + co.real, imaginary + co.imaginary);  // 实现复数加法
}

complex complex::operator-(const complex &co) const {
    return complex(real - co.real, imaginary - co.imaginary);  // 实现复数减法
}

complex complex::operator*(const complex &co) const {
    // 实现复数乘法
    return complex(real * co.real - imaginary * co.imaginary, real * co.imaginary + imaginary * co.real);
}

complex complex::operator~() const {
    return complex(real, -imaginary);  // 实现复数共轭
}

complex operator*(double n, const complex &co) {
    return complex(n * co.real, n * co.imaginary);  // 实现复数与实数的乘法
}

complex operator*(const complex &co, double n) {
    return n * co;  // 实现复数与实数的乘法（交换律）
}

istream &operator>>(istream &is, complex &co) {
    cout << "real: ";
    is >> co.real;  // 从输入流中读取实部
    cout << "imaginary: ";
    is >> co.imaginary;  // 从输入流中读取虚部
    return is;
}

ostream &operator<<(ostream &os, const complex &co) {
    os << "(" << co.real << "," << co.imaginary << co.i << ")";  // 按格式输出复数
    return os;
}