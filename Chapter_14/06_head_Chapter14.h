#ifndef HEAD_06_CHAPTER14_H
#define HEAD_06_CHAPTER14_H

/*
 * 知识点总结：
 * 1. 模板类：`Stack` 类使用了模板技术，使其可以处理任意类型的数据。
 * 2. 栈的基本操作：实现了栈的常见操作，如判断是否为空、是否已满、压栈和出栈。
 * 3. 静态成员：`MAX` 是一个静态常量，定义了栈的最大容量。

 * 注意点：
 * 1. 确保栈的容量（`MAX`）合理设置，避免栈溢出或空间浪费。
 * 2. 栈操作的边界检查：在 `push` 和 `pop` 操作时需要进行边界检查，以防止栈溢出或在空栈上执行出栈操作。
 */

template <class Type>
class Stack {
private:
    static const int MAX = 10; // 栈的最大容量
    Type items[MAX];           // 栈的存储数组
    int top;                   // 栈顶指针，指示栈顶位置
public:
    Stack();                   // 构造函数，初始化栈
    bool isEmpty() const;      // 判断栈是否为空
    bool isFull() const;       // 判断栈是否已满
    bool push(Type &item);     // 压栈操作
    bool pop(Type &item);      // 出栈操作
};

template <class Type>
Stack<Type>::Stack() {
    top = 0; // 栈顶指针初始化为0，表示栈为空
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
        return true;
    } else {
        return false; // 栈已满，返回 false
    }
}

template <class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) { // 如果栈不为空
        item = items[--top]; // 将栈顶元素弹出，栈顶指针减1
        return true;
    } else {
        return false; // 栈为空，返回 false
    }
}

#endif //HEAD_06_CHAPTER14_H