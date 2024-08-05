#include "test04_head_Chapter12.h"

// 带参数的构造函数
Stack::Stack(int n) {
    m_pitems = new Item[n]; // 动态分配内存
    m_size = n; // 设置栈的容量
    m_top = 0; // 初始化栈顶指针
}

// 复制构造函数
Stack::Stack(const Stack &stack) {
    m_pitems = new Item[stack.m_size]; // 动态分配内存
    for (int i = 0; i < stack.m_size; ++i)
        m_pitems[i] = stack.m_pitems[i]; // 复制元素
    m_size = stack.m_size; // 复制栈的容量
    m_top = stack.m_top; // 复制栈顶指针
}

// 析构函数
Stack::~Stack() {
    delete[] m_pitems; // 释放动态分配的内存
}

// 检查栈是否为空
bool Stack::isEmpty() const {
    return m_top == 0; // 如果栈顶指针为0，表示栈为空
}

// 检查栈是否已满
bool Stack::isFull() const {
    return m_top == MAX; // 如果栈顶指针等于最大值，表示栈已满
}

// 压栈操作
bool Stack::push(Item &item) {
    if (m_top < MAX) { // 如果栈未满
        m_pitems[m_top++] = item; // 将元素压入栈中，栈顶指针加1
        return true; // 压栈成功
    } else {
        return false; // 栈已满，压栈失败
    }
}

// 出栈操作
bool Stack::pop(Item &item) {
    if (m_top > 0) { // 如果栈非空
        item = m_pitems[--m_top]; // 从栈顶弹出元素，栈顶指针减1
        return true; // 出栈成功
    } else {
        return false; // 栈为空，出栈失败
    }
}

// 重载赋值运算符
Stack& Stack::operator=(const Stack &stack) {
    if (this == &stack) // 检查自赋值
        return *this;
    delete[] m_pitems; // 释放原来的内存
    m_pitems = new Item[stack.m_size]; // 动态分配新内存
    for (int i = 0; i < stack.m_size; ++i) {
        m_pitems[i] = stack.m_pitems[i]; // 复制元素
    }
    m_size = stack.m_size; // 复制栈的容量
    m_top = stack.m_top; // 复制栈顶指针
    return *this; // 返回当前对象
}