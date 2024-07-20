#include "iostream"
#include "01_head_Chapter10.h"

/*
 * acquire：初始化股票信息
 * co - 公司名
 * n - 股份数
 * pr - 每股价格
 */
void Stock::acquire(const string &co, long n, double pr) {
    company = co; // 设置公司名
    if (n < 0) {
        cout << "Number of shares can't be negative: " << company << " shares set to be 0." << endl;
        shares = 0; // 股份数不能为负，设置为0
    } else {
        shares = n; // 设置股份数
    }
    share_val = pr; // 设置每股价格
    set_tot(); // 更新总价值
}

/*
 * buy：买入股票
 * num - 买入的股份数
 * price - 买入价格
 */
void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << "Number of shares can't be negative, Transaction is aborted." << endl;
    } else {
        shares += num; // 增加股份数
        share_val = price; // 更新每股价格
        set_tot(); // 更新总价值
    }
}

/*
 * sell：卖出股票
 * num - 卖出的股份数
 * price - 卖出价格
 */
void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << "Number of shares can't be negative, Transaction is aborted." << endl;
    } else if (num > shares) {
        cout << "You can't sell more than you have! Transaction is aborted." << endl;
    } else {
        shares -= num; // 减少股份数
        share_val = price; // 更新每股价格
        set_tot(); // 更新总价值
    }
}

/*
 * update：更新股票价格
 * price - 新的价格
 */
void Stock::update(double price) {
    share_val = price; // 更新每股价格
    set_tot(); // 更新总价值
}

/*
 * show：显示公司股票信息
 */
void Stock::show() {
    cout << "Company: " << company << endl; // 输出公司名
    cout << "Shares: " << shares << endl; // 输出股份数
    cout << "Share price: " << share_val << endl; // 输出每股价格
    cout << "Total worth: " << total_val << endl; // 输出总价值
}