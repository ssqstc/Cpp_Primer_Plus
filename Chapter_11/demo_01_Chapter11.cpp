#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 类与对象：定义 Num 类及其成员函数，实现数字的加法运算。
 * - 构造函数：提供默认构造函数和带参数构造函数初始化对象。
 * - 运算符重载：重载加法运算符实现 Num 对象的相加。
 * - 成员函数：实现数值的显示功能。
 *
 * 注意点：
 * - 构造函数的初始化列表和默认参数使用。
 * - 运算符重载函数的实现和使用。
 * - 成员函数中使用 const 保证函数不修改对象。
 * - 运算符重载函数作为友元函数定义在类外部。
 */

class Num{
private:
    // 不再需要声明成员 n，因为它是 public
public:
    int n; // 数字成员
    Num(); // 默认构造函数
    Num(int m); // 带参数构造函数
    void show() const; // 显示数字
};

// 默认构造函数，将 n 初始化为 0
Num::Num() {
    n = 0;
}

// 带参数构造函数，初始化 n 为 m
Num::Num(int m) {
    n = m;
}

// 显示数字
void Num::show() const {
    cout << "n = " << n << endl; // 输出 n 的值
}

// 重载加法运算符，返回两个 Num 对象的和
Num operator+(const Num &m, const Num &l) {
    Num temp; // 临时对象用于存储结果
    temp.n = m.n + l.n; // 相加并赋值给临时对象
    return temp; // 返回临时对象
}

int main(){
    Num a(10); // 创建 Num 对象 a，初始化为 10
    a.show(); // 显示 a 的值

    Num b(20); // 创建 Num 对象 b，初始化为 20
    b.show(); // 显示 b 的值

    Num c; // 创建 Num 对象 c，默认初始化为 0
    c = a + b; // 将 a 和 b 相加，结果赋值给 c
    c.show(); // 显示 c 的值

    return 0;
}
