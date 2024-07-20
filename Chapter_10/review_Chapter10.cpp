// 用户自定义的数据类型,其内包括想描述的数据、数据存储形式、操作数据的方法.
// 是一种将抽象转换为用户定义类型的C++工具。它将数据表示和操纵数据的方法组合成一个整洁的包。

// 类设计尽可能将公有接口与实现细节分开。公有接口表示设计的抽象组件。
// 将实现细节放在一起并将它们与抽象分开称为封装。
// 数据隐藏（将数据放在类的私有部分中）是一种封装，将实现细节隐藏在私有部分中也是一种封装。

// 对象是类的实例化

// 每个对象都有属于自己的数据成员,但是每个对象共享成员函数.

//#ifndef __HEAD_TEST__
//#define __HEAD_TEST__
//
//class BankAccount{
//private:
//    string name;
//    string account;
//    double deposit;
//public:
//    BankAccount(const string &client, const string &num, double bal = 0.0);
//    void show() const;
//    void put(double money);
//    void get(double money);
//};
//
//#endif // __HEAD_TEST__

// 声明程序对象时自动调用或者显式地去调用构造函数.
// 对象过期时或者程序运行结束时自动调用析构函数

//BankAccount::BankAccount(const string &client, const string &num, double bal){
//    name = client;
//    account = num;
//    deposit = bal;
//}

// 没有参数或者所有参数均有默认值的是默认构造函数
// 有默认构造函数在创建对象时不需要进行初始化的操作

//#ifndef __03_HEAD_CHAPTER10_H__
//#define __03_HEAD_CHAPTER10_H__
//#include "string"
//using namespace std;
//
//class Stock {
//private:
//    string company;
//    long shares;
//    double share_val;
//    double total_val;
//    void set_tot() { total_val = shares * share_val; }
//
//public:
//    Stock();
//    Stock(const string &co, long n, double pr);
//    ~Stock();
//    // Stock(const string &co = "Error", long n = 0, double pr = 0.0);
//    void buy(long num, double price);
//    void sell(long num, double price);
//    void update(double price);
//    void show() const;
//    const Stock& topval(const Stock &s) const; // 返回总价值较高的股票对象
//
//    const string &company_name() const {return company;}
//    long num_shares() const {return shares;}
//    double shareval() const {return share_val;}
//    double totalval() const {return total_val;}
//};
//
//#endif //__03_HEAD_CHAPTER10_H__

// this是当前调用函数对象的指针 *this是对象本身