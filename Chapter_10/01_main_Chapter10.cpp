#include "iostream"
#include "01_head_Chapter10.h"
/*
 * 知识点总结：
 * - 类和对象：使用 `class` 定义类，通过对象来使用类的成员函数和变量。
 * - 访问控制：使用 `private` 和 `public` 关键字控制类成员的访问权限。
 * - 成员函数：定义了类的成员函数来操作对象的状态。
 * - 构造函数：虽然本例中没有显式定义构造函数，但通过 `acquire` 方法模拟了初始化操作。
 * - 内联函数：通过 `inline` 关键字或者在类定义内定义的函数会被编译器视为内联函数。
 *
 * 注意点：
 * - 使用类成员函数来操作私有数据成员。
 * - 防止负值操作：在买入和卖出股票时，检查股票数量是否为负值。
 * - 使用私有成员函数 `set_tot` 来更新总值。
 */

/*
 * 主函数：测试 Stock 类的功能
 */
int main() {
    Stock fluffy_the_cat; // 创建 Stock 类的对象
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50); // 初始化对象
    fluffy_the_cat.show(); // 显示对象信息

    fluffy_the_cat.buy(15, 18.125); // 买入股票
    fluffy_the_cat.show(); // 显示对象信息

    fluffy_the_cat.sell(400, 20.0); // 尝试卖出超过拥有量的股票
    fluffy_the_cat.show(); // 显示对象信息

    fluffy_the_cat.buy(300000, 40.125); // 大量买入股票
    fluffy_the_cat.show(); // 显示对象信息

    fluffy_the_cat.sell(300000, 0.125); // 大量卖出股票
    fluffy_the_cat.show(); // 显示对象信息

    return 0;
}
