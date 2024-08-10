#include "03_head_Chapter13.h"

/*
知识点总结:
1. **多态和虚函数**: 使用基类指针数组实现对不同派生类对象的统一管理。
2. **动态内存管理**: 使用`new`和`delete`进行对象的动态创建和释放。
3. **构造函数和析构函数**: 展示了派生类如何调用基类的构造函数，并定义虚析构函数确保资源释放。

注意点:
1. **虚析构函数**: 确保基类定义虚析构函数以便正确释放派生类对象的资源。
2. **输入验证**: 在读取用户输入时确保输入有效。
3. **资源管理**: 确保动态分配的内存被正确释放，避免内存泄漏。
*/

const int CLIENTS = 3;

int main() {
    Brass *p_clients[CLIENTS]; // 定义指向Brass对象的指针数组
    string temp; // 临时字符串存储客户姓名
    long tempNum; // 临时变量存储账户号码
    double tempBal; // 临时变量存储账户余额
    int kind; // 临时变量存储账户类型

    for (int i = 0; i < CLIENTS; ++i) {
        cout << "Enter the client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempNum;
        cout << "Enter opening balance: $";
        cin >> tempBal;
        cout << "Enter 1 for Brass Account or enter 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != 1 && kind != 2))
            cout << "Enter either 1 or 2: ";
        if (kind == 1)
            p_clients[i] = new Brass(temp, tempNum, tempBal); // 创建Brass对象
        else {
            double t_max, t_rate;
            cout << "Enter the overdraft limit: $";
            cin >> t_max;
            cout << "Enter the rate: ";
            cin >> t_rate;
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