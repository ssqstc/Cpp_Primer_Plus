#include "01_head_Chapter11.h"

/*
 * 知识点总结：
 * - 类与对象：定义 Time 类及其成员函数，实现时间的加法运算。
 * - 构造函数：提供默认构造函数和带参数构造函数初始化对象。
 * - 运算符重载：重载加法运算符实现 Time 对象的相加。
 * - 成员函数：实现时间的加法、重置、显示等功能。
 *
 * 注意点：
 * - 构造函数的默认参数使用。
 * - 运算符重载函数的实现和使用。
 * - 成员函数中使用 const 保证函数不修改对象。
 */

int main(){
    Time coding(2, 40); // 创建 Time 对象 coding，初始化为 2 小时 40 分钟
    Time fixing(5, 55); // 创建 Time 对象 fixing，初始化为 5 小时 55 分钟
    Time total; // 创建 Time 对象 total
    Time planning; // 创建 Time 对象 planning
    cout << "coding time = "; // 输出 coding 时间
    coding.show(); // 调用 show() 函数显示 coding 时间

    cout << "fixing time = "; // 输出 fixing 时间
    fixing.show(); // 调用 show() 函数显示 fixing 时间

    total = coding.Sum(fixing); // 计算 coding 和 fixing 的总时间
    total.show(); // 显示总时间
    cout << "----------------Dividing----------------" << endl;
    total = coding + fixing; // 使用运算符重载计算总时间
    total.show(); // 显示总时间

    planning = coding.operator+(fixing); // 使用 operator+ 计算总时间
    planning.show(); // 显示总时间
    return 0;
}
