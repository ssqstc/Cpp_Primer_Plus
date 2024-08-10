#include "test04_head_Chapter13.h"

/*
 * 知识点总结：
 * 1. 多态性与虚函数：本程序通过基类指针指向派生类对象，展示了多态性。`Port` 类提供了虚函数 `show()`，以便在基类和派生类之间进行动态绑定。
 * 2. 复制构造函数与赋值操作符：`Port` 和 `VintagePort` 类实现了复制构造函数和赋值操作符，用于深拷贝对象的数据成员，避免浅拷贝导致的内存问题。
 * 3. 析构函数：两个类都实现了析构函数，用于释放动态分配的内存，防止内存泄漏。
 * 4. 友元函数：通过重载 `<<` 操作符，实现了 `Port` 和 `VintagePort` 对象的输出。
 *
 * 注意点：
 * 1. 动态内存分配时，需要确保在合适的地方释放内存，以避免内存泄漏。
 * 2. 在重载 `=` 操作符时，注意避免自赋值的情况，以防止程序出现逻辑错误。
 * 3. `strncpy` 函数在使用时需确保字符串的最后一个字符是 `\0`，以防止字符串操作越界。
 */

int main() {
    // 创建一个 Port 对象 port1，品牌（brand）为 "ABC"，类型（style）为 "sweet"，瓶数（bottles）为 200
    Port port1("ABC", "sweet", 200);
    cout << port1 << endl; // 输出 port1 的信息

    cout << "----------------Dividing----------------" << endl; // 输出分隔线

    // 创建一个 VintagePort 对象 vp，品牌为 "EFG"，类型为 "vintage"，瓶数为 300，昵称（nickname）为 "Old Jack"，年份（year）为 40
    VintagePort vp("EFG", "vintage", 300, "Old Jack", 40);
    cout << vp << endl; // 输出 vp 的信息

    cout << "----------------Dividing----------------" << endl; // 输出分隔线

    // 使用复制构造函数创建一个 VintagePort 对象 vp2
    VintagePort vp2(vp);
    cout << vp2 << endl; // 输出 vp2 的信息

    cout << "----------------Dividing----------------" << endl; // 输出分隔线

    // 创建一个指向 Port 对象的指针 p_port
    Port * p_port;
    p_port = &port1; // 将 p_port 指向 port1
    p_port->show(); // 调用 Port 类的 show() 函数，显示 port1 的信息

    cout << "----------------Dividing----------------" << endl; // 输出分隔线

    p_port = &vp; // 将 p_port 指向 vp（VintagePort 对象）
    p_port->show(); // 调用 VintagePort 类的 show() 函数，显示 vp 的信息

    return 0; // 返回 0，表示程序成功结束
}