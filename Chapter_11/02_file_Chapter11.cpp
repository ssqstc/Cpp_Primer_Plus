#include "02_head_Chapter11.h"

/*
 * Time 类的默认构造函数
 * 初始化小时和分钟为0
 */
Time::Time() {
    hours = minutes = 0;
}

/*
 * Time 类的构造函数
 * 初始化小时和分钟
 * h - 小时
 * m - 分钟
 */
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

/*
 * 添加分钟
 * m - 要添加的分钟数
 */
void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

/*
 * 添加小时
 * h - 要添加的小时数
 */
void Time::AddHr(int h) {
    hours += h;
}

/*
 * 重置时间
 * h - 小时
 * m - 分钟
 */
void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

/*
 * 重载+运算符
 * t - Time 对象
 * 返回两个 Time 对象的和
 */
Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = t.minutes + this->minutes;
    sum.hours = t.hours + this->hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

/*
 * 重载-运算符
 * t - Time 对象
 * 返回两个 Time 对象的差
 */
Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1, tot2;
    tot1 = this->hours * 60 + this->minutes;
    tot2 = t.hours * 60 + t.minutes;
    diff.hours = (tot1 - tot2) / 60;
    diff.minutes = (tot1 - tot2) % 60;
    return diff;
}

/*
 * 重载*运算符
 * multi - 乘数
 * 返回 Time 对象乘以一个系数后的结果
 */
Time Time::operator*(const double multi) const {
    Time result;
    long totalminutes = hours * multi * 60 + minutes * multi;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

/*
 * 友元函数，重载*运算符
 * multi - 乘数
 * t - Time 对象
 * 返回 Time 对象乘以一个系数后的结果
 */
Time operator*(const double multi, const Time &t){
    Time result;
    long totalminutes = t.hours * multi * 60 + t.minutes * multi;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

/*
 * 显示时间
 */
void Time::show() const {
    cout << hours << " hours, " << minutes << " minutes." << endl; // 输出时间
}