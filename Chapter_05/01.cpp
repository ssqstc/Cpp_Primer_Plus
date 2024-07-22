#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. `for`循环：
   - 用于循环执行一段代码，直到条件不再满足。
   - 在循环中可以对循环变量进行递减操作。
2. 输入输出操作：
   - 使用`cin`读取用户输入。
   - 使用`cout`输出结果。
3. 循环变量作用域：
   - 循环变量在循环结束后依然可以被访问，并保持其最后的值。
*/

int main()
{
    cout << "Enter the starting countdown value: ";  // 提示用户输入倒计时起始值
    int limit;  // 定义变量用于存储用户输入的起始值
    cin >> limit;  // 读取用户输入

    int i;  // 定义循环变量
    for (i = limit; i; i--) {  // 从limit开始倒计时，直到i为0时循环结束
        cout << "i = " << i << endl;  // 输出当前的倒计时值
    }

    cout << "Done, now that i = " << i << endl;  // 循环结束后输出最终的i值
    return 0;  // 程序结束
}
