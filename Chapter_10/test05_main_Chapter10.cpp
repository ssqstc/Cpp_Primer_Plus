#include "test05_head_Chapter10.h"

/*
 * 知识点总结：
 * - 栈的基本操作：实现了栈的入栈(push)和出栈(pop)操作。
 * - 结构体和类的结合：使用结构体customer来存储客户信息，并在栈类中使用。
 * - 静态常量成员：定义栈的大小为静态常量成员，方便管理和维护。
 * - 累加功能：在出栈操作中累加支付金额，展示累计总额。

 * 注意点：
 * - 输入检查：确保输入的数据有效，并处理可能的错误输入。
 * - 栈的边界检查：在入栈和出栈操作中检查栈是否满或空，避免越界操作。
 */

/*
 * 主函数：演示 Stack 类和 customer 结构体的使用
 * - 实现了基本的栈操作，包括入栈和出栈
 */
int main(){
    char ch; // 存储用户输入的操作字符
    customer cust{}; // 初始化客户结构体
    Stack st; // 创建 Stack 对象
    cout << "Please enter A to push to stack,\n" // 提示用户输入操作
            "P to pop from stack, Q to quit." << endl;
    while (cin >> ch && toupper(ch) != 'Q'){ // 循环读取用户输入，直到输入 'Q' 退出
        while (cin.get() != '\n'){} // 清除输入缓冲区
        switch (ch) {
            case 'A': // 如果用户输入 'A' 或 'a'
            case 'a':
                cout << "Enter a customer's fullname you want to push to stack:" << endl; // 提示输入客户姓名
                cin.getline(cust.fullname, 35); // 读取客户姓名
                cout << "Enter a customer payment: "; // 提示输入客户支付金额
                cin >> cust.payment; // 读取客户支付金额
                if (st.isfull()){ // 检查栈是否已满
                    cout << "Stack already full" << endl; // 如果已满，提示用户
                } else{
                    st.push(cust); // 否则，将客户信息入栈
                }
                break;
            case 'P': // 如果用户输入 'P' 或 'p'
            case 'p':
                if (st.isempty()){ // 检查栈是否为空
                    cout << "Stack is empty" << endl; // 如果为空，提示用户
                } else{
                    st.pop(cust); // 否则，将客户信息出栈
                    cout << cust.fullname << " is popped" << endl; // 输出出栈的客户姓名
                    cout << cust.payment << " is popped" << endl; // 输出出栈的客户支付金额
                }
                break;
        }
        cout << "Please enter A to push to stack,\n" // 提示用户输入操作
                "P to pop from stack, Q to quit." << endl;
    }
    return 0;
}
