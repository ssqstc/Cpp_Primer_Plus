#include "test02_head_Chapter11.h"
#include "cmath"

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);  // 弧度转角度的系数

    double Vector::mag_val() const {
        return sqrt(x * x + y * y);  // 计算向量的模
    }

    double Vector::ang_val() const {
        if (0.0 == x && 0.0 == y) {
            return 0.0;  // 原点的角度为0
        } else {
            return atan2(y, x);  // 计算向量的角度
        }
    }

    Vector::Vector() {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
        } else if (form == POL) {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
        } else {
            cout << "Error" << endl;
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
        } else if (form == POL) {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
        } else {
            cout << "Error" << endl;
            x = y = 0.0;
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
            os << "mag, ang = " << v.mag_val() << ", " << v.ang_val() << endl;  // 输出极坐标
        } else {
            os << "Invalid mode" << endl;  // 无效模式
        }
        return os;
    }
}