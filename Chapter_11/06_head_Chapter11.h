#ifndef __06_HEAD_CHAPTER11_H__
#define __06_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

class Stonewt {
private:
    static const int Lbs_per_stn = 14; // 每英石等于14磅
    int stone; // 英石部分
    double pds_left; // 英石后剩余的磅数
    double pounds; // 总磅数
public:
    Stonewt(double lbs); // 构造函数，接受磅数
//    explicit Stonewt(double lbs); // 显示构造函数，防止隐式转换
    Stonewt(int stn, double lbs); // 构造函数，接受英石和磅数
    Stonewt(); // 默认构造函数
    void show_lbs() const; // 显示重量，以磅为单位
    void show_stn() const; // 显示重量，以英石为单位
};

#endif //__06_HEAD_CHAPTER11_H__
