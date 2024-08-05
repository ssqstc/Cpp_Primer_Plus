#include "test04_head_Chapter12.h"

/*
知识点总结:
1. **构造函数和析构函数**: 包括带参数的构造函数、复制构造函数和析构函数。
2. **运算符重载**: 重载赋值运算符以便进行深拷贝。
3. **成员函数**: 包括栈的基本操作，如压栈、出栈、检查是否为空和是否已满。
4. **动态内存管理**: 使用动态分配和释放内存来处理栈中的元素。

注意点:
1. **内存管理**: 确保动态分配的内存在析构函数中被正确释放，避免内存泄漏。
2. **深拷贝**: 在复制构造函数和赋值运算符中进行深拷贝，避免共享指针导致的问题。
3. **边界检查**: 在压栈和出栈操作时进行边界检查，防止非法操作。
*/

const int MAX = 5; // 栈的最大容量
int main() {
    Stack stack(MAX); // 创建一个栈对象，容量为MAX
    Item item; // 声明一个Item对象

    for (int i = 0; i < MAX; ++i) {
        cout << "Enter a number you want to push to stack: " << endl; // 提示用户输入要压入栈的数字
        cin >> item; // 读取用户输入
        while (cin.get() != '\n'); // 清除输入缓冲区中的换行符
        stack.push(item); // 将数字压入栈
    }

    Stack stack_new(stack); // 使用复制构造函数创建一个新的栈对象
    for (int i = 0; i < MAX; ++i) {
        stack_new.pop(item); // 从新栈中弹出元素
        cout << item << " is poped." << endl; // 输出弹出的元素
    }

    return 0;
}