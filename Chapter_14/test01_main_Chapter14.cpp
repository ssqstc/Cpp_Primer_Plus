#include "test01_head_Chapter14.h"
/*
 * 知识点总结：
 * 1. 类模板 `Pair` 用于将两个 `valarray` 类型的数组封装在一起。
 * 2. `Wine` 类包含一个 `Pair` 对象来管理年份和瓶数的数据。
 * 3. `Wine` 类使用了组合的方式，将 `Pair` 作为私有成员，用于存储年份和瓶数。
 * 4. `getBottles()` 函数用于从用户输入获取每年对应的瓶数数据。
 * 5. `show()` 函数用于显示葡萄酒的名称、年份和瓶数。

 * 注意点：
 * 1. 构造函数的使用：`Wine` 类中提供了多个构造函数，支持不同方式的初始化。
 * 2. `valarray` 的使用：`valarray` 是标准库中的一个数组类，提供了丰富的操作符重载，适合用于数值计算。
 * 3. 内存安全：类的成员变量为标准库中的类型，不涉及手动内存管理，避免了内存泄漏的问题。
 */
int main() {
    // 从用户获取葡萄酒名称和年数
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50); // 获取输入的葡萄酒名称
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs; // 获取年数

    // 创建一个 Wine 对象，并从用户获取年份和瓶数
    Wine holding(lab, yrs);
    holding.getBottles(); // 获取每年的瓶数数据
    holding.show(); // 显示葡萄酒信息

    // 使用初始化列表创建另一个 Wine 对象
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.show(); // 显示葡萄酒信息

    // 显示总瓶数
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    cout << "Bye\n";
    return 0;
}