#include "test05_head_Chapter10.h"

using namespace std;

Stack::Stack() {
    top = 0.0; // 初始化栈顶指针
    total = 0.0; // 初始化支付总额
}

bool Stack::isempty() const {
    return top == 0; // 栈空条件
}

bool Stack::isfull() const {
    return top == SIZE; // 栈满条件
}

bool Stack::push(Item &item) {
    if (top < SIZE){ // 检查栈是否未满
        items[top++] = item; // 入栈操作
        return true;
    } else{
        return false;
    }
}

bool Stack::pop(Item &item) {
    if (top > 0){ // 检查栈是否不为空
        item = items[--top]; // 出栈操作
        total += item.payment; // 累加支付金额
        cout << "total = " << total << endl; // 输出累计总额
        return true;
    } else{
        return false;
    }
}