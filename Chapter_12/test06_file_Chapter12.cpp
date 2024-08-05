#include "test06_head_Chapter12.h"

// 队列的构造函数
Queue::Queue(int a_qsize) : m_qsize(a_qsize) {
    m_front = m_rear = nullptr; // 初始化队列为空
    m_items = 0; // 初始化队列中的元素数量为0
}

// 队列的析构函数
Queue::~Queue() {
    Node* temp;
    while (m_front != nullptr) { // 循环释放所有节点
        temp = m_front;
        m_front = m_front->m_next;
        delete temp;
    }
}

// 检查队列是否为空
bool Queue::isEmpty() const {
    return 0 == m_items; // 如果队列中的元素数量为0，则队列为空
}

// 检查队列是否已满
bool Queue::isFull() const {
    return m_items == m_qsize; // 如果队列中的元素数量等于队列的容量，则队列已满
}

// 获取队列中的元素数量
int Queue::queueCount() const {
    return m_items;
}

// 入队操作
bool Queue::enqueue(const Item& a_item) {
    if (isFull()) // 如果队列已满，返回false
        return false;
    Node* add = new Node; // 创建新节点
    add->m_item = a_item; // 设置节点的值
    add->m_next = nullptr;
    m_items++; // 增加队列中的元素数量

    if (m_front == nullptr) // 如果队列为空
        m_front = add; // 将新节点设置为队列的第一个节点
    else
        m_rear->m_next = add; // 否则，将新节点添加到队列的末尾
    m_rear = add; // 更新队列的尾节点
    return true;
}

// 出队操作
bool Queue::dequeue(Item& a_item) {
    if (isEmpty()) // 如果队列为空，返回false
        return false;
    a_item = m_front->m_item; // 获取队列的第一个元素
    m_items--; // 减少队列中的元素数量

    Node* temp = m_front; // 删除队列的第一个节点
    m_front = m_front->m_next;
    delete temp;

    if (isEmpty()) // 如果队列为空
        m_rear = nullptr; // 将尾节点设置为空
    return true;
}

// 设置客户的到达时间和处理时间
void Customer::set(long when) {
    m_arrive = when; // 设置到达时间
    m_processTime = rand() % 3 + 1; // 设置随机的处理时间（1到3分钟）
}
