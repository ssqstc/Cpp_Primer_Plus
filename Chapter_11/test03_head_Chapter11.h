#ifndef __TEST03_HEAD_CHAPTER11_H__
#define __TEST03_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

namespace VECTOR {
    class Vector {
    public:
        enum Mode {RECT, POL};  // 坐标模式：直角坐标和极坐标
    private:
        double x;  // x坐标或模
        double y;  // y坐标或角度
        double mag;  // 模
        double ang;  // 角度
        Mode mode;  // 当前模式
        void set_mag();  // 设置模
        void set_ang();  // 设置角度
        void set_x();  // 设置x坐标
        void set_y();  // 设置y坐标
    public:
        Vector();  // 默认构造函数
        Vector(double n1, double n2, Mode form = RECT);  // 带参构造函数
        void reset(double n1, double n2, Mode form = RECT);  // 重置向量
        double x_val() const { return x; }  // 返回x坐标
        double y_val() const { return y; }  // 返回y坐标
        double mag_val() const { return mag; }  // 返回模
        double ang_val() const { return ang; }  // 返回角度
        void polar_mode();  // 切换到极坐标模式
        void rect_mode();  // 切换到直角坐标模式

        Vector operator+(const Vector &b) const;  // 向量加法
        Vector operator-(const Vector &b) const;  // 向量减法
        Vector operator-() const;  // 向量取反
        Vector operator*(double n) const;  // 向量数乘

        friend Vector operator*(double n, const Vector &a);  // 数乘向量
        friend ostream &operator<<(ostream &os, const Vector &v);  // 输出向量
    };
}

#endif //__TEST03_HEAD_CHAPTER11_H__