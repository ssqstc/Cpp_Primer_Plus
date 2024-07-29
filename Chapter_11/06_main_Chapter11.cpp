/**
 * 知识点总结：
 * 1. **构造函数重载**：提供了多个构造函数，以不同的方式初始化对象。
 * 2. **成员函数**：定义了 `show_lbs` 和 `show_stn` 函数，用于显示重量。
 * 3. **常量成员**：使用 `const` 修饰成员函数，表示这些函数不会修改对象的状态。
 * 4. **静态常量数据成员**：使用 `static const` 声明类中的常量数据成员。
 *
 * 注意点：
 * 1. **构造函数的调用**：了解不同构造函数的调用方式和使用场景。
 * 2. **数据成员初始化**：确保数据成员在构造函数中正确初始化。
 * 3. **成员函数的 const 修饰**：确保不会在无意中修改对象状态。
 * 4. **静态常量成员的初始化**：在类定义内初始化静态常量成员。
 */

#include "06_head_Chapter11.h"

int main() {
    Stonewt incognito = 275; // 初始化为275磅，调用 Stonewt(double lbs) 构造函数
    Stonewt wolfe(285.7); // 初始化为285.7磅，调用 Stonewt(double lbs) 构造函数
    Stonewt taft(21, 8); // 初始化为21英石8磅，调用 Stonewt(int stn, double lbs) 构造函数

    incognito.show_stn(); // 以英石为单位显示重量
    wolfe.show_stn(); // 以英石为单位显示重量
    taft.show_lbs(); // 以磅为单位显示重量

    cout << "----------------Dividing----------------" << endl; // 分隔线

    incognito = 276.8; // 将 incognito 重新赋值为276.8磅
    taft = 325; // 将 taft 重新赋值为325磅
    incognito.show_stn(); // 以英石为单位显示重量
    taft.show_lbs(); // 以磅为单位显示重量
    return 0;
}
