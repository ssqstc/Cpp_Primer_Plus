#include "02_head_Chapter13.h"

/*
知识点总结:
1. **继承和多态**: `BrassPlus` 类继承自 `Brass` 类，并使用了虚函数来实现多态。
2. **构造函数**: 演示了基类和派生类的构造函数调用，以及派生类如何调用基类的构造函数。
3. **成员函数重载**: 展示了如何在派生类中重载基类的成员函数，以实现不同的功能。

注意点:
1. **虚函数**: 使用 `virtual` 关键字定义基类的成员函数，以便在派生类中重载。
2. **构造函数初始化列表**: 确保在派生类的构造函数中正确调用基类构造函数进行初始化。
3. **多态调用**: 在使用基类指针或引用调用派生类对象时，确保正确实现多态功能。
*/

int main() {
    Brass jerry("Jerry", 123456, 666666.0); // 创建Brass对象
    BrassPlus jack("Jack", 654321, 3000.0); // 创建BrassPlus对象

    jerry.viewAcct(); // 查看Jerry的账户信息
    cout << endl;
    jack.viewAcct(); // 查看Jack的账户信息
    cout << endl;

    cout << "Depositing $1000 into the Jack Account: " << endl;
    jack.deposit(1000); // 向Jack的账户存款1000美元
    cout << "New balance: $" << jack.balance() << endl; // 输出Jack的账户余额

    cout << "Withdraw $777777 from the Jerry Account: " << endl;
    jerry.withDraw(777777); // 从Jerry的账户取款777777美元
    cout << endl;

    cout << "Withdraw $4200 from the Jack Account: " << endl;
    jack.withDraw(4200); // 从Jack的账户取款4200美元
    jack.viewAcct(); // 查看Jack的账户信息
    return 0;
}