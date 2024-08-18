#include "test02_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. **模板类的继承**：`Wine` 类继承了模板类 `Pair<valarray<int>, valarray<int>>` 和标准库类 `string`，展示了多重继承的用法。
 * 2. **类型别名**：`typedef` 语句为复杂类型创建了简短的别名，简化了代码的可读性。
 * 3. **`valarray`**：这是 C++ 标准库中的一个容器类，提供了元素级别的数组操作。
 * 4. **友元函数**：`Wine` 类中定义的函数 `label` 返回私有继承的 `string` 类型，表明私有继承的访问控制及其对基类成员的处理。
 * 5. **构造函数重载**：`Wine` 类的多个构造函数展示了如何根据不同的参数初始化对象。
 *
 * 注意点：
 * 1. **多重继承的访问控制**：注意 `Wine` 类使用了私有继承，这意味着基类的公有和保护成员在派生类中变为私有成员，不能直接访问。
 * 2. **友元函数与私有继承的结合使用**：友元函数在私有继承中可以访问基类的私有成员，这在 `label` 函数中得以体现。
 * 3. **`valarray` 的使用**：确保使用 `valarray` 时对其方法及操作符的理解，尤其是数组的元素级操作和自动调整数组大小的能力。
 * 4. **类型转换**：`Wine` 类中多次使用了类型转换，将 `this` 指针转换为基类的引用，确保访问基类的成员。
 */

int main() {
    // 输入酒的名称
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    // 输入年份数量
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    // 创建 Wine 对象 holding，并获取瓶子数据
    Wine holding(lab, yrs);
    holding.getBottles();
    holding.show();

    // 使用预定义的年份和瓶子数据创建另一个 Wine 对象 more
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.show();

    // 输出 more 对象的瓶子总数
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    cout << "Bye\n";
    return 0;
}