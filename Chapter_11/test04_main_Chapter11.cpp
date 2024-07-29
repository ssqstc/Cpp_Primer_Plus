#include "test04_head_Chapter11.h"

/**
 * 知识点总结:
 * 1. 类的定义与构造：定义了 `Time` 类，并提供默认构造函数和带参数的构造函数。
 * 2. 成员函数：包括增加分钟和小时的函数以及重置时间的函数。
 * 3. 友元函数：定义了 `operator+`、`operator-`、`operator*` 和输出运算符 `operator<<`。
 * 4. 运算符重载：实现了时间的加法、减法、乘法以及输出的重载。
 * 5. 标准输入输出：使用 `cin` 和 `cout` 进行输入输出操作。

 * 注意点:
 * 1. 时间的表示和处理：小时和分钟的加减法需要注意进位和借位问题。
 * 2. 运算符重载：确保重载的运算符不修改操作数本身。
 * 3. 友元函数：在类的外部定义，但可以访问类的私有成员。
 * 4. `operator<<` 输出运算符需要处理末尾换行符。
 */

int main() {
    Time coding(4, 35);  // 初始化coding时间为4小时35分钟
    Time fixing(2, 47);  // 初始化fixing时间为2小时47分钟
    Time total;  // 总时间
    Time diff;  // 时间差
    Time adjusted;  // 调整后的时间

    cout << "coding time = " << coding;  // 输出coding时间

    cout << "fixing time = " << fixing;  // 输出fixing时间

    total = coding + fixing;  // 计算总时间
    cout << "total time = " << total;  // 输出总时间

    diff = coding - fixing;  // 计算时间差
    cout << "difference time = " << diff;  // 输出时间差

    adjusted = coding * 1.5;  // coding时间乘以1.5
    cout << "adjusted time = " << adjusted;  // 输出调整后的时间

    adjusted = 1.5 * coding;  // 1.5乘以coding时间
    cout << "adjusted time = " << adjusted;  // 输出调整后的时间

    return 0;
}
