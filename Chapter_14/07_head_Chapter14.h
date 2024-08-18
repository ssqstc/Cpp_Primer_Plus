#ifndef HEAD_07_CHAPTER14_H
#define HEAD_07_CHAPTER14_H

template <class Type>
class Stack {
private:
    static const int MAX = 10; // 栈的最大容量
    Type items[MAX]; // 存储栈元素的数组
    int top; // 栈顶指针
public:
    Stack(); // 构造函数，初始化栈
    bool isEmpty() const; // 判断栈是否为空
    bool isFull() const; // 判断栈是否已满
    bool push(Type &item); // 将元素压入栈
    bool pop(Type &item); // 将元素弹出栈
};

template <class Type>
Stack<Type>::Stack() {
    top = 0; // 初始化栈顶指针为0，表示栈为空
}

template <class Type>
bool Stack<Type>::isEmpty() const {
    return top == 0; // 如果栈顶指针为0，表示栈为空
}

template <class Type>
bool Stack<Type>::isFull() const {
    return top == MAX; // 如果栈顶指针等于最大值，表示栈已满
}

template <class Type>
bool Stack<Type>::push(Type &item) {
    if (top < MAX) { // 如果栈未满
        items[top++] = item; // 将元素压入栈中，栈顶指针加1
        return true; // 压栈成功
    } else {
        return false; // 栈已满，压栈失败
    }
}

template <class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) { // 如果栈不为空
        item = items[--top]; // 将栈顶元素弹出，栈顶指针减1
        return true; // 出栈成功
    } else {
        return false; // 栈为空，出栈失败
    }
}

#endif // HEAD_07_CHAPTER14_H