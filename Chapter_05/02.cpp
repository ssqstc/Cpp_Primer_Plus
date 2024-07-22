#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 表达式求值：
   - 赋值表达式：赋值运算符`=`会将右边的值赋给左边的变量，并返回这个值。
   - 比较表达式：比较运算符如`<`和`>`用于比较两个值，返回布尔值（0表示false，1表示true）。
2. `cout`输出布尔值：
   - 默认情况下，布尔值会被转换为整数输出（0表示false，1表示true）。
   - 使用`cout.setf(ios_base::boolalpha)`可以使`cout`输出布尔值的文字表示（true或false）。
*/

int main()
{
    int x;
    cout << "The expression x = 100 has the value: ";
    cout << (x = 100) << endl;  // 赋值表达式，输出100
    cout << "Now x = " << x << endl;  // 输出当前x的值，即100
    cout << "The expression x < 3 has the value: ";
    cout << (x < 3) << endl;  // 比较表达式，x < 3 返回false，即0
    cout << "The expression x > 3 has the value: ";
    cout << (x > 3) << endl;  // 比较表达式，x > 3 返回true，即1

    cout << "------------------------------------\n";
    cout.setf(ios_base::boolalpha);  // 设置`cout`以布尔值文字表示输出
    cout << "The expression x < 3 has the value: ";
    cout << (x < 3) << endl;  // 布尔值文字表示，输出false
    cout << "The expression x > 3 has the value: ";
    cout << (x > 3) << endl;  // 布尔值文字表示，输出true

    return 0;
}
