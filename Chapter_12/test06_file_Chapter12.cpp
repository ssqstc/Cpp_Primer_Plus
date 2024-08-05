#include "test06_head_Chapter12.h"

Queue::Queue(int a_qs) : m_qsize(a_qs) {
    m_front = m_rear = nullptr;
    m_items = 0;
}

Queue::~Queue() {
    Node* temp;
    while (m_front != nullptr) {
        temp = m_front;
        m_front = m_front->m_next;
        delete temp;
    }
}

bool Queue::isEmpty() const {
    return 0 == m_items;
}

bool Queue::isFull() const {
    return m_items == m_qsize;
}

int Queue::queueCount() const {
    return m_items;
}

bool Queue::enqueue(const Item& a_item) {
    if (isFull())
        return false;
    Node* add = new Node;
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

bool Queue::dequeue(Item& a_item) {
    if (isEmpty())
        return false;
    a_item = m_front->m_item;
    m_items--;

    Node* temp = m_front;
    m_front = m_front->m_next;
    delete temp;

    if (isEmpty())
        m_rear = nullptr;
    return true;
}

void Customer::set(long when) {
    m_arrive = when;
    m_processTime = rand() % 3 + 1;
}