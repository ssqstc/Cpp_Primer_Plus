#ifndef __TEST06_HEAD_CHAPTER12_H__
#define __TEST06_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;

class Customer {
private:
    long m_arrive; // 到达时间
    int m_processTime; // 处理时间
public:
    Customer() { m_arrive = m_processTime = 0; }
    void set(long when); // 设置到达时间和处理时间
    long when() const { return m_arrive; } // 获取到达时间
    int ptime() const { return m_processTime; } // 获取处理时间
};

typedef Customer Item; // 将Customer类型定义为Item

class Queue {
private:
    enum { Q_SIZE = 10 }; // 队列的默认容量
    struct Node { Item m_item; struct Node* m_next; }; // 队列的节点结构
    Node* m_front; // 队列的头节点
    Node* m_rear; // 队列的尾节点
    int m_items; // 队列中的元素数量
    const int m_qsize; // 队列的容量
    Queue(const Queue &queue) : m_qsize(0) {} // 禁止复制构造函数
    Queue& operator=(const Queue& q) { return *this; } // 禁止赋值运算符
public:
    Queue(int a_qsize = Q_SIZE); // 队列的构造函数
    ~Queue(); // 队列的析构函数
    bool isEmpty() const; // 检查队列是否为空
    bool isFull() const; // 检查队列是否已满
    int queueCount() const; // 获取队列中的元素数量
    bool enqueue(const Item& a_item); // 入队操作
    bool dequeue(Item& a_item);
};

#endif //__TEST06_HEAD_CHAPTER12_H__
