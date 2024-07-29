#include "test05_head_Chapter11.h"

/**
 * 知识点总结:
 * 1. 枚举类型: `Type` 枚举用于表示不同的重量显示类型。
 * 2. 类的构造函数: 重载了三个构造函数用于初始化 `Stonewt` 对象。
 * 3. 成员函数: `set_type` 用于设置重量显示类型。
 * 4. 运算符重载: 重载了 `+`, `-`, `*` 运算符用于 `Stonewt` 对象的加法、减法和乘法。
 * 5. 友元函数: 重载了输出运算符 `operator<<` 用于输出 `Stonewt` 对象。
 * 6. 常量成员: `Lbs_per_stn` 表示每英石的磅数，是类的静态常量成员。

 * 注意点:
 * 1. 类型转换: 构造函数中需要将输入的重量转换为英石和磅的组合表示。
 * 2. 枚举类型: 使用枚举类型时要注意类型安全和范围。
 * 3. 运算符重载: 重载的运算符需要返回新的对象而不是修改现有对象。
 * 4. 友元函数: 友元函数可以访问类的私有成员，但需要在类定义中声明。
 */

int main() {
    Stonewt incognito = 275;  // 初始化为275磅
    Stonewt wolfe(285.7);  // 初始化为285.7磅
    Stonewt taft(21, 8);  // 初始化为21英石8磅

    incognito.set_type(Stonewt::POUNDS);  // 设置显示类型为磅
    cout << incognito;  // 输出 incognito 的重量
    wolfe.set_type(Stonewt::FLOAT_POUNDS);  // 设置显示类型为浮动磅
    cout << wolfe;  // 输出 wolfe 的重量
    taft.set_type(Stonewt::STONE);  // 设置显示类型为英石
    cout << taft;  // 输出 taft 的重量

    taft = incognito + wolfe;  // 计算 incognito 和 wolfe 的重量和
    taft.set_type(Stonewt::STONE);  // 设置显示类型为英石
    cout << "taft = " << taft;  // 输出 taft 的重量

    taft = wolfe - incognito;  // 计算 wolfe 和 incognito 的重量差
    taft.set_type(Stonewt::FLOAT_POUNDS);  // 设置显示类型为浮动磅
    cout << "taft = " << taft;  // 输出 taft 的重量

    incognito = incognito * 2;  // incognito 的重量乘以2
    incognito.set_type(Stonewt::POUNDS);  // 设置显示类型为磅
    cout << "incognito = " << incognito;  // 输出 incognito 的重量
    return 0;
}
