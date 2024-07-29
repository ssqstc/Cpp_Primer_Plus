#include "test04_head_Chapter11.h"


Time::Time() {
    hours = minutes = 0;  // 默认构造函数初始化为0
}

Time::Time(int h, int m) {
    hours = h;  // 初始化小时
    minutes = m;  // 初始化分钟
}

void Time::AddMin(int m) {
    minutes += m;  // 增加分钟数
    hours += minutes / 60;  // 处理分钟进位到小时
    minutes %= 60;  // 保留分钟数
}

void Time::AddHr(int h) {
    hours += h;  // 增加小时数
}

void Time::Reset(int h, int m) {
    hours = h;  // 重置小时数
    minutes = m;  // 重置分钟数
}

Time operator+(const Time &s, const Time &t) {
    Time sum;
    sum.minutes = s.minutes + t.minutes;  // 计算总分钟数
    sum.hours = s.hours + t.hours + sum.minutes / 60;  // 计算总小时数，并处理进位
    sum.minutes %= 60;  // 保留分钟数
    return sum;
}

Time operator-(const Time &s, const Time &t) {
    Time diff;
    int tot1, tot2;
    tot1 = s.hours * 60 + s.minutes;  // 将s时间转换为总分钟数
    tot2 = t.hours * 60 + t.minutes;  // 将t时间转换为总分钟数
    diff.hours = (tot1 - tot2) / 60;  // 计算小时差
    diff.minutes = (tot1 - tot2) % 60;  // 计算分钟差
    return diff;
}

Time operator*(const Time &t, double multi) {
    Time result;
    long totalminutes = t.hours * multi * 60 + t.minutes * multi;  // 计算乘积后的总分钟数
    result.hours = totalminutes / 60;  // 转换为小时
    result.minutes = totalminutes % 60;  // 保留分钟数
    return result;
}

Time operator*(double multi, const Time &t) {
    return t * multi;  // 调用前一个乘法运算符重载
}

ostream &operator<<(std::ostream &os, const Time &t) {
    os << t.hours << " hours, " << t.minutes << " minutes." << endl;  // 输出时间
    return os;
}