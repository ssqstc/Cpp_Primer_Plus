#include "iostream"
#include "test01_head_Chapter10.h"

/*
 * 默认构造函数
 * 初始化成员变量为默认值
 */
BankAccount::BankAccount() {
    name = "null"; // 默认账户名为 "null"
    account = "null"; // 默认账户号为 "null"
    deposit = 0.0; // 默认存款为 0.0
}

/*
 * 带参数的构造函数
 * 初始化成员变量为指定值
 */
BankAccount::BankAccount(const string &client, const string &num, double bal) {
    name = client; // 初始化账户名
    account = num; // 初始化账户号
    deposit = bal; // 初始化存款余额
}

/*
 * 显示账户信息
 * const 成员函数，保证不修改对象的状态
 */
void BankAccount::show() const {
    cout << "The Account information: " << endl; // 输出账户信息
    cout << "name: " << name << endl; // 输出账户名
    cout << "account: " << account << endl; // 输出账户号
    cout << "deposit: " << deposit << endl; // 输出存款余额
}

/*
 * 存款操作
 * money - 存款金额
 */
void BankAccount::put(double money) {
    if (money > 0){ // 检查存款金额是否为正数
        cout << "------Deposit $" << money << "------" << endl; // 输出存款信息
        deposit += money; // 增加存款余额
    } else{
        cout << "error!" << endl; // 如果存款金额为负数，输出错误信息
    }
}

/*
 * 取款操作
 * money - 取款金额
 */
void BankAccount::get(double money) {
    if (money > 0){ // 检查取款金额是否为正数
        cout << "------Withdraw $" << money << "------" << endl; // 输出取款信息
        deposit -= money; // 减少存款余额
    } else{
        cout << "error!" << endl; // 如果取款金额为负数，输出错误信息
    }
}