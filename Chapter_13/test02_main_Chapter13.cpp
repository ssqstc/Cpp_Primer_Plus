#include "test02_head_Chapter13.h"

/*
知识点总结:
1. **深拷贝与动态内存管理**: 本示例中展示了如何使用深拷贝构造函数和赋值运算符来正确管理动态分配的内存。
2. **拷贝构造函数与赋值运算符重载**: 通过实现拷贝构造函数与赋值运算符，确保对象的深拷贝，防止内存泄漏和浅拷贝问题。
3. **虚函数的继承与重载**: `report`函数在基类中定义为虚函数，派生类`Classic`进行了重载，展示了多态性。

注意点:
1. **内存泄漏与悬空指针**: 在析构函数、拷贝构造函数和赋值运算符中，谨慎处理动态内存，确保避免内存泄漏和悬空指针的发生。
2. **基类与派生类的初始化**: 在派生类的构造函数和赋值运算符中，通过调用基类的相应函数或构造函数，确保基类部分正确初始化。
*/

void bravo(const Cd & disk); // 函数声明，接受Cd类的引用作为参数

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5); // 创建Cd对象
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brenden", "Philips", 2, 57.17); // 创建Classic对象
    Cd *pcd = &c1; // 基类指针指向基类对象

    cout << "Using object directly:\n";
    c1.report(); // 直接使用对象调用report
    c2.report(); // 派生类对象调用report

    cout << "Using type cd * pointer to objects:\n";
    pcd->report(); // 使用基类指针调用基类对象的report
    pcd = &c2; // 基类指针指向派生类对象
    pcd->report(); // 使用基类指针调用派生类对象的report，展示多态性

    cout << "Calling a function with a Cd reference argument:\n";
    bravo(c1); // 通过引用传递基类对象
    bravo(c2); // 通过引用传递派生类对象，展示多态性

    cout << "Testing assignment: ";
    Classic copy; // 创建派生类对象
    copy = c2; // 测试赋值运算，确保正确的深拷贝
    copy.report(); // 显示复制结果

    return 0;
}

void bravo(const Cd & disk) {
    disk.report(); // 调用引用对象的report函数，展示多态性
}