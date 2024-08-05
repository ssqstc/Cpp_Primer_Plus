#ifndef __TEST03_HEAD_CHAPTER12_H__
#define __TEST03_HEAD_CHAPTER12_H__

#include "iostream"
#include "string"
using namespace std;

class Stock {
private:
    char *m_company;  // 公司名称
    long m_shares;  // 股票数量
    double m_shareVal;  // 每股价格
    double m_totalVal;  // 总价值
    void set_tot() { m_totalVal = m_shares * m_shareVal; }  // 计算总价值

public:
    Stock();  // 默认构造函数
    Stock(const char *co, long n, double pr);  // 带参数的构造函数
    ~Stock();  // 析构函数
    void buy(long num, double price);  // 买入股票
    void sell(long num, double price);  // 卖出股票
    void upDate(double price);  // 更新股票价格
    const Stock& topVal(const Stock &stock) const;  // 返回总价值较高的股票对象

    friend ostream &operator<<(ostream &os, const Stock &stock);  // 重载输出运算符
};

#endif //__TEST03_HEAD_CHAPTER12_H__