#include "test03_head_Chapter12.h"

/*
知识点总结:
1. **构造函数和析构函数**: 包括默认构造函数、带参数的构造函数和析构函数。
2. **运算符重载**: 重载输出运算符以便打印对象信息。
3. **成员函数**: 包括买入、卖出、更新股票价格的成员函数，以及比较股票总价值的成员函数。
4. **动态内存管理**: 使用动态分配和释放内存来处理公司名称字符串。
5. **常量成员函数**: 保证函数不会修改对象的状态。

注意点:
1. **内存管理**: 确保动态分配的内存在析构函数中被正确释放，避免内存泄漏。
2. **数据有效性检查**: 在买入和卖出股票时需要检查数量的有效性，防止非法操作。
3. **常量指针**: 使用常量指针避免在比较过程中修改对象。
*/

const int STKS = 4; // 股票数量
int main() {
    // 创建四个Stock对象的数组，并初始化
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0), // NanoSmart公司，12股，每股20.0元
            Stock("Boffo Objects", 200, 2.0), // Boffo Objects公司，200股，每股2.0元
            Stock("Mono", 130, 3.25), // Mono公司，130股，每股3.25元
            Stock("Fleep", 60, 6.5) // Fleep公司，60股，每股6.5元
    };
    cout << "Stock holding:" << endl; // 输出所有股票信息
    for (int i = 0; i < STKS; ++i) {
        cout << stocks[i];  // 输出每个Stock对象的信息
        cout << endl;
    }

    const Stock *top = &stocks[0];  // 指向价值最高的股票
    for (int i = 1; i < STKS; ++i) {
        top = &top->topVal(stocks[i]);  // 找到价值最高的股票
    }
    cout << "Most valuable holding: " << endl; // 输出最有价值的股票信息
    cout << *top;  // 输出价值最高的股票信息

    return 0;
}