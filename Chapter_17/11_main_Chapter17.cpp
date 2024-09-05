#include <iostream>
using namespace std;

/*
  知识点总结：
  1. `while(cin >> input)`：这是一个标准的输入循环，利用 `cin` 的返回值判断输入是否成功。输入成功时返回 true，输入无效时返回 false（如遇到非数字输入）。
  2. 输入流控制：当输入流遇到非数字或文件结束符（如 Ctrl+D）时，`cin` 会进入错误状态，循环结束。
  3. 输入后的值：循环结束后，`input` 变量仍保留最后一次输入的值。

  注意点：
  1. 当输入非数字（如字母或符号）时，`cin` 进入错误状态，输入循环结束。用户应确保输入为数字，否则需要处理输入错误。
  2. 最后输出的 `input` 值是错误输入之前的值，并不会存储导致 `cin` 错误的输入。
  3. 可以通过清除错误状态并忽略错误输入来增强输入的健壮性。
*/

int main() {
    cout << "Enter numbers: ";  // 提示用户输入

    int sum = 0;   // 存储所有输入数字的总和
    int input;     // 存储用户输入的数字
    while (cin >> input) {  // 不断读取输入直到发生错误
        sum += input;  // 累加输入的数字
    }

    // 输出最后一次成功输入的值和总和
    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}