#include "04_head_Chapter11.h"

// 默认构造函数，初始化小时和分钟为 0
Time::Time() {
    hours = minutes = 0;
}

// 带参数构造函数，初始化小时和分钟
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

// 增加分钟数，并处理小时数的进位
void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

// 增加小时数
void Time::AddHr(int h) {
    hours += h;
}

// 重置时间
void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

// 运算符重载 +，用于时间相加
Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = t.minutes + this->minutes;
    sum.hours = t.hours + this->hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

// 运算符重载 -，用于时间相减
Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1, tot2;
    tot1 = this->hours * 60 + this->minutes;
    tot2 = t.hours * 60 + t.minutes;
    diff.hours = (tot1 - tot2) / 60;
    diff.minutes = (tot1 - tot2) % 60;
    return diff;
}

// 运算符重载 *，用于时间乘以倍数
Time Time::operator*(double multi) const {
    Time result;
    long totalminutes = hours * multi * 60 + minutes * multi;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

// 友元函数，运算符重载 *，用于时间乘以倍数
Time operator*(double multi, const Time &t) {
    Time result;
    long totalminutes = t.hours * multi * 60 + t.minutes * multi;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

// 友元函数，运算符重载 <<，用于输出时间
ostream &operator<<(ostream &os, const Time &t) {
    os << t.hours << " hours, " << t.minutes << " minutes." << endl;
    return os;
}