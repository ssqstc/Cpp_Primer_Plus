#ifndef __TEST04_HEAD_CHAPTER12_H__
#define __TEST04_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstring"
using namespace std;

typedef unsigned long Item;

class Stack {
private:
    static const int MAX = 10;
    Item *m_pitems;
    int m_size;
    int m_top;
public:
    Stack(int n = MAX);
    Stack(const Stack &stack);
    ~Stack();

    Stack &operator=(const Stack &stack);

    bool isEmpty() const; // 检查栈是否为空
    bool isFull() const; // 检查栈是否已满
    bool push(Item &item); // 压栈操作
    bool pop(Item &item); // 出栈操作
};


#endif //__TEST04_HEAD_CHAPTER12_H__
