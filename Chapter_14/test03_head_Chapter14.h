#ifndef TEST03_MAIN_CHAPTER14_H
#define TEST03_MAIN_CHAPTER14_H

#include "iostream"
#include "string"
using namespace std;

// Worker 类表示一个工人，有姓名和ID属性
class Worker {
private:
    string fullName; // 工人的全名
    long id;         // 工人的ID
public:
    // 构造函数
    Worker() : fullName("none one"), id(0) {}
    Worker(const string& s, long n) : fullName(s), id(n) {}
    ~Worker() {}

    // 设置工人的姓名和ID
    void set();

    // 显示工人的姓名和ID
    void show() const;
};

// 设置工人的姓名和ID
void Worker::set() {
    cout << "Enter worker's fullname: ";
    getline(cin, fullName);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n'); // 清除输入缓冲区中的换行符
}

// 显示工人的姓名和ID
void Worker::show() const {
    cout << "Name: " << fullName << endl;
    cout << "Employee ID: " << id << endl;
}

// Queue 模板类，表示一个通用的队列
template <typename T>
class Queue {
private:
    enum { Q_SIZE = 10 };  // 默认队列大小
    struct Node {          // 链表节点
        T m_item;          // 存储的元素
        struct Node *m_next; // 指向下一个节点的指针
    };
    Node *m_front;         // 指向队列前端的指针
    Node *m_rear;          // 指向队列尾端的指针
    int m_items;           // 当前队列中的元素数量
    const int m_qsize;     // 队列的最大容量
public:
    Queue(int a_qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;    // 判断队列是否为空
    bool isFull() const;     // 判断队列是否已满
    int queueCount() const;  // 返回队列中元素的数量
    bool enqueue(const T &a_item); // 入队操作
    bool dequeue(T &a_item);       // 出队操作
};

// 构造函数
template <typename T>
Queue<T>::Queue(int a_qs) : m_qsize(a_qs) {
    m_front = m_rear = nullptr;
    m_items = 0;
}

// 析构函数
template <typename T>
Queue<T>::~Queue() {
    Node *temp;
    while (m_front != nullptr) { // 循环删除队列中的每个节点
        temp = m_front;
        m_front = m_front->m_next;
        delete temp;
    }
}

// 判断队列是否为空
template <typename T>
bool Queue<T>::isEmpty() const {
    return 0 == m_items;
}

// 判断队列是否已满
template <typename T>
bool Queue<T>::isFull() const {
    return m_items == m_qsize;
}

// 返回队列中的元素数量
template <typename T>
int Queue<T>::queueCount() const {
    return m_items;
}

// 入队操作
template <typename T>
bool Queue<T>::enqueue(const T &a_item) {
    if (isFull())  // 如果队列已满，入队失败
        return false;
    Node *add = new Node;  // 创建新节点
    add->m_item = a_item;  // 将元素存储到节点中
    add->m_next = nullptr; // 新节点的下一个指针为空
    m_items++;             // 队列元素数量加一

    if (m_front == nullptr) // 如果队列为空，更新队列的前端指针
        m_front = add;
    else
        m_rear->m_next = add; // 如果队列非空，将新节点加入队列尾端
    m_rear = add;             // 更新队列的尾端指针
    return true;
}

// 出队操作
template <typename T>
bool Queue<T>::dequeue(T &a_item) {
    if (isEmpty())  // 如果队列为空，出队失败
        return false;
    a_item = m_front->m_item; // 取出队列前端的元素
    m_items--;                // 队列元素数量减一

    Node *temp = m_front;     // 临时存储当前的前端节点
    m_front = m_front->m_next;// 更新前端指针
    delete temp;              // 删除前端节点

    if (isEmpty())  // 如果队列为空，更新队列的尾端指针
        m_rear = nullptr;
    return true;
}

#endif //TEST03_MAIN_CHAPTER14_H