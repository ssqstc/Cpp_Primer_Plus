#include "01_head_Chapter13.h"

/*
知识点总结:
1. **继承**: `RatedPlayer` 类继承自 `TableTennisPlayer` 类，演示了如何通过继承扩展类的功能。
2. **构造函数**: 演示了如何在派生类中调用基类的构造函数，并如何重载构造函数。
3. **成员函数**: 包含基类和派生类的成员函数，实现基本的对象操作和状态管理。

注意点:
1. **构造函数初始化列表**: 确保在派生类的构造函数中使用初始化列表正确初始化基类部分。
2. **函数重载和覆盖**: 理解在派生类中如何重载和覆盖基类函数。
3. **对象切片**: 当从基类复制派生类对象时，可能会发生对象切片，需要注意避免这种情况。

*/

int main() {
    RatedPlayer ratedPlayer1(1140, "Mallory", "Duck", false); // 创建RatedPlayer对象
    TableTennisPlayer player1("Tara", "Boomdea", false); // 创建TableTennisPlayer对象

    ratedPlayer1.name(); // 输出RatedPlayer1的名字
    if (ratedPlayer1.hasTable()) { // 检查RatedPlayer1是否有桌子
        cout << ": has a table." << endl;
    }
    else {
        cout << ": hasn't a table." << endl;
    }
    ratedPlayer1.name(); // 再次输出RatedPlayer1的名字
    cout << ", Rating: " << ratedPlayer1.rating() << endl; // 输出RatedPlayer1的评分

    RatedPlayer ratedPlayer2(1212, player1); // 使用TableTennisPlayer对象创建RatedPlayer对象
    cout << "Name: ";
    ratedPlayer2.name(); // 输出RatedPlayer2的名字
    cout << ", Rating: " << ratedPlayer2.rating() << endl; // 输出RatedPlayer2的评分
    return 0;
}