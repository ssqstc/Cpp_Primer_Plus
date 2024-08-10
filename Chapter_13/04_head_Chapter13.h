#ifndef __04_HEAD_CHAPTER13_H__
#define __04_HEAD_CHAPTER13_H__

#include "iostream"
using namespace std;

// AcctABC抽象基类
class AcctABC {
private:
    string m_fullName; // 客户姓名
    long m_acctNum; // 账号
    double m_balance; // 余额
protected:
    const string &fullName() const { return m_fullName; } // 获取客户姓名
    long acctNum() const { return m_acctNum; } // 获取账号
public:
    AcctABC(const string &s = "Nullbody", long an = -1, double bal = 0.0); // 构造函数
    void deposit(double amt); // 存款函数
    double balance() const { return m_balance; } // 获取余额函数
    virtual void withDraw(double amt) = 0; // 纯虚函数，取款
    virtual void viewAcct() const = 0; // 纯虚函数，显示账户信息
    virtual ~AcctABC() {} // 虚析构函数
};

// Brass类，继承自AcctABC类
class Brass : public AcctABC {
public:
    Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {} // 构造函数
    virtual void withDraw(double amt); // 取款函数
    virtual void viewAcct() const; // 显示账户信息函数
    virtual ~Brass() {} // 虚析构函数
};

// BrassPlus类，继承自AcctABC类
class BrassPlus : public AcctABC {
private:
    double m_maxLoan; // 最高贷款额
    double m_rate; // 贷款利率
    double m_owesBank; // 欠银行的钱
public:
    BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500.0, double rate = 0.11125);// 构造函数
    BrassPlus(const AcctABC &abc, double ml = 500.0, double rate = 0.11125); // 构造函数
    virtual void viewAcct() const; // 显示账户信息函数
    virtual void withDraw(double amt); // 取款函数
    void resetMax(double m) { m_maxLoan = m; } // 重置最高贷款额
    void resetRate(double r) { m_rate = r; } // 重置贷款利率
    void resetOwes() { m_owesBank = 0.0; } // 重置欠银行的钱
};

#endif //__04_HEAD_CHAPTER13_H__