#include "12_head_Chapter14.h"
#include <iostream>

using namespace std;

/*
 * 知识点总结：
 * 1. 模板模板参数：`Crab` 类使用模板模板参数，即 `Thing` 是一个模板参数，可以接受一个模板类，如 `Stack`。
 * 2. 模板类组合：`Crab` 类将 `Stack` 类作为模板参数，通过组合实现对不同类型栈（int 和 double）的操作。
 * 3. 栈的基本操作：`Stack` 类模板实现了栈的基本操作，包括 `push`（压栈）和 `pop`（弹栈）。

 * 注意点：
 * 1. 模板模板参数的语法比较复杂，`template <template <typename T> typename Thing>` 用于接收类模板作为参数。
 * 2. 栈操作中需注意栈满和栈空的判断，以防止溢出或在空栈上进行弹出操作。
 * 3. `push` 和 `pop` 操作时使用了引用传递，确保操作后元素的值可以传递回调用处。
 */

template <template <typename T> typename Thing>
class Crab {
private:
    Thing<int> s1;      // 使用模板参数 Thing 定义一个 int 类型的栈
    Thing<double> s2;   // 使用模板参数 Thing 定义一个 double 类型的栈
public:
    // 将 int 和 double 类型的值分别压入两个栈中
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }

    // 从两个栈中分别弹出 int 和 double 类型的值
    bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
};

int main() {
    int ni;
    double nb;
    Crab<Stack> nebula;  // 使用 Stack 类模板实例化 Crab 类

    cout << "Enter int & double pairs, such as 2 3.4(0 0 to end):" << endl;
    // 输入 int 和 double 成对的值，直至输入 0 0 结束
    while ((cin >> ni >> nb) && (ni > 0 && nb > 0)) {
        if (!nebula.push(ni, nb)) {  // 如果栈满，退出循环
            break;
        }
    }

    // 从栈中弹出元素并显示，直至栈为空
    while (nebula.pop(ni, nb)) {
        cout << ni << ", " << nb << endl;
    }

    return 0;
}