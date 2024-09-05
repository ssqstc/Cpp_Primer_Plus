#include <iostream>  // 标准输入输出流库

/*
  知识点总结：
  1. `cin` 和 `cout`：用于从标准输入读取数据和向标准输出打印数据。
  2. `cout` 的格式控制：可以使用 `hex`、`oct`、`dec` 来控制输出数据的进制格式。
     - `hex`：将输出设置为十六进制格式。
     - `oct`：将输出设置为八进制格式。
     - `dec`：将输出设置为十进制格式。
  3. 格式转换的持久性：一旦设置了 `hex` 或 `oct`，后续的所有输出都会采用该进制，直到显式更改。

  注意点：
  1. 在改变输出格式后，要确保在需要时恢复到十进制格式，以避免影响后续的输出。
  2. 使用制表符 `\t` 来对齐输出时，需注意字符长度差异可能导致的对齐偏差。
*/

using namespace std;

int main() {
    cout << "Enter an integer: ";  // 提示用户输入一个整数
    int n;
    cin >> n;  // 从标准输入读取整数

    cout << "n\t\tn*n\n";  // 输出表头
    cout << n << "\t\t" << n * n << " (decimal)\n";  // 以十进制输出 n 和 n 的平方

    cout << hex;  // 设置为十六进制格式
    cout << n << "\t\t" << n * n << " (hexadecimal)\n";  // 以十六进制输出 n 和 n 的平方

    cout << oct;  // 设置为八进制格式
    cout << n << "\t\t" << n * n << " (octal)\n";  // 以八进制输出 n 和 n 的平方

    cout << dec;  // 恢复为十进制格式
    cout << n << "\t\t" << n * n << " (decimal)\n";  // 再次以十进制输出 n 和 n 的平方

    return 0;
}