#include "iostream"
#include "02_head_Chapter10.h"
/*
 * 知识点总结：
 * - 构造函数：定义了默认构造函数和带参数的构造函数来初始化对象。
 * - 析构函数：定义了析构函数来处理对象销毁时的操作。
 * - 数据成员：定义了多个私有数据成员来存储对象的状态。
 * - 成员函数：定义了多个成员函数来操作对象的数据。
 * - const 成员函数：保证成员函数不会修改对象的状态。
 *
 * 注意点：
 * - 初始化对象时确保数据的有效性，避免负值操作。
 * - 使用 `set_tot` 函数更新总价值，保证数据一致性。
 */

int main() {
    // 初始化 Stock 类的对象并调用其构造函数
    Stock stock1("Nano Smart", 12, 20.0);
    stock1.show(); // 显示对象信息

    Stock stock2 = Stock("Boffo objects", 2, 2.0);
    stock2.show(); // 显示对象信息

    Stock stock3;   // 隐式调用默认构造函数
    // Stock stock3 = Stock();   // 显式调用默认构造函数
    stock3.show(); // 显示对象信息

    cout << "Assigning stock1 to stock2: \n";
    stock2 = stock1; // 赋值操作，将 stock1 的值赋给 stock2
    cout << "Listing stock1 and stock2: \n";
    stock1.show(); // 显示 stock1 信息
    stock2.show(); // 显示 stock2 信息

    cout << "Using a construct to reset an object: \n";
    stock1 = Stock("Nifty Foods", 10, 50.0); // 用构造函数创建临时对象并赋值给 stock1
    cout << "Revised stock1: \n";
    stock1.show(); // 显示 stock1 信息
    cout << "Done\n";

    const Stock lang = Stock("Klu proper", 3, 3.0); // 初始化 const 对象
    lang.show(); // 显示对象信息

    return 0;
}
