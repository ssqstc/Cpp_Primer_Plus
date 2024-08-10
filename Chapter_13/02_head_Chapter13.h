#ifndef __02_HEAD_CHAPTER13_H__
#define __02_HEAD_CHAPTER13_H__

#include "iostream"
using namespace std;

// Brass类
class Brass {
private:
    string m_fullName; // 客户全名
    long m_acctNum; // 账户号码
    double m_balance; // 账户余额
public:
    Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0); // 构造函数
    void deposit(double amt); // 存款
    virtual void withDraw(double amt); // 取款
    double balance() const; // 获取余额
    virtual void viewAcct() const; // 查看账户信息
};

// BrassPlus类，继承自Brass类
class BrassPlus : public Brass {
private:
    double m_maxLoan; // 最高贷款额
    double m_rate; // 贷款利率
    double m_owesBank; // 欠银行的钱
public:
    BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500.0, double rate = 0.11125); // 构造函数
    BrassPlus(const Brass &ba, double ml = 500.0, double rate = 0.11125); // 使用Brass对象创建BrassPlus对象
    virtual void viewAcct() const; // 查看账户信息
    virtual void withDraw(double amt); // 取款
    void resetMax(double m) { m_maxLoan = m; } // 重置最高贷款额
    void resetRate(double r) { m_rate = r; } // 重置贷款利率
    void resetOwes() { m_owesBank = 0.0; } // 重置欠银行的钱
};

#endif //__02_HEAD_CHAPTER13_H__