#ifndef __TEST01_HEAD_CHAPTER10__
#define __TEST01_HEAD_CHAPTER10__
#include "string"
using namespace std;

/*
 * BankAccount 类定义
 * 模拟银行账户的基本操作：显示账户信息、存款、取款
 */
class BankAccount{
private:
    string name; // 账户名
    string account; // 账户号
    double deposit; // 存款余额
public:
    BankAccount(); // 默认构造函数
    BankAccount(const string &client, const string &num, double bal = 0.0); // 带参数的构造函数
    void show() const; // 显示账户信息
    void put(double money); // 存款操作
    void get(double money); // 取款操作
};

#endif // __TEST01_HEAD_CHAPTER10__