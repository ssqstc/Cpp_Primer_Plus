#include "04_head_Chapter13.h"

// AcctABC类的构造函数
AcctABC::AcctABC(const std::string &s, long an, double bal) {
    m_fullName = s; // 初始化客户姓名
    m_acctNum = an; // 初始化账号
    m_balance = bal; // 初始化余额
}

// 存款函数
void AcctABC::deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit is not allowed!" << endl; // 输出错误信息，存款不能为负
    else
        m_balance += amt; // 增加余额
}

// 取款函数
void AcctABC::withDraw(double amt) {
    m_balance -= amt; // 减少余额
}

// Brass类的取款函数
void Brass::withDraw(double amt) {
    if (amt < 0)
        cout << "Withdraw amount must be positive." << endl; // 输出错误信息，取款不能为负
    else if (amt <= balance())
        AcctABC::withDraw(amt); // 调用基类的取款函数
    else
        cout << "Withdraw amount exceeded your balance!" << endl; // 输出错误信息，取款超过余额
}

// Brass类的显示账户信息函数
void Brass::viewAcct() const {
    cout << "Client: " << AcctABC::fullName() << endl; // 输出客户姓名
    cout << "Account number: " << AcctABC::acctNum() << endl; // 输出账号
    cout << "Balance: $" << AcctABC::balance() << endl; // 输出余额
}

// BrassPlus类的构造函数，调用基类构造函数
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double rate) : AcctABC(s, an, bal) {
    m_maxLoan = ml; // 初始化透支限额
    m_rate = rate; // 初始化利率
    m_owesBank = 0.0; // 初始化欠银行的金额
}

// 使用AcctABC对象创建BrassPlus对象
BrassPlus::BrassPlus(const AcctABC &abc, double ml, double rate) : AcctABC(abc) {
    m_maxLoan = ml; // 初始化透支限额
    m_rate = rate; // 初始化利率
    m_owesBank = 0.0; // 初始化欠银行的金额
}

// BrassPlus类的显示账户信息函数
void BrassPlus::viewAcct() const {
    cout << "BrassPlus Client: " << AcctABC::fullName() << endl; // 输出客户姓名
    cout << "Account number: " << AcctABC::acctNum() << endl; // 输出账号
    cout << "Balance: $" << AcctABC::balance() << endl; // 输出余额
    cout << "Maximum load: $" << m_maxLoan << endl; // 输出透支限额
    cout << "Loan Rate: " << m_rate << endl; // 输出利率
    cout << "Owed to bank: $" << m_owesBank << endl; // 输出欠银行的金额
}

// BrassPlus类的取款函数
void BrassPlus::withDraw(double amt) {
    double bal = balance(); // 获取当前余额
    if (amt <= bal)
        AcctABC::withDraw(amt); // 调用基类的取款函数
    else if (amt <= bal + m_maxLoan - m_owesBank) {
        double advance = amt - bal; // 计算透支金额
        m_owesBank = advance * (1.0 + m_rate); // 计算欠银行的金额
        cout << "Bank Advance: $" << advance << endl; // 输出透支金额
        cout << "Finance charge: $" << advance * m_rate << endl; // 输出利息
        deposit(advance); // 存款透支金额
        AcctABC::withDraw(amt); // 调用基类的取款函数
    } else
        cout << "Credit limit exceeded!" << endl; // 输出错误信息，超出透支限额
}
