#include "test04_head_Chapter12.h"

Stack::Stack(int n) {
    m_pitems = new Item [n];
    m_size = n;
    m_top = 0;
}

Stack::Stack(const Stack &stack) {
    m_pitems = new Item [stack.m_size];
    for (int i = 0; i < stack.m_size; ++i)
        m_pitems[i] = stack.m_pitems[i];
    m_size = stack.m_size;
    m_top = stack.m_top;
}

Stack::~Stack() {
    delete[] m_pitems;
}

bool Stack::isEmpty() const {
    return m_top == 0; // 如果栈顶指针为0，表示栈为空
}

/*
 * 检查栈是否已满
 * 返回值：如果栈已满，返回 true；否则返回 false
 */
bool Stack::isFull() const {
    return m_top == MAX; // 如果栈顶指针等于最大值，表示栈已满
}

/*
 * 压栈操作
 * item - 要压入栈的元素
 * 返回值：如果压栈成功，返回 true；如果栈已满，返回 false
 */
bool Stack::push(Item &item) {
    if (m_top < MAX){ // 如果栈未满
        m_pitems[m_top++] = item; // 将元素压入栈中，栈顶指针加1
        return true;
    } else{
        return false; // 栈已满，返回 false
    }
}

/*
 * 出栈操作
 * item - 用于存储出栈的元素
 * 返回值：如果出栈成功，返回 true；如果栈为空，返回 false
 */
bool Stack::pop(Item &item) {
    if (m_top > 0){ // 如果栈不为空
        item = m_pitems[--m_top]; // 将栈顶元素弹出，栈顶指针减1
        return true;
    } else{
        return false; // 栈为空，返回 false
    }
}

Stack& Stack::operator=(const Stack &stack) {
    if (this == &stack)
        return *this;
    delete[] m_pitems;
    m_pitems = new Item [stack.m_size];
    for (int i = 0; i < stack.m_size; ++i) {
        m_pitems[i] = stack.m_pitems[i];
    }
    m_size = stack.m_size;
    m_top = stack.m_top;
    return *this;
}