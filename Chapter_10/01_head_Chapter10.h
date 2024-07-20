#ifndef __01_HEAD_CHAPTER10_H__
#define __01_HEAD_CHAPTER10_H__
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
    void acquire(const string &co, long n, double pr); // 初始化公司信息
    void buy(long num, double price); // 买入股票
    void sell(long num, double price); // 卖出股票
    void update(double price); // 更新股票价格
    void show(); // 显示公司信息
};

#endif //__01_HEAD_CHAPTER10_H__
