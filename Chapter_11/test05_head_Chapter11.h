#ifndef __TEST05_HEAD_CHAPTER11_H__
#define __TEST05_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

class Stonewt {
public:
    enum Type { STONE, POUNDS, FLOAT_POUNDS };  // 重量显示类型枚举
private:
    static const int Lbs_per_stn = 14;  // 每英石的磅数
    int stone;  // 英石数
    double pds_left;  // 剩余的磅数
    double pounds;  // 总磅数
    Type type;  // 显示类型
public:
    Stonewt();  // 默认构造函数
    Stonewt(double lbs);  // 初始化为磅
    Stonewt(int stn, double lbs);  // 初始化为英石和磅
    void set_type(Type m);  // 设置显示类型
    Stonewt operator+(const Stonewt &st) const;  // 重载加法运算符
    Stonewt operator-(const Stonewt &st) const;  // 重载减法运算符
    Stonewt operator*(double n) const;  // 重载乘法运算符
    friend ostream &operator<<(ostream &os, const Stonewt &st);  // 重载输出运算符
};

#endif //__TEST05_HEAD_CHAPTER11_H__