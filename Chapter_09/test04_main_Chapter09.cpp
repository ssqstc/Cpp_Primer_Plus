#include "iostream"
#include "test04_head_Chapter09.h"

/*
 * 知识点总结：
 * - 函数重载：根据不同的参数调用同名函数的不同版本。
 * - 命名空间：使用 `namespace` 组织代码，避免命名冲突。
 * - 结构体：使用 `struct` 定义一个数据结构来存储多个数据成员。
 * - 数组操作：遍历数组元素，计算最大值、最小值和平均值。
 *
 * 注意点：
 * - 使用 `using namespace SALES` 引入自定义命名空间。
 * - `setSales` 函数的两个版本：一个通过参数数组设置销售数据，另一个通过用户输入设置销售数据。
 * - `showSales` 函数显示销售数据的各项统计信息。
 */

int main(){
    using namespace SALES;

    Sales sa{};
    double ar[4] = {11.1, 22.2, 33.3, 44.4}; // 初始化销售数据数组
    setSales(sa, ar, 3); // 调用带参数的 setSales 函数
    showSales(sa); // 显示销售数据

    setSales(sa); // 调用无参数的 setSales 函数，通过用户输入设置数据
    showSales(sa); // 显示销售数据
    return 0;
}
