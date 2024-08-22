#ifndef HEAD_07_CHAPTER15_H
#define HEAD_07_CHAPTER15_H

#include <iostream> // 包含输入输出流库
using namespace std;

// 定义 bad_hmean 异常类，用于处理 hmean 函数中的错误
class bad_hmean {
private:
    double v1; // 存储出错时的第一个值
    double v2; // 存储出错时的第二个值
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {} // 构造函数初始化列表
    void mesg(); // 成员函数，用于输出错误信息
};

// 内联函数，输出 bad_hmean 的错误信息
inline void bad_hmean::mesg() {
    cout << "hmean(" << v1 << ", " << v2 << "): invalid arguments: a = -b" << endl;
}

// 定义 bad_gmean 异常类，用于处理 gmean 函数中的错误
class bad_gmean {
public:
    double v1; // 存储出错时的第一个值
    double v2; // 存储出错时的第二个值
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {} // 构造函数初始化列表
    const char* mesg(); // 成员函数，返回错误信息
};

// 内联函数，返回 bad_gmean 的错误信息
inline const char* bad_gmean::mesg() {
    return "gmean() arguments should be >= 0";
}

#endif //HEAD_07_CHAPTER15_H