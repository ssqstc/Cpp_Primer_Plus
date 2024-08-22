// 知识点总结:
// 1. 演示了四种类型转换：`const_cast`、`static_cast`、以及隐式类型转换。
// 2. `const_cast` 用于去除指针或引用的常量属性，以允许修改常量对象。
// 3. `static_cast` 用于基本数据类型之间的转换或在已知安全的类层次结构中进行上行或下行转换。
// 4. 代码包含一个逻辑错误，尝试将基类对象强制转换为派生类指针，可能导致未定义行为。

// 注意点:
// 1. 在使用 `const_cast` 进行类型转换时，务必确认原始数据不是实际的常量，否则会引发未定义行为。
// 2. 在进行向下类型转换时，使用 `static_cast` 必须保证安全性，否则建议使用 `dynamic_cast` 进行安全检查。
// 3. 对于浮点数运算，使用 `static_cast` 明确数据类型可避免整数除法带来的精度丢失。

#include <iostream> // 包含标准输入输出流库
using namespace std;

// 定义类 A
class A {};

// 定义类 B，继承自 A
class B : public A {};

int main() {
    int i = 10; // 定义整型变量 i 并赋值为 10
    cout << "i = " << i << endl; // 输出 i 的值

    const int* p1 = &i; // 定义指向常量整数的指针 p1，指向变量 i

    int* p2 = const_cast<int*>(p1); // 使用 const_cast 去除常量属性，将 p1 转换为非 const 指针 p2
    *p2 = 20; // 通过 p2 修改 i 的值为 20
    cout << "i = " << i << endl; // 输出修改后的 i 的值

    double x = 10 / 3; // 进行整数除法，结果赋值给双精度浮点数 x
    cout << "x = " << x << endl; // 输出 x 的值，此时的结果为整数 3

    double y = static_cast<double>(10) / 3; // 使用 static_cast 将 10 转换为 double，再进行浮点数除法
    cout << "y = " << y << endl; // 输出 y 的值，结果为 3.33333...

    A a; // 定义 A 类对象 a
    B b; // 定义 B 类对象 b
    A* pa = static_cast<A*>(&b); // 将 B 类对象指针转换为基类 A 的指针，这种转换是安全的
    B* pb = static_cast<B*>(&a); // 尝试将基类 A 的指针转换为派生类 B 的指针，此处可能导致未定义行为

    // 注意：最后一行代码是不安全的，将基类对象强制转换为派生类对象指针，可能导致未定义行为
    return 0; // 返回 0 表示程序正常结束
}