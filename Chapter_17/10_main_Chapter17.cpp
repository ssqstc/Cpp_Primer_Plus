#include <iostream>
#include <iomanip>  // 包含控制输出格式的库
#include <cmath>    // 数学库，包含 sqrt 函数

/*
  知识点总结：
  1. `setw()`：设置输出字段的宽度，确保输出对齐。
  2. `setfill()`：设置填充字符，用于填充输出字段宽度不足的部分。
  3. `setprecision()`：设置浮点数的精度，控制小数点后数字的个数。
  4. `fixed` 和 `right`：控制浮点数格式为定点格式，并设置右对齐。

  注意点：
  1. 每次使用 `setw()` 设置的宽度只对一次输出有效，后续输出需要重新设置宽度。
  2. `setfill()` 可以设置填充字符，但需要在设置宽度后立即使用，否则可能不会生效。
  3. 在使用 `setprecision()` 设置精度时，配合 `fixed` 使用，确保浮点数输出格式统一。

  代码结构：
  - 演示了如何使用 `iomanip` 库中的函数控制输出格式，包括对齐、精度设置和填充字符等。
*/

using namespace std;

int main() {
    // 设置浮点数为定点格式，并且所有输出右对齐
    cout << fixed << right;

    // 输出表头，设置列宽和内容对齐
    cout << setw(6) << "N" << setw(14) << "square root" << setw(15) << "fourth root\n";

    double root;
    // 遍历数值，计算平方根和四次方根，并输出结果
    for (int i = 10; i <= 100; i += 10) {
        root = sqrt(double(i));  // 计算平方根

        // 设置输出格式，并输出数值及其平方根、四次方根
        cout << setw(6) << setfill('.') << i << setfill(' ')
             << setw(12) << setprecision(3) << root
             << setw(14) << setprecision(4) << sqrt(root) << endl;
    }

    return 0;
}