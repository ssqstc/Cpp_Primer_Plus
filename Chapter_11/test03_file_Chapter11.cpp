#include "test03_head_Chapter11.h"
#include "cmath"

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);  // 弧度转角度的系数

    void Vector::set_mag() {
        mag = sqrt(x * x + y * y);  // 计算向量的模
    }

    void Vector::set_ang() {
        if (0.0 == x && 0.0 == y) {
            ang = 0.0;  // 原点的角度为0
        } else {
            ang = atan2(y, x);  // 计算向量的角度
        }
    }

    void Vector::set_x() {
        x = mag * cos(ang);  // 由模和角度计算x坐标
    }

    void Vector::set_y() {
        y = mag * sin(ang);  // 由模和角度计算y坐标
    }

    Vector::Vector() {
        x = y = mag = ang = 0.0;  // 默认构造函数初始化为0
        mode = RECT;  // 默认模式为直角坐标
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;  // 根据传入的模式初始化
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Error" << endl;
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;  // 根据传入的模式重置向量
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Error" << endl;
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::polar_mode() {
        mode = POL;  // 切换到极坐标模式
    }

    void Vector::rect_mode() {
        mode = RECT;  // 切换到直角坐标模式
    }

    Vector Vector::operator+(const VECTOR::Vector &b) const {
        return Vector(x + b.x, y + b.y);  // 向量加法
    }

    Vector Vector::operator-(const VECTOR::Vector &b) const {
        return Vector(x - b.x, y - b.y);  // 向量减法
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);  // 向量取反
    }

    Vector Vector::operator*(double n) const {
        return Vector(n * x, n * y);  // 向量数乘
    }

    Vector operator*(double n, const Vector &a) {
        return a * n;  // 数乘向量
    }

    ostream &operator<<(ostream &os, const Vector &v) {
        if (v.mode == Vector::RECT) {
            os << "x, y = " << v.x << ", " << v.y << endl;  // 输出直角坐标
        } else if (v.mode == Vector::POL) {
            os << "mag, ang = " << v.mag << ", " << v.ang << endl;  // 输出极坐标
        } else {
            os << "Invalid mode" << endl;  // 无效模式
        }
        return os;
    }
}