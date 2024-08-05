#include "test03_head_Chapter12.h"

Stock::Stock() {
    m_company = nullptr;
    m_shares = 0;
    m_shareVal = m_totalVal = 0.0;
}

Stock::Stock(const char *co, long n, double pr) {
    m_company = new char [strlen(co) + 1];
    strcpy(m_company, co);
    if (n < 0) {
        cout << "Number of shares can't be negative: " << m_company << " shares set to be 0." << endl;
        m_shares = 0;
    } else {
        m_shares = n;
    }
    m_shareVal = pr;
    set_tot();
}

Stock::~Stock() {
    delete[] m_company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << "Number of shares can't be negative, Transaction is aborted." << endl;
    } else {
        m_shares += num;
        m_shareVal = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << "Number of shares can't be negative, Transaction is aborted." << endl;
    } else if (num > m_shares) {
        cout << "You can't sell more than you have! Transaction is aborted." << endl;
    } else {
        m_shares -= num;
        m_shareVal = price;
        set_tot();
    }
}

void Stock::upDate(double price) {
    m_shareVal = price;
    set_tot();
}

ostream &operator<<(ostream &os, const Stock &stock) {
    os << "Company: " << stock.m_company << endl;
    os << "Shares: " << stock.m_shares << endl;
    os << "Share price: " << stock.m_shareVal << endl;
    os << "Total worth: " << stock.m_totalVal << endl;
    return os;
}

const Stock &Stock::topVal(const Stock &s) const {
    if (s.m_totalVal > m_totalVal) {
        return s; // 返回总价值较高的股票对象
    } else {
        return *this; // 返回当前对象
    }
}