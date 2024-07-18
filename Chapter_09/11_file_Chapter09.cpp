#include <iostream>
#include "11_head_Chapter09.h"

namespace pers{
    using std::cout;
    using std::cin;

    void getPerson(Person &rp){ // 获取 Person 信息
        cout << "Enter first name: "; // 输入名字
        cin >> rp.fname;
        cout << "Enter last name: "; // 输入姓氏
        cin >> rp.lname;
    }
    void showPerson(const Person &rp){ // 显示 Person 信息
        cout << rp.lname << ", " << rp.fname; // 显示姓氏，名字
    }
}

namespace debts{
    void getDebt(Debt &rd){ // 获取 Debt 信息
        getPerson(rd.name); // 获取 Person 信息
        std::cout << "Enter debt: "; // 输入债务金额
        std::cin >> rd.amount;
    }
    void showDebt(const Debt &rd){ // 显示 Debt 信息
        showPerson(rd.name); // 显示 Person 信息
        std::cout << ": $" << rd.amount << std::endl; // 显示债务金额
    }
    double sumDebts(const Debt arr[], int n){ // 计算总债务金额
        double total = 0;
        for (int i = 0; i < n; ++i) {
            total += arr[i].amount;
            return total; // 返回总债务金额
        }
    }
}