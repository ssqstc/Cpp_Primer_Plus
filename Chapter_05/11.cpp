#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 循环结构：
   - `while`循环：适用于先判断条件再执行循环体的情况。
   - `do-while`循环：适用于先执行一次循环体再判断条件的情况，至少执行一次。

2. 输入校验：
   - 使用循环获取用户输入，直到满足特定条件。
   - 在本例中，用户需要输入1到10之间的数字，直到输入的数字为6。

注意点：
- `do-while`循环保证至少执行一次循环体。
- 注意避免无限循环，确保循环条件能在合理范围内被满足。
*/

int main()
{
    int n;
    cout << "Enter numbers in the range 1~10 to find my favorite number: "; // 提示用户输入数字

    // 使用do-while循环确保循环体至少执行一次
    do {
        cin >> n; // 获取用户输入的数字
    } while (n != 6); // 当输入的数字不是6时继续循环

    cout << "That's my favorite number!\n"; // 输入为6时，输出提示信息

    return 0; // 返回0表示程序正常结束
}
