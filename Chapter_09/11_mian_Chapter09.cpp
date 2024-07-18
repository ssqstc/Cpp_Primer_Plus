#include <iostream>
#include "11_head_Chapter09.h"

/*
 * 知识点总结：
 * - 命名空间：用于组织代码，避免名称冲突。
 * - 结构体：定义了一种自定义的数据类型。
 * - 函数定义：定义了一些用于处理 Person 和 Debt 结构体的函数。
 *
 * 注意点：
 * - `using` 关键字引入命名空间，简化代码书写。
 * - 注意函数的参数传递方式和常量引用的使用。
 * - 确保头文件的多重包含保护机制。
 */

int main(){
    using debts::Debt; // 使用 debts 命名空间中的 Debt 结构体
    using debts::showDebt; // 使用 debts 命名空间中的 showDebt 函数

    Debt golf = {{"Micheal", "Jordan"}, 120.0}; // 初始化一个 Debt 结构体实例
    showDebt(golf); // 显示 Debt 信息

    return 0;
}