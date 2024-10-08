#include "test01_head_Chapter12.h"

/*
知识点总结:
1. **类的构造函数和析构函数**: 包括默认构造函数、带参数的构造函数、拷贝构造函数和析构函数。
2. **深拷贝（Deep Copy）**: 拷贝构造函数和赋值运算符确保对象中的动态内存被正确拷贝。
3. **运算符重载**: 赋值运算符的重载实现。
4. **字符串处理**: 使用 `strcpy` 和 `strncpy` 进行字符串的复制和安全复制。

注意点:
1. **内存管理**: 确保动态分配的内存在析构函数和赋值运算符中被正确释放，避免内存泄漏。
2. **字符串复制**: 确保字符串复制时的边界处理，避免越界操作。
3. **自赋值检查**: 赋值运算符重载中需要处理自赋值的情况，避免不必要的操作。
*/

int main() {
    Cow cow1;  // 默认构造函数
    Cow cow2("ssqstc", "dadada", 70);  // 带参数的构造函数
    Cow cow3(cow2);  // 拷贝构造函数

    cow1 = cow2;  // 赋值运算符重载
    cow1.showCow();  // 显示cow1的信息
    cow2.showCow();  // 显示cow2的信息
    cow3.showCow();  // 显示cow3的信息
    return 0;
}