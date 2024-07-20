#ifndef __TEST06_HEAD_CHAPTER10_H__
#define __TEST06_HEAD_CHAPTER10_H__
#include "iostream"
using namespace std;

class Move{
private:
    double x; // x 坐标
    double y; // y 坐标
public:
    Move(double a = 0, double b = 0); // 构造函数，初始化 x 和 y
    void showmove() const; // 显示 x 和 y
    Move add(const Move &m) const; // 相加两个 Move 对象
    void reset(double a = 0, double b = 0); // 重置 x 和 y 的值
};

#endif //__TEST06_HEAD_CHAPTER10_H__