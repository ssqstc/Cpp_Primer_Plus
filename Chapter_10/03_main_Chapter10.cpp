#include "iostream"
#include "03_head_Chapter10.h"
/*
 * 知识点总结：
 * - this指针：用于指向调用成员函数的对象本身。
 * - 对象数组的使用。
 *
 * 注意点：
 * - 确保数据有效性，避免负值操作。
 * - 使用 `set_tot` 函数更新总价值，保证数据一致性。
 * - 使用 const 关键字修饰不会修改对象状态的成员函数。
 * - 返回对象引用时注意避免返回局部变量的引用。
 */

const int STKS = 4;
int main() {
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Mono", 130, 3.25),
            Stock("Fleep", 60, 6.5)
        };
    cout << "Stock holding:" << endl;
    for (int i = 0; i < STKS; ++i) {    // 遍历数组对象成员信息
        stocks[i].show();
        cout << endl;
    }

    const Stock *top = &stocks[0];
    for (int i = 1; i < STKS; ++i) {
        top = &top->topval(stocks[i]);  // 获取数组对象中总价值较高的对象
    }
    cout << "\nMost valuable holding: " << endl;
    top->show();

//    const Stock& top = stock1.topval(stock2);  // 获取总价值较高的对象
//    cout << "\nNow show the top val:\n";
//    top.show();

    return 0;
}