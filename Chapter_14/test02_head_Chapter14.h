#ifndef TEST02_HEAD_CHAPTER14_H
#define TEST02_HEAD_CHAPTER14_H

#include <iostream>
#include <valarray>
using namespace std;

// 模板类 Pair 用于存储两个不同类型的对象
template <typename T1, typename T2>
class Pair {
private:
    T1 a; // 第一个对象
    T2 b; // 第二个对象
public:
    // 构造函数
    Pair(const T1& aVal, const T2& bVal) : a(aVal), b(bVal) {}
    // 获取第一个对象的引用
    T1& first() { return a; }
    // 获取第二个对象的引用
    T2& second() { return b; }
    // 获取第一个对象的常量引用
    T1 first() const { return a; }
    // 获取第二个对象的常量引用
    T2 second() const { return b; }
};

// Wine 类私有继承了模板类 Pair 和 string 类
class Wine : private Pair< valarray<int>, valarray<int> >, private string {
private:
    typedef valarray<int> ArrayInt;  // 使用 typedef 简化 valarray<int> 的定义
    typedef Pair<ArrayInt, ArrayInt> PariArray;  // 使用 typedef 简化 Pair<valarray<int>, valarray<int>> 的定义
public:
    // 默认构造函数，初始化 name 和 pariArray
    Wine() : string("default"), PariArray({1988, 1992, 1996},{24, 48, 144}) {}

    // 构造函数，接收字符指针、年份数量、年份数组和瓶子数组
    Wine(const char* l, int y, const int yr[], const int bot[]) : string(l), PariArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}

    // 构造函数，仅接收字符指针和年份数量
    Wine(const char* l, int y) : string(l), PariArray(ArrayInt(y), ArrayInt(y)) {}

    // 返回酒的名称（字符串）
    const string& label() const { return (const string&) *this; }

    // 获取每年的瓶子数量
    void getBottles();

    // 显示酒的信息
    void show() const;

    // 返回瓶子数量的总和
    int sum() const { return PariArray::second().sum(); }
};

// 获取年份和对应瓶子数量的函数实现
void Wine::getBottles() {
    int len = PariArray::first().size(); // 获取年份数组的大小
    for (int i = 0; i < len; ++i) {
        // 输入年份和对应的瓶子数量
        cout << "Enter " << (const string&)*this << " data for " << len << " year(s): " << endl;
        cout << "Enter year: ";
        cin >> PariArray::first()[i];
        cout << "Enter bottles for that year: ";
        cin >> PariArray::second()[i];
    }
}

// 显示酒的年份和瓶子数量
void Wine::show() const {
    int len = PariArray::first().size(); // 获取年份数组的大小
    cout << "Wine: " << (string&)*this << endl;
    cout << "\t\tYear\tBottles" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "\t\t" << PariArray::first()[i] << "\t" << PariArray::second()[i] << endl;
    }
}

#endif //TEST02_HEAD_CHAPTER14_H