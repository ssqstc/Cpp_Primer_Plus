#ifndef __11_HEAD_CHAPTER09_H__
#define __11_HEAD_CHAPTER09_H__

namespace pers{
    struct Person{ // 定义 Person 结构体
        std::string fname; // 名字
        std::string lname; // 姓氏
    };
    void getPerson(Person &rp); // 声明获取 Person 信息的函数
    void showPerson(const Person &rp); // 声明显示 Person 信息的函数
}

namespace debts{
    using namespace pers;
    struct Debt{ // 定义 Debt 结构体
        Person name; // 债务人信息
        double amount; // 债务金额
    };
    void getDebt(Debt &rd); // 声明获取 Debt 信息的函数
    void showDebt(const Debt &rd); // 声明显示 Debt 信息的函数
    double sumDebts(const Debt arr[], int n); // 声明计算总债务金额的函数
}
#endif //__11_HEAD_CHAPTER09_H__