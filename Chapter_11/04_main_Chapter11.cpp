#include "04_head_Chapter11.h"

/*
知识点：
1. 类和对象：定义了一个 Time 类，并在 main 函数中创建了多个 Time 对象。
2. 构造函数：Time 类有默认构造函数和带参数的构造函数。
3. 运算符重载：对 +、-、* 运算符进行了重载，用于 Time 对象之间的运算。
4. 友元函数：使用友元函数来重载运算符，使得可以用全局函数的方式处理 Time 对象。
5. 输入输出流：重载了 << 运算符，便于输出 Time 对象的信息。
6. 内联函数：在类内部定义的函数是内联函数，提升了性能。

注意点：
1. 时间运算：在进行时间的加减运算时，需注意分钟的进位和借位。
2. 构造函数初始化：确保构造函数正确初始化对象的成员变量。
3. 运算符重载的实现：确保返回的 Time 对象是新的对象，且不修改原有对象。
4. 友元函数：友元函数可以访问类的私有成员变量，要慎重使用以防止封装性破坏。
5. 对象输出：重载 << 运算符时，返回的应该是引用，且确保输出流的格式正确。
*/

int main() {
    Time coding(4, 35);  // 初始化为 4 小时 35 分钟
    Time fixing(2, 47);  // 初始化为 2 小时 47 分钟
    Time total;          // 默认初始化为 0 小时 0 分钟
    Time diff;           // 默认初始化为 0 小时 0 分钟
    Time adjusted;       // 默认初始化为 0 小时 0 分钟

    // 打印 coding 时间
    cout << "coding time = ";
    cout << coding;

    // 打印 fixing 时间
    cout << "fixing time = ";
    cout << fixing;

    // 计算并打印 total 时间
    total = coding + fixing;
    cout << "total time = ";
    cout << total;

    // 计算并打印 diff 时间
    diff = coding - fixing;
    cout << "difference time = ";
    cout << diff;

    // 计算并打印 adjusted 时间 (对象方法)
    adjusted = coding * 1.5;
    cout << "adjusted time = ";
    cout << adjusted;

    // 计算并打印 adjusted 时间 (友元函数)
    adjusted = 1.5 * coding;
    cout << "adjusted time (friend function) = ";
    cout << adjusted;

    // 分隔线
    cout << "----------------Dividing----------------" << endl;
    cout << coding << fixing;

    return 0;
}
