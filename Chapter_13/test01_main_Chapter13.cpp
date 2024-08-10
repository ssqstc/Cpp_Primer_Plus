#include "test01_head_Chapter13.h"

/*
知识点总结:
1. **继承与多态**: 演示了派生类（`Classic`）继承基类（`Cd`）并重写虚函数的多态性。
2. **虚函数的使用**: `report`函数在基类中定义为虚函数，保证了通过基类指针调用时，派生类的重载版本能够被正确调用。
3. **默认构造函数与参数构造函数**: 通过多个构造函数的实现展示了如何为类提供多种初始化方式。

注意点:
1. **字符数组的边界处理**: 在字符串复制过程中注意数组边界，避免溢出，同时保证以`'\0'`结尾。
2. **赋值运算与对象切片**: 通过赋值运算测试对象的深拷贝与对象切片问题，特别是在继承关系下。
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