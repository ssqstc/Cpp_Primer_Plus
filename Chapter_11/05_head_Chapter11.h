// 头文件

#ifndef __05_HEAD_CHAPTER11_H__
#define __05_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

namespace VECTOR {
    class Vector {
    public:
        enum Mode {RECT, POL}; // 枚举类型用于表示坐标模式
    private:
        double x; // x分量
        double y; // y分量
        double mag; // 向量模
        double ang; // 向量角度
        Mode mode; // 当前模式
        void set_mag(); // 设置模
        void set_ang(); // 设置角度
        void set_x(); // 设置x分量
        void set_y(); // 设置y分量
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        double x_val() const {return x;} // 返回x分量
        double y_val() const {return y;} // 返回y分量
        double mag_val() const {return mag;} // 返回模
        double ang_val() const {return ang;} // 返回角度
        void polar_mode(); // 切换到极坐标模式
        void rect_mode(); // 切换到直角坐标模式

        Vector operator+(const Vector &b) const; // 重载加法运算符
        Vector operator-(const Vector &b) const; // 重载减法运算符
        Vector operator-() const; // 重载负号运算符
        Vector operator*(double n) const; // 重载乘法运算符

        friend Vector operator*(double n, const Vector &a); // 友元重载乘法运算符
        friend ostream &operator<<(ostream &os, const Vector &v); // 友元重载输出运算符
    };
}

#endif //__05_HEAD_CHAPTER11_H__