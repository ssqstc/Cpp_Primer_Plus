#ifndef __TEST07_HEAD_CHAPTER10_H__
#define __TEST07_HEAD_CHAPTER10_H__
#include "string"
#include "iostream"
using namespace std;

class Plorg{
private:
    static const int SIZE = 20; // name 的最大长度
    char name[SIZE]{}; // Plorg 的名字
    int ci; // CI 值
public:
    Plorg(const char *n = "Plorga", int c = 50); // 构造函数，初始化 name 和 ci
    void set_ci(int c); // 设置 ci 的值
    void show() const; // 显示 name 和 ci
};

#endif //__TEST07_HEAD_CHAPTER10_H__