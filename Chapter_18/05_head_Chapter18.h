#ifndef HEAD_05_CHAPTER18_H
#define HEAD_05_CHAPTER18_H

#include <iostream>
using namespace std;

// 模板函数，接受一个值和一个函数作为参数
template<typename T, typename F>
T use_f(T t, F f) {
    static int count = 0;  // 静态变量，记录调用次数
    count++;
    cout << "use_f count = " << count << ", &count = " << &count << endl;
    return f(t);  // 调用传递的函数对象
}

// 仿函数类 Fp，重载 operator()，将输入的参数与成员变量相乘
class Fp {
    double z_;
public:
    // 构造函数，初始化成员变量 z_
    Fp(double z = 1.0) : z_(z) {}

    // 重载的 operator()，实现仿函数功能
    double operator()(double p) { return z_ * p; }
};

// 仿函数类 Fq，重载 operator()，将输入的参数与成员变量相加
class Fq {
    double z_;
public:
    // 构造函数，初始化成员变量 z_
    Fq(double z = 1.0) : z_(z) {}

    // 重载的 operator()，实现仿函数功能
    double operator()(double q) { return z_ + q; }
};

#endif //HEAD_05_CHAPTER18_H