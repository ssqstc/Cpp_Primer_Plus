#include "01_head_Chapter12.h"

/**
 * 知识点总结:
 * 1. 构造函数和析构函数: `StringBad` 类包括默认构造函数、带参构造函数、复制构造函数和析构函数。
 * 2. 深拷贝和浅拷贝: 复制构造函数和赋值运算符确保了深拷贝，避免多个对象指向同一内存区域。
 * 3. 静态成员: 使用静态成员变量 `num_strings` 来统计对象的数量。
 * 4. 运算符重载: 重载了 `=` 赋值运算符和 `<<` 输出运算符。
 *
 * 注意点:
 * 1. 动态内存管理: 构造函数和赋值运算符中需要确保正确的动态内存分配和释放。
 * 2. 自我赋值检查: 赋值运算符中应检查自我赋值情况。
 * 3. 静态成员的初始化: 静态成员变量需要在类外进行初始化。
 */

void callme1(StringBad &rsb);  // 通过引用传递对象，避免复制构造函数调用
void callme2(StringBad rsb);   // 通过值传递对象，会调用复制构造函数

int main() {
    StringBad headline1("Hello world");  // 使用带参构造函数
    StringBad headline2("Good morning");
    StringBad sports("ssqstc");

    cout << "Headline1: " << headline1 << endl;  // 输出Headline1
    cout << "Headline2: " << headline2 << endl;  // 输出Headline2
    cout << "Sports: " << sports << endl;        // 输出Sports

    callme1(headline1);  // 通过引用传递对象
    callme2(headline2);  // 通过值传递对象

    return 0;
}

void callme1(StringBad &rsb) {
    cout << "String passed by reference: " << rsb << endl;  // 输出通过引用传递的字符串
}

void callme2(StringBad rsb) {
    cout << "String passed by value: " << rsb << endl;  // 输出通过值传递的字符串
}