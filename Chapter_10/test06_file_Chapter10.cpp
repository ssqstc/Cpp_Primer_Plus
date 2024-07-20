#include "test06_head_Chapter10.h"

/*
 * 构造函数：初始化 x 和 y
 */
Move::Move(double a, double b) {
    x = a; // 初始化 x
    y = b; // 初始化 y
}

/*
 * 显示 x 和 y 的值
 */
void Move::showmove() const {
    cout << "x = " << x << endl; // 输出 x 的值
    cout << "y = " << y << endl; // 输出 y 的值
}

/*
 * 将当前对象和另一个 Move 对象的 x 和 y 相加，并返回一个新的 Move 对象
 */
Move Move::add(const Move &m) const {
    return Move(m.x + this->x, m.y + this->y); // 返回相加后的新 Move 对象
}

/*
 * 重置 x 和 y 的值
 */
void Move::reset(double a, double b) {
    x = a; // 重置 x 的值
    y = b; // 重置 y 的值
}