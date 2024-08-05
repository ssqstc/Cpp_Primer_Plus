#ifndef __04_HEAD_CHAPTER12_H__
#define __04_HEAD_CHAPTER12_H__

#include "iostream"
using namespace std;

class Customer {
private:
    long m_arrive;  // 客户到达时间
    int m_processTime;  // 客户处理时间
public:
    Customer() { m_arrive = m_processTime = 0; }  // 构造函数，初始化到达时间和处理时间
    void set(long a_when);  // 设置客户到达时间和处理时间
    long when() const { return m_arrive; }  // 返回客户到达时间
    int ptime() const { return m_processTime; }  // 返回客户处理时间
};

typedef Customer Item;  // 将 Customer 类定义为 Item

class Queue {
private:
    enum { Q_SIZE = 10 };  // 定义队列的默认大小
    struct Node { Item m_item; struct Node *m_next; };  // 定义节点结构
    Node *m_front;  // 队列前端
    Node *m_rear;  // 队列后端
    int m_items;  // 队列中的项数
    const int m_qsize;  // 队列的最大尺寸
public:
    Queue(int a_qs = Q_SIZE);  // 构造函数
    ~Queue();  // 析构函数
    bool isEmpty() const;  // 检查队列是否为空
    bool isFull() const;  // 检查队列是否已满
    int queueCount() const;  // 返回队列中的项数
    bool enqueue(const Item &a_item);  // 将项加入队列
    bool dequeue(Item &a_item);  // 将项从队列中移除
};

#endif //__04_HEAD_CHAPTER12_H__