#include "test08_head_Chapter10.h"

/*
 * 构造函数：初始化 m_top
 */
List::List() {
    m_top = 0; // 初始化 m_top 为 0
}

/*
 * 判断列表是否为空
 */
bool List::isempty() const {
    return m_top == 0; // 如果 m_top 为 0，则列表为空
}

/*
 * 判断列表是否已满
 */
bool List::isfull() const {
    return m_top == MAX; // 如果 m_top 等于 MAX，则列表已满
}

/*
 * 添加元素到列表
 */
bool List::add(const Item &item) {
    if (m_top < MAX){ // 如果列表未满
        m_item[m_top++] = item; // 将元素添加到列表中
        return true; // 返回 true 表示添加成功
    } else
        return false; // 返回 false 表示添加失败
}

/*
 * 使用函数指针访问列表中的元素
 */
void List::visit(void (*pf)(Item &)){
    for (int i = 0; i < m_top; ++i) { // 遍历列表中的元素
        pf(m_item[i]); // 使用函数指针访问元素
    }
}

/*
 * 访问列表元素的函数
 */
void visit_item(Item &item){
    cout << "Item = " << item << endl; // 输出元素的值
}