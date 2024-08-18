#include "05_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. 抽象基类：`Worker` 类是一个抽象基类，包含纯虚函数 `set()` 和 `show()`，强制派生类实现这些函数。
 * 2. 多态性：通过基类指针 `Worker*` 操作派生类对象，实现了运行时的多态。
 * 3. 虚基类与多重继承：`Waiter` 和 `Singer` 类通过虚继承自 `Worker`，`SingingWaiter` 类多重继承了 `Waiter` 和 `Singer`，避免了钻石继承的问题。
 * 4. 构造函数：派生类需要在构造函数中显式调用基类构造函数，以初始化继承的成员变量。

 * 注意点：
 * 1. 确保基类 `Worker` 的析构函数为虚函数，以避免通过基类指针删除派生类对象时引发未定义行为。
 * 2. 在使用 `new` 动态分配内存时，要使用 `delete` 释放内存，防止内存泄漏。
 * 3. 输入验证：确保用户输入有效的员工类型字符，避免非法输入引发程序错误。
 */

const int SIZE = 3;

int main() {
    Worker* lolas[SIZE]; // 创建指向 Worker 对象的指针数组，用于存放不同类型的员工对象

    for (int i = 0; i < SIZE; ++i) {
        char choice;
        cout << "Enter the employee category: \n" << "w:waiter\ts:singer\tt:singing waiter\tq:quit" << endl;
        cin >> choice;
        // 验证用户输入，确保输入为有效的员工类型
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter w, s, t, q:"; // 提示用户重新输入
            cin >> choice;
        }
        if (choice == 'q')
            break; // 用户选择退出
        switch (choice) {
            case 'w':
                lolas[i] = new Waiter; // 创建一个新的 Waiter 对象
                break;
            case 's':
                lolas[i] = new Singer; // 创建一个新的 Singer 对象
                break;
            case 't':
                lolas[i] = new SingingWaiter; // 创建一个新的 SingingWaiter 对象
                break;
        }
        while (cin.get() != '\n'); // 清除输入缓冲区
        lolas[i]->set(); // 调用 set() 函数设置对象属性
    }
    cout << "\nHere is your staff: " << endl;
    for (int i = 0; i < SIZE; ++i) {
        lolas[i]->show(); // 调用 show() 函数显示对象信息
        cout << endl;
    }
    for (int i = 0; i < SIZE; ++i) {
        delete lolas[i]; // 释放动态分配的内存
    }

    return 0;
}