#ifndef __03_HEAD_CHAPTER10_H__
#define __03_HEAD_CHAPTER10_H__
#include "string"
using namespace std;

class Stock {
private:
    string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const string &co, long n, double pr);
    ~Stock();
    // Stock(const string &co = "Error", long n = 0, double pr = 0.0);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock& topval(const Stock &s) const; // 返回总价值较高的股票对象
};

#endif //__03_HEAD_CHAPTER10_H__