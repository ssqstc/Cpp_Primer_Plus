#include <iostream>  // 标准输入输出流库

/*
  知识点总结：
  1. `setf(ios_base::showpos)`：设置输出正数时显示正号 `+`。
  2. `hex`、`uppercase`、`showbase`：这些格式化标志用于输出16进制数字，`uppercase` 将字母显示为大写，`showbase` 添加数字前缀 `0x`。
  3. `boolalpha`：将布尔值以 `true` 或 `false` 的字符串形式输出，而不是默认的 `1` 或 `0`。

  注意点：
  1. `hex` 改变了整数的输出格式，从十进制变为十六进制。
  2. 在使用 `setf()` 改变格式时，注意格式设置的持久性，格式会保持到下一次显示操作。
  3. 布尔值格式化输出 `true` 和 `false` 时，使用了 `boolalpha` 进行文字形式的显示。

  代码结构：
  - 演示了不同的数据格式输出，包括正数符号、十六进制表示法、和布尔值的格式化输出。
*/

using namespace std;

int main() {
    int temperature = 63;  // 水的温度

    // 输出水温，设置显示正号
    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);  // 显示正号
    cout << temperature << endl;

    // 为编程爱好者显示十六进制格式
    cout << "For our programming friends, that's\n";
    cout << hex << temperature << endl;  // 转换为十六进制输出

    // 设置大写和显示基数前缀
    cout.setf(ios_base::uppercase);  // 将字母转为大写
    cout.setf(ios_base::showbase);  // 显示数字前缀
    cout << "or\n";
    cout << temperature << endl;  // 输出十六进制的水温

    // 输出布尔值
    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha);  // 布尔值显示为 true/false
    cout << true << "!\n";

    return 0;
}