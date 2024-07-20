#include "iostream"
#include "03_head_Chapter10.h"

/*
 * Stock 类的默认构造函数
 * 初始化成员变量
 */
Stock::Stock() {
    company = "no name"; // 设置默认公司名
    shares = 0; // 设置默认股份数
    share_val = 0.0; // 设置默认每股价格
    total_val = 0.0; // 设置默认总价值
}

/*
 * Stock 类的构造函数
 * co - 公司名
 * n - 股份数
 * pr - 每股价格
 */
Stock::Stock(const string &co, long n, double pr) {
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
 * Stock 类的析构函数
 * 用于对象销毁时释放资源
 */
Stock::~Stock() {}

/*
 * 买入股票函数
 * num - 买入数量
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
 * 卖出股票函数
 * num - 卖出数量
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
 * 更新股票价格函数
 * price - 新价格
 */
void Stock::update(double price) {
    share_val = price; // 更新每股价格
    set_tot(); // 更新总价值
}

/*
 * 显示股票信息函数
 */
void Stock::show() const {
    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << "Share price: " << share_val << endl;
    cout << "Total worth: " << total_val << endl;
}

/*
 * 返回总价值较高的股票对象
 * s - 另一股票对象
 * 返回值 - 总价值较高的股票对象的引用
 */
const Stock& Stock::topval(const Stock &s) const {
    if (s.total_val > total_val) {
        return s; // 返回总价值较高的股票对象
    } else {
        return *this; // 返回当前对象
    }
}