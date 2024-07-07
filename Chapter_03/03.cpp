#include <iostream>
using namespace std;

// 主函数，程序的入口点
int main()
{
    // 设置输出格式为固定小数点，以便后续浮点数输出时保持一致的精度
    cout.setf(ios_base::fixed, ios_base::floatfield);

    // 定义一个浮点数变量 tree，并赋值为 3.0
    float tree = 3;
    // 定义一个整数变量 guess，并尝试赋值为浮点数 3.9832
    // 由于类型强制转换，小数部分被截断，体现了浮点数到整数的精度损失
    int guess = 3.9832;
    // 定义一个整数变量 debt，并赋值为科学计数法表示的数 7.2E12
    // 这里展示了C++对科学计数法的支持，以及大数在编程中的表示方法
    int debt = 7.2E12;

    // 依次输出变量的值，演示了C++对不同类型数据的输出能力
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;

    // 程序正常结束
    return 0;
}
