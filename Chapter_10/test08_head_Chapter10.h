#ifndef __TEST08_HEAD_CHAPTER10_H__
#define __TEST08_HEAD_CHAPTER10_H__
#include "iostream"
using namespace std;

typedef unsigned long Item; // 定义 Item 类型为 unsigned long

void visit_item(Item &item); // 函数声明：访问列表元素

class List{
private:
    enum {MAX = 10}; // 列表的最大容量
    Item m_item[MAX]{}; // 列表存储的元素数组
    int m_top; // 列表中当前元素的数量
public:
    List(); // 构造函数
    bool isempty() const; // 判断列表是否为空
    bool isfull() const; // 判断列表是否已满
    bool add(const Item &item); // 添加元素到列表
    void visit(void (*pf)(Item &)); // 使用函数指针访问列表中的元素
};

#endif //__TEST08_HEAD_CHAPTER10_H__