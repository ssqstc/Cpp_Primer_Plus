#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 嵌套循环：
   - 外层循环用于控制行数。
   - 内层循环用于控制每行的输出模式。

2. 控制输出格式：
   - 每行先输出相应数量的点号（'.'）。
   - 然后输出相应数量的星号（'*'）。

3. 用户输入：
   - 提示用户输入要打印的行数。
   - 根据输入值进行相应的循环操作。

注意点：
- 输入值 `count` 决定外层循环的次数。
- 确保内层循环的逻辑正确，输出点号和星号的数量要符合要求。
*/

int main()
{
    cout << "Enter number of rows: "; // 提示用户输入行数
    int count;
    cin >> count; // 读取用户输入的行数

    for (int i = 1; i <= count; ++i) { // 外层循环，控制行数
        for (int j = count - i; j > 0; --j) { // 内层循环，输出点号
            cout << ".";
        }
        for (int j = 0; j < i; ++j) { // 内层循环，输出星号
            cout << "*";
        }
        cout << endl; // 每行结束后换行
    }

    return 0; // 返回0表示程序正常结束
}
