#include "04_head_Chapter10.h"

/*
 * Stack 类的构造函数
 * 初始化栈顶指针
 */
Stack::Stack() {
    top = 0;
}

/*
 * 检查栈是否为空
 * 返回值：如果栈为空，返回 true；否则返回 false
 */
bool Stack::isempty() const {
    return top == 0; // 如果栈顶指针为0，表示栈为空
}

/*
 * 检查栈是否已满
 * 返回值：如果栈已满，返回 true；否则返回 false
 */
bool Stack::isfull() const {
    return top == MAX; // 如果栈顶指针等于最大值，表示栈已满
}

/*
 * 压栈操作
 * item - 要压入栈的元素
 * 返回值：如果压栈成功，返回 true；如果栈已满，返回 false
 */
bool Stack::push(Item &item) {
    if (top < MAX){ // 如果栈未满
        items[top++] = item; // 将元素压入栈中，栈顶指针加1
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
    if (top > 0){ // 如果栈不为空
        item = items[--top]; // 将栈顶元素弹出，栈顶指针减1
        return true;
    } else{
        return false; // 栈为空，返回 false
    }
}