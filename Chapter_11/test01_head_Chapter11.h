#ifndef __TEST01_HEAD_CHAPTER11_H__
#define __TEST01_HEAD_CHAPTER11_H__

#include "iostream"  // 包含输入输出流库
using namespace std;

namespace VECTOR {
    class Vector {
    public:
        enum Mode {RECT, POL};  // 定义模式：直角坐标和极坐标
    private:
        double x;  // x 坐标
        double y;  // y 坐标
        double mag;  // 向量的模
        double ang;  // 向量的角度
        Mode mode;  // 模式：RECT 或 POL
        void set_mag();  // 设置模
        void set_ang();  // 设置角度
        void set_x();  // 设置 x 坐标
        void set_y();  // 设置 y 坐标
    public:
        Vector();  // 默认构造函数
        Vector(double n1, double n2, Mode form = RECT);  // 构造函数，接受两个参数和模式
        void reset(double n1, double n2, Mode form = RECT);  // 重置向量
        double x_val() const {return x;}  // 获取 x 坐标
        double y_val() const {return y;}  // 获取 y 坐标
        double mag_val() const {return mag;}  // 获取模
        double ang_val() const {return ang;}  // 获取角度
        void polar_mode();  // 切换到极坐标模式
        void rect_mode();  // 切换到直角坐标模式

        Vector operator+(const Vector &b) const;  // 向量加法
        Vector operator-(const Vector &b) const;  // 向量减法
        Vector operator-() const;  // 向量取反
        Vector operator*(double n) const;  // 向量与标量相乘

        friend Vector operator*(double n, const Vector &a);  // 标量与向量相乘
        friend ostream &operator<<(ostream &os, const Vector &v);  // 输出运算符重载
    };
}

#endif //__TEST01_HEAD_CHAPTER11_H__
