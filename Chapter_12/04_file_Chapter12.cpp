#include "04_head_Chapter12.h"
#include "cstdlib"

// 构造函数，初始化队列
Queue::Queue(int a_qs) : m_qsize(a_qs) {
    m_front = m_rear = nullptr;
    m_items = 0;
}

// 析构函数，删除队列中的所有节点
Queue::~Queue() {
    Node *temp;
    while (m_front != nullptr) {
        temp = m_front;
        m_front = m_front->m_next;
        delete temp;
    }
}

// 检查队列是否为空
bool Queue::isEmpty() const {
    return 0 == m_items;
}

// 检查队列是否已满
bool Queue::isFull() const {
    return m_items == m_qsize;
}

// 返回队列中的项数
int Queue::queueCount() const {
    return m_items;
}

// 将项加入队列
bool Queue::enqueue(const Item &a_item) {
    if (isFull())
        return false;
    Node *add = new Node;
    add->m_item = a_item;
    add->m_next = nullptr;
    m_items++;

    if (m_front == nullptr)
        m_front = add;
    else
        m_rear->m_next = add;
    m_rear = add;
    return true;
}

// 将项从队列中移除
bool Queue::dequeue(Item &a_item) {
    if (isEmpty())
        return false;
    a_item = m_front->m_item;
    m_items--;

    Node *temp = m_front;
    m_front = m_front->m_next;
    delete temp;

    if (isEmpty())
        m_rear = nullptr;
    return true;
}

// 设置客户到达时间和处理时间
void Customer::set(long a_when) {
    m_arrive = a_when;
    m_processTime = rand() % 3 + 1;
}