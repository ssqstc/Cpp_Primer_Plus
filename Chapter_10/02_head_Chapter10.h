#ifndef __02_HEAD_CHAPTER10_H__
#define __02_HEAD_CHAPTER10_H__
#include "string"
using namespace std;

class Stock {
private:
    string company; // 公司名
    long shares; // 股份数
    double share_val; // 每股价格
    double total_val; // 总价值
    void set_tot() { total_val = shares * share_val; } // 更新总价值

public:
    Stock(); // 默认构造函数
    Stock(const string &co, long n, double pr); // 带参数的构造函数
    ~Stock(); // 析构函数
    // Stock(const string &co = "Error", long n = 0, double pr = 0.0); // 可选构造函数
    void buy(long num, double price); // 买入股票
    void sell(long num, double price); // 卖出股票
    void update(double price); // 更新股票价格
    void show() const; // const 成员函数，显示公司信息
};

#endif //__02_HEAD_CHAPTER10_H__