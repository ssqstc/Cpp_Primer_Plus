#include "test03_head_Chapter12.h"

// 默认构造函数
Stock::Stock() {
    m_company = nullptr; // 公司名称初始化为空
    m_shares = 0; // 股票数量初始化为0
    m_shareVal = m_totalVal = 0.0; // 股票单价和总价值初始化为0.0
}

// 带参数的构造函数
Stock::Stock(const char *co, long n, double pr) {
    m_company = new char [strlen(co) + 1];  // 动态分配内存
    strcpy(m_company, co);  // 复制公司名称
    if (n < 0) { // 检查股票数量是否为负数
        cout << "Number of shares can't be negative: " << m_company << " shares set to be 0." << endl; // 输出错误信息
        m_shares = 0; // 如果为负数，将股票数量设为0
    } else {
        m_shares = n; // 否则，设为指定数量
    }
    m_shareVal = pr; // 设置股票单价
    set_tot();  // 计算总价值
}

// 析构函数
Stock::~Stock() {
    delete[] m_company;  // 释放动态分配的内存
}

// 买入股票
void Stock::buy(long num, double price) {
    if (num < 0) { // 检查买入数量是否为负数
        cout << "Number of shares can't be negative, Transaction is aborted." << endl; // 输出错误信息
    } else {
        m_shares += num; // 增加股票数量
        m_shareVal = price; // 更新股票单价
        set_tot();  // 更新总价值
    }
}

// 卖出股票
void Stock::sell(long num, double price) {
    if (num < 0) { // 检查卖出数量是否为负数
        cout << "Number of shares can't be negative, Transaction is aborted." << endl; // 输出错误信息
    } else if (num > m_shares) { // 检查卖出数量是否大于持有数量
        cout << "You can't sell more than you have! Transaction is aborted." << endl; // 输出错误信息
    } else {
        m_shares -= num; // 减少股票数量
        m_shareVal = price; // 更新股票单价
        set_tot();  // 更新总价值
    }
}

// 更新股票价格
void Stock::upDate(double price) {
    m_shareVal = price; // 更新股票单价
    set_tot();  // 更新总价值
}

// 重载输出运算符
ostream &operator<<(ostream &os, const Stock &stock) {
    os << "Company: " << stock.m_company << endl; // 输出公司名称
    os << "Shares: " << stock.m_shares << endl; // 输出股票数量
    os << "Share price: " << stock.m_shareVal << endl; // 输出股票单价
    os << "Total worth: " << stock.m_totalVal << endl; // 输出总价值
    return os;
}

// 比较两个股票对象，返回总价值较高的股票对象
const Stock &Stock::topVal(const Stock &s) const {
    if (s.m_totalVal > m_totalVal) {
        return s; // 返回总价值较高的股票对象
    } else {
        return *this; // 返回当前对象
    }
}