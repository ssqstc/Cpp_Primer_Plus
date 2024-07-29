#ifndef __TEST02_HEAD_CHAPTER11_H__
#define __TEST02_HEAD_CHAPTER11_H__

#include "iostream"
using namespace std;

namespace VECTOR {
    class Vector {
    public:
        enum Mode {RECT, POL};  // 坐标模式：直角坐标和极坐标
    private:
        double x;  // x坐标或模
        double y;  // y坐标或角度
        Mode mode;  // 当前模式
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        double x_val() const {return x;}  // 获取x值
        double y_val() const {return y;}  // 获取y值
        double mag_val() const;  // 计算模
        double ang_val() const;  // 计算角度
        void polar_mode();  // 切换到极坐标模式
        void rect_mode();  // 切换到直角坐标模式

        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector &a);
        friend ostream &operator<<(ostream &os, const Vector &v);
    };
}

#endif //__TEST02_HEAD_CHAPTER11_H__