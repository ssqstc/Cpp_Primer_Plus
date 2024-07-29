#include "test06_head_Chapter11.h"

/**
 * 知识点总结:
 * 1. 枚举类型: `Type` 枚举用于表示不同的重量显示类型。
 * 2. 类的构造函数: 重载了三个构造函数用于初始化 `Stonewt` 对象。
 * 3. 运算符重载: 重载了 `==`, `!=`, `>`, `<`, `>=`, `<=` 运算符用于 `Stonewt` 对象的比较。
 * 4. 友元函数: 重载了输出运算符 `operator<<` 用于输出 `Stonewt` 对象。
 * 5. 常量成员: `Lbs_per_stn` 表示每英石的磅数，是类的静态常量成员。

 * 注意点:
 * 1. 类型转换: 构造函数中需要将输入的重量转换为英石和磅的组合表示。
 * 2. 运算符重载: 重载的运算符需要返回布尔值来表示比较结果。
 * 3. 友元函数: 友元函数可以访问类的私有成员，但需要在类定义中声明。
 */

const int SIZE = 6;

int main() {
    Stonewt st_arr[SIZE] = {275, Stonewt(285.7), Stonewt(21, 8)};  // 初始化数组，隐式转换, 275(隐式自动类型转换) 、 285.7、21,8 (构造函数)
    Stonewt delault;  // 默认构造函数初始化为0
    Stonewt eleven(11, 0.0);  // 初始化为11英石
    Stonewt max, min = st_arr[0];  // 初始化最大和最小值
    unsigned int count = 0;  // 计数器
    double input;  // 输入变量

    for (int i = 0; i < SIZE; ++i) {
        if (st_arr[i] == delault) {  // 如果数组元素为默认值
            cout << "Enter pounds:";
            cin >> input;  // 输入新的磅数
            st_arr[i] = input;  // 赋值给数组元素
        }
        if (st_arr[i] >= eleven) {  // 判断是否大于等于11英石
            count++;
        }
        max = max > st_arr[i] ? max : st_arr[i];  // 更新最大值
        min = min < st_arr[i] ? min : st_arr[i];  // 更新最小值
    }
    cout << "The max weight: " << max << ", the min weight " << min << ", " << count << " objects are heavier than eleven";
    return 0;
}
