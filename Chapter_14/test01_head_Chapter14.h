#ifndef TEST01_HEAD_CHAPTER14_H
#define TEST01_HEAD_CHAPTER14_H

#include <iostream>
#include <cstring>
#include <valarray>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 a; // 用于存储年份的 valarray
    T2 b; // 用于存储瓶数的 valarray
public:
    // 构造函数，初始化年份和瓶数
    Pair(const T1& aVal, const T2& bVal) : a(aVal), b(bVal) {}
    // 获取年份的引用
    T1& first() { return a; }
    // 获取瓶数的引用
    T2& second() { return b; }
    // 获取年份的常量引用
    T1 first() const { return a; }
    // 获取瓶数的常量引用
    T2 second() const { return b; }
};

class Wine {
private:
    typedef valarray<int> ArrayInt; // 定义 `valarray<int>` 的别名
    typedef Pair<ArrayInt, ArrayInt> PariArray; // 定义 `Pair<ArrayInt, ArrayInt>` 的别名
    string name; // 葡萄酒名称
    PariArray pariArray; // 用于存储年份和瓶数的 `Pair` 对象
public:
    // 默认构造函数，初始化名称和年份瓶数数据
    Wine() : name("default"), pariArray({1988, 1992, 1996},{24, 48, 144}) {}
    // 初始化名称、年份、年份数组和瓶数数组
    Wine(const char* l, int y, const int yr[], const int bot[]) : name(l), pariArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}
    // 初始化名称和年份，年份和瓶数数组空置
    Wine(const char* l, int y) : name(l), pariArray(ArrayInt(y), ArrayInt(y)) {}
    // 获取葡萄酒名称
    const string& label() const { return name; }
    // 从用户输入获取年份和瓶数
    void getBottles();
    // 显示葡萄酒的名称、年份和瓶数
    void show() const;
    // 计算总瓶数
    int sum() const { return pariArray.second().sum(); }
};

void Wine::getBottles() {
    int len = pariArray.first().size(); // 获取年份数组的大小
    for (int i = 0; i < len; ++i) {
        cout << "Enter " << name << " data for " << len << " year(s): " << endl;
        cout << "Enter year: ";
        cin >> pariArray.first()[i]; // 获取每一年的年份
        cout << "Enter bottles for that year: ";
        cin >> pariArray.second()[i]; // 获取对应年份的瓶数
    }
}

void Wine::show() const {
    int len = pariArray.first().size(); // 获取年份数组的大小
    cout << "Wine: " << name << endl;
    cout << "\t\tYear\tBottles" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "\t\t" << pariArray.first()[i] << "\t" << pariArray.second()[i] << endl; // 显示年份和瓶数
    }
}

#endif //TEST01_HEAD_CHAPTER14_H