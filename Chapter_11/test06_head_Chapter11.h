#ifndef __TEST06_HEAD_CHAPTER11_H__
#define __TEST06_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

class Stonewt {
private:
    static const int Lbs_per_stn = 14;  // 每英石的磅数
    int stone;  // 英石数
    double pds_left;  // 剩余的磅数
    double pounds;  // 总磅数
public:
    Stonewt(double lbs);  // 初始化为磅
    Stonewt(int stn, double lbs);  // 初始化为英石和磅
    Stonewt();  // 默认构造函数

    bool operator==(const Stonewt &st) const;  // 重载等于运算符
    bool operator>(const Stonewt &st) const;  // 重载大于运算符
    bool operator<(const Stonewt &st) const;  // 重载小于运算符
    bool operator<=(const Stonewt &st) const;  // 重载小于等于运算符
    bool operator>=(const Stonewt &st) const;  // 重载大于等于运算符
    bool operator!=(const Stonewt &st) const;  // 重载不等于运算符

    friend ostream &operator<<(ostream &os, const Stonewt &st);  // 重载输出运算符
};

#endif //__TEST06_HEAD_CHAPTER11_H__