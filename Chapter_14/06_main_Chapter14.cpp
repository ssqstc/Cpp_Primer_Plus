#include "iostream"
#include "06_head_Chapter14.h"
#include "cctype"
using namespace std;
/*
 * 知识点总结：
 * 1. **模板类（Template Class）**：`Stack` 类使用了模板技术，使其可以处理任意类型的数据。模板类允许在编写时不指定具体的数据类型，而是在使用时传入具体类型，从而实现代码的复用。
 * 2. **栈的基本操作**：`Stack` 类实现了栈的常见操作，如判断栈是否为空 (`isEmpty`)、是否已满 (`isFull`)、压栈 (`push`) 和出栈 (`pop`)。这些操作是栈结构的核心操作。
 * 3. **静态成员（Static Member）**：`MAX` 是一个静态常量，定义了栈的最大容量。静态成员在类的所有实例中共享，相同的栈大小限制适用于每个 `Stack` 对象。
 * 4. **栈顶指针（Top Pointer）**：`top` 变量用于指示栈顶的位置。初始值为 `0`，表示栈为空；每次压栈时 `top` 递增，每次出栈时 `top` 递减。
 * 5. **字符处理（Character Handling）**：`toupper` 函数将字符转换为大写字母，用于处理用户输入，并清除输入缓冲区中的多余字符。

 * 注意点：
 * 1. **模板使用中的数据类型一致性**：在使用模板类时，需要确保传递给模板的数据类型是一致的，以防止类型不匹配导致的编译错误。
 * 2. **边界检查（Boundary Check）**：在 `push` 和 `pop` 操作时，需要进行边界检查，以防止栈溢出或在空栈上执行出栈操作。这是确保栈操作安全性的关键步骤。
 * 3. **静态成员的初始化**：静态成员 `MAX` 是在类声明中定义的常量，在整个类的生命周期中保持不变。注意静态成员的作用范围和生命周期。
 * 4. **输入处理和缓冲区清理**：在读取用户输入时，使用 `cin.get()` 清理输入缓冲区中的多余字符，确保输入的准确性，防止多余字符干扰后续输入操作。
 */
int main() {
    char ch;
    string po;
    Stack<string> st;

    // 提示用户进行操作选择
    cout << "Please enter A to push to stack,\n"
            "P to pop from stack, Q to quit." << endl;

    // 读取用户输入，并判断是否选择退出
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {} // 清除输入缓冲区中的多余字符

        // 根据用户输入的操作进行相应的处理
        switch (ch) {
            case 'A': // 用户选择压栈
            case 'a':
                cout << "Enter a string you want to push to stack:" << endl;
                cin >> po; // 获取用户输入的字符串
                if (st.isFull()) { // 判断栈是否已满
                    cout << "Stack already full" << endl; // 栈已满，输出提示信息
                } else {
                    st.push(po); // 栈未满，执行压栈操作
                }
                break;
            case 'P': // 用户选择出栈
            case 'p':
                if (st.isEmpty()) { // 判断栈是否为空
                    cout << "Stack is empty" << endl; // 栈为空，输出提示信息
                } else {
                    st.pop(po); // 栈不为空，执行出栈操作
                    cout << po << " is popped" << endl; // 输出出栈的元素
                }
                break;
        }

        // 继续提示用户进行操作选择
        cout << "Please enter A to push to stack,\n"
                "P to pop from stack, Q to quit." << endl;
    }

    return 0;
}