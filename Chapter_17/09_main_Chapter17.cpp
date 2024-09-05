#include <iostream>  // 标准输入输出流库
#include <cmath>     // 数学库，包含 sqrt 函数

/*
  知识点总结：
  1. `setf()`：用于设置流的格式化标志，包括对齐方式（左、右、内部对齐）、浮点数格式（科学计数法、固定小数点）等。
  2. `precision()`：设置浮点数的精度，控制小数点后数字的个数。
  3. `width()`：设置输出字段的宽度，确保输出的对齐。
  4. `cout.setf()` 和 `cout.unsetf()`：用于设置和恢复流的格式化标志。

  注意点：
  1. `ios_base::left`、`ios_base::internal`、`ios_base::right`：控制输出对齐方式，分别为左对齐、符号与数值内部对齐、右对齐。
  2. `ios_base::scientific` 和 `ios_base::fixed`：分别用于设置科学计数法和定点格式显示浮点数。
  3. 在每次设置格式标志时，注意保留原有设置，以便之后还原格式，避免影响后续输出。

  代码结构：
  - 演示了如何设置不同的对齐方式和浮点数输出格式，结合对齐和精度展示平方根的输出。
*/

using namespace std;

int main() {
    // 设置左对齐、显示正号、显示小数点
    cout.setf(ios_base::left, ios_base::adjustfield);   // 左对齐
    cout.setf(ios_base::showpos);                      // 显示正号
    cout.setf(ios_base::showpoint);                    // 显示小数点
    cout.precision(3);                                 // 设置浮点数精度为3位小数

    // 设置科学计数法显示浮点数并保存旧格式设置
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "Left Justification:\n";

    // 输出左对齐格式的数值及其平方根
    for (int i = 1; i <= 41; i += 10) {
        cout.width(4);                                 // 设置输出宽度为4
        cout << i << "|";                              // 输出整数
        cout.width(12);                                // 设置输出宽度为12
        cout << sqrt(double(i)) << "|\n";              // 输出该整数的平方根
    }

    // 恢复浮点数格式，设置内部对齐
    cout.setf(ios_base::internal, ios_base::adjustfield);
    cout.setf(old, ios_base::floatfield);               // 恢复原浮点数格式

    cout << "Internal Justification:\n";
    // 输出符号内部对齐格式的数值及其平方根
    for (int i = 1; i <= 41; i += 10) {
        cout.width(4);
        cout << i << "|";
        cout.width(12);
        cout << sqrt(double(i)) << "|\n";
    }

    // 设置右对齐并使用定点格式显示浮点数
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Right Justification:\n";
    // 输出右对齐格式的数值及其平方根
    for (int i = 1; i <= 41; i += 10) {
        cout.width(4);
        cout << i << "|";
        cout.width(12);
        cout << sqrt(double(i)) << "|\n";
    }

    return 0;
}