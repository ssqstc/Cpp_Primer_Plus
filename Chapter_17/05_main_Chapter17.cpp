#include <iostream>  // 标准输入输出流库

/*
  知识点总结：
  1. `cout.fill()`：用于设置填充字符，填充字符用于当输出内容长度不足指定宽度时补齐。
  2. `cout.width()`：设置下一个输出操作的最小字段宽度。如果输出内容长度不足宽度，则使用填充字符补齐。

  注意点：
  1. `cout.fill()` 只影响使用 `width()` 设置的输出宽度填充，并且只在当前设置的字段宽度大于输出内容长度时起作用。
  2. `cout.width()` 仅影响紧接着的输出操作，之后会自动恢复默认宽度。
  3. 数组的定义：`staff` 和 `bonus` 数组分别存储员工姓名和奖金。

  代码结构：
  - 使用循环遍历数组，输出员工姓名及其奖金，奖金不足7位时由'*'字符填充。
*/

using namespace std;

int main() {
    cout.fill('*');  // 设置填充字符为 '*'，用于不足宽度时填充

    // 定义员工姓名和奖金的数组
    const char *staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
    long bonus[2] = { 900, 1350 };

    // 循环输出员工姓名和奖金
    for (int i = 0; i < 2; ++i) {
        cout << staff[i] << ": $";  // 输出员工姓名及前缀
        cout.width(7);  // 设置下一个输出字段的最小宽度为7
        cout << bonus[i] << "\n";  // 输出奖金，若长度不足则用 '*' 填充
    }

    return 0;
}