#include "04_head_Chapter13.h"

/*
知识点总结:
1. **抽象基类**: 使用纯虚函数定义抽象基类`AcctABC`，强制派生类实现特定函数。
2. **动态内存管理**: 使用`new`和`delete`进行对象的动态创建和释放。
3. **构造函数和析构函数**: 展示了派生类如何调用基类的构造函数，并定义虚析构函数确保资源释放。
4. **访问控制**: 基类和派生类之间的保护和私有成员访问控制。

注意点:
1. **纯虚函数**: 确保基类定义纯虚函数以便派生类实现。
2. **输入验证**: 在读取用户输入时确保输入有效。
3. **资源管理**: 确保动态分配的内存被正确释放，避免内存泄漏。
*/

const int CLIENTS = 3; // 定义常量，表示客户数量

int main() {
    AcctABC *p_clients[CLIENTS]; // 定义指向AcctABC对象的指针数组
    string temp; // 临时字符串存储客户姓名
    long tempNum; // 临时变量存储账户号码
    double tempBal; // 临时变量存储账户余额
    int kind; // 临时变量存储账户类型

    for (int i = 0; i < CLIENTS; ++i) {
        cout << "Enter the client's name: "; // 输出提示信息，输入客户姓名
        getline(cin, temp); // 获取客户姓名
        cout << "Enter client's account number: "; // 输出提示信息，输入客户账号
        cin >> tempNum; // 获取客户账号
        cout << "Enter opening balance: $"; // 输出提示信息，输入初始余额
        cin >> tempBal; // 获取初始余额
        cout << "Enter 1 for Brass Account or enter 2 for BrassPlus Account: "; // 输出提示信息，选择账户类型
        while (cin >> kind && (kind != 1 && kind != 2)) // 检查输入是否有效
            cout << "Enter either 1 or 2: "; // 输出提示信息，重新输入
        if (kind == 1)
            p_clients[i] = new Brass(temp, tempNum, tempBal); // 创建Brass对象
        else {
            double t_max, t_rate;
            cout << "Enter the overdraft limit: $"; // 输出提示信息，输入透支限额
            cin >> t_max; // 获取透支限额
            cout << "Enter the rate: "; // 输出提示信息，输入利率
            cin >> t_rate; // 获取利率
            p_clients[i] = new BrassPlus(temp, tempNum, tempBal, t_max, t_rate); // 创建BrassPlus对象
        }
        while (cin.get() != '\n'); // 清除输入缓冲区
    }
    cout << endl;

    for (int i = 0; i < CLIENTS; ++i) {
        p_clients[i]->viewAcct(); // 显示每个客户的账户信息
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; ++i) {
        delete p_clients[i]; // 释放动态分配的内存
    }
    return 0;
}
