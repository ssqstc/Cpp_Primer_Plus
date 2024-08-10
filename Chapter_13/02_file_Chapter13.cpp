#include "02_head_Chapter13.h"

// Brass类的构造函数
Brass::Brass(const std::string &s, long an, double bal) {
    m_fullName = s;
    m_acctNum = an;
    m_balance = bal;
}

// 向账户存款
void Brass::deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit is not allowed!" << endl;
    else
        m_balance += amt;
}

// 从账户取款
void Brass::withDraw(double amt) {
    if (amt < 0)
        cout << "Withdraw amount must be positive." << endl;
    else if (amt <= m_balance)
        m_balance -= amt;
    else
        cout << "Withdraw amount exceeded your balance!" << endl;
}

// 获取账户余额
double Brass::balance() const {
    return m_balance;
}

// 查看账户信息
void Brass::viewAcct() const {
    cout << "Client: " << m_fullName << endl;
    cout << "Account number: " << m_acctNum << endl;
    cout << "Balance: $" << m_balance << endl;
}

// BrassPlus类的构造函数，调用基类构造函数
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double rate) : Brass(s, an, bal) {
    m_maxLoan = ml;
    m_rate = rate;
    m_owesBank = 0.0;
}

// 使用Brass对象创建BrassPlus对象
BrassPlus::BrassPlus(const Brass &ba, double ml, double rate) : Brass(ba) {
    m_maxLoan = ml;
    m_rate = rate;
    m_owesBank = 0.0;
}

// 查看BrassPlus账户信息，包含父类和子类的账户信息
void BrassPlus::viewAcct() const {
    Brass::viewAcct();
    cout << "Maximum load: $" << m_maxLoan << endl;
    cout << "Loan Rate: " << m_rate << endl;
    cout << "Owed to bank: $" << m_owesBank << endl;
}

// 从BrassPlus账户取款
void BrassPlus::withDraw(double amt) {
    double bal = balance();
    if (amt <= bal)
        Brass::withDraw(amt);
    else if (amt <= bal + m_maxLoan - m_owesBank) {
        double advance = amt - bal;
        m_owesBank = advance * (1.0 + m_rate);
        cout << "Bank Advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * m_rate << endl;
        deposit(advance);
        Brass::withDraw(amt);
    } else
        cout << "Credit limit exceeded!" << endl;
}