#include "05_head_Chapter11.h"
#include "cmath"

namespace VECTOR{
    const double Rad_to_deg = 45.0 / atan(1.0); // 弧度到角度转换系数

    void Vector::set_mag() {
        mag = sqrt(x * x + y * y); // 计算并设置向量的模
    }

    void Vector::set_ang() {
        if (0.0 == x && 0.0 == y){
            ang = 0.0; // 如果向量为零向量，则角度为0
        } else{
            ang = atan2(y, x); // 计算并设置向量的角度
        }
    }

    void Vector::set_x() {
        x = mag * cos(ang); // 根据模和角度计算并设置x坐标
    }

    void Vector::set_y() {
        y = mag * sin(ang); // 根据模和角度计算并设置y坐标
    }

    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = RECT; // 初始化为零向量，模式为直角坐标
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang(); // 直角坐标模式下设置坐标并计算模和角度
        } else if (form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y(); // 极坐标模式下设置模和角度并计算坐标
        } else{
            cout << "Error" << endl;
            x = y = mag = ang = 0.0;
            mode = RECT; // 错误模式处理
        }
    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT){
            x = n1;
            y = n2;
            set_mag();
            set_ang(); // 重置直角坐标
        } else if (form == POL){
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y(); // 重置极坐标
        } else{
            cout << "Error" << endl;
            x = y = mag = ang = 0.0;
            mode = RECT; // 错误模式处理
        }
    }

    void Vector::polar_mode() {
        mode = POL; // 设置为极坐标模式
    }

    void Vector::rect_mode() {
        mode = RECT; // 设置为直角坐标模式
    }

    Vector Vector::operator+(const VECTOR::Vector &b) const {
        return Vector(x + b.x, y + b.y); // 向量加法
    }

    Vector Vector::operator-(const VECTOR::Vector &b) const {
        return Vector(x - b.x, y - b.y); // 向量减法
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y); // 取反向量
    }

    Vector Vector::operator*(double n) const {
        return Vector(n * x, n * y); // 向量数乘
    }

    Vector operator*(double n, const Vector &a){
        return a * n; // 交换顺序的向量数乘
    }

    ostream &operator<<(ostream &os, const Vector &v){
        if (v.mode == Vector::RECT){
            os << "x, y = " << v.x << ", " << v.y << endl; // 输出直角坐标
        } else if (v.mode == Vector::POL){
            os << "mag, ang = " << v.mag << ", " << v.ang << endl; // 输出极坐标
        } else{
            os << "Invalid mode" << endl; // 错误模式处理
        }
        return os;
    }
}