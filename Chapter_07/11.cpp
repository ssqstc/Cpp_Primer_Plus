#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 结构体：定义和使用结构体存储相关数据。
 * 2. 函数：定义和调用函数实现特定功能。
 * 3. 运算符：使用算术运算符进行时间计算。
 *
 * 注意点：
 * 1. 时间换算：注意分钟到小时的换算及取余操作。
 * 2. 结构体传递：函数参数和返回值为结构体时，注意数据的完整传递。
 * 3. 初始值：确保结构体的成员变量初始化，避免未定义行为。
 */

struct travel_time{
    int hours; // 小时
    int mins;  // 分钟
};

const int Mins_per_hour = 60; // 每小时的分钟数

travel_time sum(travel_time t1, travel_time t2); // 计算时间总和的函数声明
void show_time(travel_time t); // 显示时间的函数声明

int main(){
    travel_time day1 = {5, 45}; // 第一天的时间
    travel_time day2 = {4, 55}; // 第二天的时间

    travel_time trip = sum(day1, day2); // 计算前两天的总时间
    cout << "Two days total:" << endl; // 两天的总时间
    show_time(trip); // 显示总时间

    travel_time day3 = {4, 32}; // 第三天的时间
    cout << "Three days total:" << endl; // 三天的总时间
    show_time(sum(trip, day3)); // 显示三天的总时间
    return 0;
}

travel_time sum(travel_time t1, travel_time t2){ // 计算时间总和的函数定义
    travel_time total{};
    total.mins = (t1.mins + t2.mins) % Mins_per_hour; // 计算总分钟并取余
    total.hours = (t1.mins + t2.mins) / Mins_per_hour + t1.hours + t2.hours; // 计算总小时
    return total; // 返回总时间
}

void show_time(travel_time t){ // 显示时间的函数定义
    cout << "Hours = " << t.hours << " , Minutes = " << t.mins << endl; // 输出时间
}
