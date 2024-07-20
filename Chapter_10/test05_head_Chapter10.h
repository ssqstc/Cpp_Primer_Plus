#ifndef __TEST05_HEAD_CHAPTER10_H__
#define __TEST05_HEAD_CHAPTER10_H__
#include "iostream"
using namespace std;

struct customer{
    char fullname[35]; // 客户全名
    double payment; // 客户支付金额
};
typedef customer Item; // 将 customer 类型定义为 Item

class Stack{
private:
    static const int SIZE = 10; // 栈的大小
    double total; // 累计支付总额
    int top; // 栈顶指针
    Item items[SIZE]; // 栈数组
public:
    Stack(); // 构造函数
    bool isempty() const; // 检查栈是否为空
    bool isfull() const; // 检查栈是否已满
    bool push(Item &item); // 入栈操作
    bool pop(Item &item); // 出栈操作
};

#endif //__TEST05_HEAD_CHAPTER10_H__