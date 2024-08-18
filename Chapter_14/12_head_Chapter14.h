#ifndef HEAD_12_CHAPTER10_H
#define HEAD_12_CHAPTER10_H

/*
 * Stack 类模板实现了一个固定大小的栈，包含基本的栈操作。
 */

template <class Type>
class Stack {
private:
    static const int MAX = 10;  // 栈的最大容量
    Type items[MAX];            // 存储栈中元素的数组
    int top;                    // 栈顶指针，表示栈中元素个数
public:
    Stack();                    // 构造函数，初始化栈顶指针
    bool isEmpty() const;       // 判断栈是否为空
    bool isFull() const;        // 判断栈是否已满
    bool push(Type &item);      // 将元素压入栈中
    bool pop(Type &item);       // 将栈顶元素弹出
};

template <class Type>
Stack<Type>::Stack() {
    top = 0;  // 初始化栈顶指针为 0，表示栈为空
}

template <class Type>
bool Stack<Type>::isEmpty() const {
    return top == 0;  // 栈顶指针为 0，表示栈为空
}

template <class Type>
bool Stack<Type>::isFull() const {
    return top == MAX;  // 栈顶指针等于最大容量，表示栈已满
}

template <class Type>
bool Stack<Type>::push(Type &item) {
    if (top < MAX) {  // 如果栈未满，压入元素
        items[top++] = item;  // 将元素存入数组，栈顶指针加 1
        return true;
    } else {
        return false;  // 栈已满，返回 false
    }
}

template <class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {  // 如果栈不为空，弹出元素
        item = items[--top];  // 获取栈顶元素，栈顶指针减 1
        return true;
    } else {
        return false;  // 栈为空，返回 false
    }
}

#endif // HEAD_12_CHAPTER10_H