#include "iostream"
#include "04_head_Chapter10.h"
#include "cctype"
using namespace std;

/*
 * 知识点总结：
 * - 使用类封装数据和操作：Stack 类封装了栈的基本操作。
 * - 静态成员常量：用于定义类的常量成员（栈的最大容量）。
 * - 构造函数：用于初始化对象（栈顶指针）。
 * - const 成员函数：用于不修改对象状态的成员函数。
 * - 模板函数：用于实现通用的栈操作（压栈、出栈）。
 *
 * 注意点：
 * - 确保数据有效性：在压栈和出栈操作中进行边界检查。
 * - 使用静态成员常量代替魔法数字：提高代码的可读性和维护性。
 * - const 成员函数的使用：保证函数不会修改对象的状态。
 * - 清除输入缓冲区：避免输入错误影响后续操作。
 */

/*
 * 主函数：演示 Stack 类的使用
 * - 提示用户输入操作
 * - 根据用户输入进行对应操作（压栈、出栈、退出）
 */
int main(){
    char ch;
    unsigned long po;
    Stack st;
    cout << "Please enter A to push to stack,\n"
            "P to pop from stack, Q to quit." << endl; // 提示用户输入A进行压栈，P进行出栈，Q退出程序
    while (cin >> ch && toupper(ch) != 'Q'){ // 获取用户输入的字符并转换为大写字母，判断是否为Q
        while (cin.get() != '\n'){} // 清除输入缓冲区中的多余字符及换行符
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a number you want to push to stack:" << endl; // 提示用户输入要压入栈的数字
                cin >> po;
                if (st.isfull()){ // 判断栈是否已满
                    cout << "Stack already full" << endl; // 栈已满，输出提示信息
                } else{
                    st.push(po); // 栈未满，执行压栈操作
                }
                break;
            case 'P':
            case 'p':
                if (st.isempty()){ // 判断栈是否为空
                    cout << "Stack is empty" << endl; // 栈为空，输出提示信息
                } else{
                    st.pop(po); // 栈不为空，执行出栈操作
                    cout << po << " is popped" << endl; // 输出出栈的元素
                }
                break;
        }
        cout << "Please enter A to push to stack,\n"
                "P to pop from stack, Q to quit." << endl; // 提示用户输入A进行压栈，P进行出栈，Q退出程序
    }
    return 0;
}
