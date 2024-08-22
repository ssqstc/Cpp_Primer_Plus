#ifndef HEAD_03_CHAPTER12_H
#define HEAD_03_CHAPTER12_H

#include "iostream"
using namespace std;

// 模板类 `Queue`，用于实现任意类型的队列
template <typename Item>
class Queue {
private:
    enum { Q_SIZE = 10 }; // 默认队列大小为10
    // 内嵌类 `Node`，表示队列中的节点
    class Node {
    public:
        Item m_item; // 节点保存的元素
        Node* m_next; // 指向下一个节点的指针
        Node(const Item& i) : m_item(i), m_next(nullptr) {} // 构造函数，初始化数据和指针
    };
    Node *m_front; // 队列头指针
    Node *m_rear;  // 队列尾指针
    int m_items;   // 队列中当前元素数量
    const int m_qsize; // 队列的最大容量
public:
    // 构造函数，初始化队列大小
    Queue(int a_qs = Q_SIZE);
    // 析构函数，释放所有节点的内存
    ~Queue();
    // 判断队列是否为空
    bool isEmpty() const;
    // 判断队列是否已满
    bool isFull() const;
    // 返回队列中元素的数量
    int queueCount() const;
    // 将元素加入队列（入队）
    bool enqueue(const Item &a_item);
    // 将元素从队列中移出（出队）
    bool dequeue(Item &a_item);
};

// 构造函数实现，初始化队列大小，并将头尾指针设为 `nullptr`
template <typename Item>
Queue<Item>::Queue(int a_qs) : m_qsize(a_qs) {
    m_front = m_rear = nullptr;
    m_items = 0;
}

// 析构函数实现，循环释放所有节点的内存
template <typename Item>
Queue<Item>::~Queue() {
    Node *temp;
    while (m_front != nullptr) {
        temp = m_front;
        m_front = m_front->m_next;
        delete temp;
    }
}

// 判断队列是否为空
template <typename Item>
bool Queue<Item>::isEmpty() const {
    return 0 == m_items;
}

// 判断队列是否已满
template <typename Item>
bool Queue<Item>::isFull() const {
    return m_items == m_qsize;
}

// 返回队列中的元素数量
template <typename Item>
int Queue<Item>::queueCount() const {
    return m_items;
}

// 将元素加入队列（入队）
// 如果队列已满，返回 false；否则，创建新节点并将其加入队列
template <typename Item>
bool Queue<Item>::enqueue(const Item &a_item) {
    if (isFull()) {
        return false;
    }
    Node *add = new Node(a_item); // 创建新节点
    m_items++; // 更新队列中的元素数量

    // 如果队列为空，设置新节点为队列头
    if (m_front == nullptr)
        m_front = add;
    else
        m_rear->m_next = add; // 否则将新节点加到队列尾部
    m_rear = add; // 更新队列尾指针
    return true;
}

// 将元素从队列中移出（出队）
// 如果队列为空，返回 false；否则，删除头节点并更新头指针
template <typename Item>
bool Queue<Item>::dequeue(Item &a_item) {
    if (isEmpty())
        return false;
    a_item = m_front->m_item; // 将队列头元素赋值给传入的变量
    m_items--; // 更新队列中的元素数量

    Node *temp = m_front; // 临时保存队列头节点
    m_front = m_front->m_next; // 更新队列头指针
    delete temp; // 删除原队列头节点

    if (isEmpty())
        m_rear = nullptr; // 如果队列为空，设置尾指针为 nullptr
    return true;
}

#endif //HEAD_03_CHAPTER12_H