#ifndef __TEST04_HEAD_CHAPTER12_H__
#define __TEST04_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstring"
using namespace std;

typedef unsigned long Item; // 定义Item为unsigned long类型

class Stack {
private:
    static const int MAX = 10; // 栈的最大容量
    Item *m_pitems; // 动态数组，用于存储栈元素
    int m_size; // 栈的容量
    int m_top; // 栈顶指针

public:
    Stack(int n = MAX); // 带参数的构造函数
    Stack(const Stack &stack); // 复制构造函数
    ~Stack(); // 析构函数

    Stack &operator=(const Stack &stack); // 重载赋值运算符

    bool isEmpty() const; // 检查栈是否为空
    bool isFull() const; // 检查栈是否已满
    bool push(Item &item); // 压栈操作
    bool pop(Item &item); // 出栈操作
};

#endif //__TEST04_HEAD_CHAPTER12_H__