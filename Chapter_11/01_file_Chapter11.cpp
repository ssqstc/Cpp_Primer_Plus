#include "01_head_Chapter11.h"

// 默认构造函数，将 hours 和 minutes 初始化为 0
Time::Time() {
    hours = minutes = 0;
}

// 带参数构造函数，初始化 hours 和 minutes
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

// 添加分钟，并处理进位
void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

// 添加小时
void Time::AddHr(int h) {
    hours += h;
}

// 重置时间
void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

// 计算两个 Time 对象的总和
Time Time::Sum(const Time &t) const {
    Time sum;
    sum.minutes = t.minutes + this->minutes;
    sum.hours = t.hours + this->hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

// 重载加法运算符，计算两个 Time 对象的总和
Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = t.minutes + this->minutes;
    sum.hours = t.hours + this->hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

// 显示时间
void Time::show() const {
    cout << hours << " hours, " << minutes << " minutes." << endl; // 输出时间
}