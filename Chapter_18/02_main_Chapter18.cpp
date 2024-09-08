/*
知识点：
1. **构造函数与默认参数**：`Action` 和 `Bingo` 的构造函数均有默认参数。
2. **继承与虚函数**：`Bingo` 类继承自 `Action` 类，并重写了虚函数 `f`，通过关键字 `override` 标明。
3. **多态**：使用虚函数的重写特性，`Bingo` 类中的 `f` 方法覆盖了基类 `Action` 中的 `f` 方法。

注意点：
1. 虚函数 `f` 在基类和派生类中都要保持一致的函数签名（包括参数类型和返回值）。
2. 构造函数的初始化列表应用于类成员变量的初始化，如 `Action(int i = 0) : a(i)`。

*/

#include <iostream>
using namespace std;

// 基类 Action
class Action {
    int a;  // 成员变量，存储整数
public:
    // 构造函数，带有默认参数 i
    Action(int i = 0) : a(i) {}

    // 获取成员变量 a 的值
    int val() const { return a; }

    // 虚函数 f，接受字符参数 ch 并输出
    virtual void f(char ch) const {
        cout << val() << ch << '\n';  // 输出 a 和 ch
    }
};

// 派生类 Bingo，继承自 Action
class Bingo : public Action {
public:
    // 构造函数，调用基类构造函数
    Bingo(int i = 0) : Action(i) {}

    // 重写基类的虚函数 f，添加 "!" 到输出
    void f(char ch) const override {
        cout << val() << ch << "!\n";  // 输出 a、ch 和 "!"
    }
};

int main() {
    // 创建 Bingo 对象 b，初始化值为 10
    Bingo b(10);

    // 调用重写的虚函数 f
    b.f('@');  // 输出 "10@!"

    return 0;
}