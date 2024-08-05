#ifndef __TEST06_HEAD_CHAPTER12_H__
#define __TEST06_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;

class Customer {
private:
    long m_arrive;
    int m_processTime;
public:
    Customer() { m_arrive = m_processTime = 0; }
    void set(long when);
    long when() const { return m_arrive; }
    int ptime() const { return m_processTime; }
};

typedef Customer Item;

class Queue {
private:
    enum { Q_SIZE = 10 };
    struct Node { Item m_item; struct Node* m_next; };
    Node* m_front;
    Node* m_rear;
    int m_items;
    const int m_qsize;
    Queue(const Queue &queue) : m_qsize(0) {}
    Queue& operator=(const Queue& q) { return* this; }
public:
    Queue(int a_qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    bool enqueue(const Item& a_item);
    bool dequeue(Item& a_item);
};


#endif //__TEST06_HEAD_CHAPTER12_H__
