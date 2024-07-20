#ifndef __04_HEAD_CHAPTER10_H__
#define __04_HEAD_CHAPTER10_H__

typedef unsigned long Item; // 定义 Item 类型为 unsigned long

/*
 * Stack 类定义
 * 模拟栈的基本操作：压栈、出栈、检查是否为空、检查是否已满
 */
class Stack{
private:
    static const int MAX = 10; // 栈的最大容量
    Item items[MAX]; // 存储栈元素的数组
    int top; // 栈顶指针
public:
    Stack(); // 构造函数
    bool isempty() const; // 检查栈是否为空
    bool isfull() const; // 检查栈是否已满
    bool push(Item &item); // 压栈操作
    bool pop(Item &item); // 出栈操作
};

#endif //__04_HEAD_CHAPTER10_H__