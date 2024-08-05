#ifndef __TEST03_HEAD_CHAPTER12_H__
#define __TEST03_HEAD_CHAPTER12_H__

#include "iostream"
#include "string"
using namespace std;

class Stock {
private:
    char *m_company;
    long m_shares;
    double m_shareVal;
    double m_totalVal;
    void set_tot() { m_totalVal = m_shares * m_shareVal; }

public:
    Stock();
    Stock(const char *co, long n, double pr);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void upDate(double price);
    const Stock& topVal(const Stock &stock) const;

    friend ostream &operator<<(ostream &os, const Stock &stock);
};


#endif //__TEST03_HEAD_CHAPTER12_H__
