#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 字符输入和输出：
   - 使用 `cin.get(ch)` 逐个字符读取输入，适用于处理空格、换行符等特殊字符。
   - 使用 `cout` 输出字符。

2. 计数器：
   - 使用计数器统计输入的字符数。

3. 循环控制和错误检测：
   - 使用 `while` 循环，并结合 `cin.fail()` 方法，当输入流状态正常时继续循环。
   - `cin.fail()` 在输入流发生错误时返回 true。

注意点：
- `cin.get(ch)` 可以读取包括空格和换行符在内的所有字符。
- 使用 `cin.fail()` 监控输入流状态以确保正确读取字符。
- 当输入达到文件结束符（EOF）或发生其他错误时，`cin.fail()` 返回 true，退出循环。
*/

int main()
{
    char ch;                     // 定义字符变量ch，用于存储用户输入的字符
    int count = 0;               // 初始化计数器，用于统计输入的字符数

    cout << "Enter characters, enter # to quit: " << endl; // 提示用户输入字符，输入#结束
    cin.get(ch);                 // 获取用户输入的第一个字符

    while (cin.fail() == false)  // 当输入流状态正常时继续循环
    {
        cout << ch;              // 输出输入的字符
        count++;                 // 字符计数器加1
        cin.get(ch);             // 获取下一个输入的字符
    }

    cout << endl;
    cout << count << " characters read" << endl; // 输出总共输入的字符数

    return 0;                   // 返回0表示程序正常结束
}
