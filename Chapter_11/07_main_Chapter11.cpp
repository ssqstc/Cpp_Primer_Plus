/**
 * 知识点总结：
 * 1. **转换构造函数**：定义从 `double` 到 `Stonewt` 以及从 `int` 到 `Stonewt` 的转换构造函数。
 * 2. **类型转换运算符**：定义类型转换运算符，将 `Stonewt` 对象转换为 `int` 和 `double` 类型。
 * 3. **常量成员函数**：确保某些成员函数不会修改对象的状态。
 * 4. **静态常量成员**：定义类中的常量数据成员。
 *
 * 注意点：
 * 1. **构造函数的调用**：注意构造函数的调用方式以及不同参数类型对应的构造函数。
 * 2. **类型转换的实现**：确保类型转换运算符正确实现，并注意类型转换的精度和舍入问题。
 * 3. **常量成员函数的使用**：在定义不会修改对象状态的函数时，应使用 `const` 修饰。
 * 4. **静态常量成员的初始化**：静态常量成员需要在类内初始化。
 */

#include "07_head_Chapter11.h"

int main() {
    Stonewt poppins(9, 2.8); // 初始化为9英石2.8磅，调用 Stonewt(int stn, double lbs) 构造函数
    double p_wt = poppins; // 将 Stonewt 对象转换为 double 类型
    cout << "poppins = " << p_wt << " pounds." << endl; // 输出转换后的磅数

    int weight = poppins; // 将 Stonewt 对象转换为 int 类型
    cout << "poppins = " << weight << " pounds." << endl; // 输出转换后的磅数

    cout << "poppins = " << int(poppins) << " pounds." << endl; // 显式转换为 int 类型并输出
    return 0;
}
