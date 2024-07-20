#include "iostream"
#include "test01_head_Chapter10.h"

/*
 * 知识点总结：
 * - 使用类封装银行账户信息及其操作：BankAccount 类封装了银行账户的基本操作。
 * - 构造函数重载：提供默认构造函数和带参数的构造函数，方便对象初始化。
 * - const 成员函数：用于不修改对象状态的成员函数，保证函数不会修改对象的状态。
 *
 * 注意点：
 * - 构造函数初始化列表：初始化类成员时可以使用初始化列表而不是赋值语句。
 * - 数据有效性检查：在存款和取款操作中进行有效性检查。
 * - const 成员函数的使用：保证函数不会修改对象的状态。
 */

/*
 * 主函数：演示 BankAccount 类的使用
 * - 创建 BankAccount 对象并显示账户信息
 * - 执行存款和取款操作并显示账户信息
 */

int main(){
    BankAccount root; // 创建默认的 BankAccount 对象
    root.show(); // 显示默认账户信息

    cout << "----------------Dividing----------------" << endl;

    BankAccount bank("ssqstc", "123456", 66666); // 使用参数创建 BankAccount 对象
    bank.show(); // 显示账户信息
    bank.put(666666); // 存款操作
    bank.show(); // 显示账户信息
    bank.get(1); // 取款操作
    bank.show(); // 显示账户信息

    return 0;
}
