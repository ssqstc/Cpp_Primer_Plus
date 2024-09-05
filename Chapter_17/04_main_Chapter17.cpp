#include <iostream>  // 标准输入输出流库

/*
  知识点总结：
  1. `cout.width()`：设置输出字段的宽度。此设置只对下一个输出有效，之后会自动恢复默认宽度。
  2. `cout` 的返回值：`cout.width()` 返回上一次设置的字段宽度。
  3. 循环结构：通过循环控制不同数字的输出格式，观察宽度设置的效果。

  注意点：
  1. `cout.width()` 只影响紧随其后的输出操作。
  2. 设置的宽度若小于输出内容的实际长度，则内容会超出指定宽度。
*/

using namespace std;

int main() {
    // 设置并获取默认的字段宽度，通常为 0
    int w = cout.width(30);
    cout << "default field width = " << w << ":\n";  // 输出默认字段宽度

    // 设置输出字段宽度为5，然后为下一次输出设置字段宽度为8
    cout.width(5);
    cout << "N" << ':';  // 输出 "N"，并指定字段宽度为5
    cout.width(8);
    cout << "N * N" << ":\n";  // 输出 "N * N"，并指定字段宽度为8

    // 使用循环输出不同数值及其平方的格式
    for (long i = 1; i <= 100; i *= 10) {
        cout.width(5);
        cout << i << ':';  // 输出数值 i，并指定字段宽度为5
        cout.width(8);
        cout << i * i << ":\n";  // 输出 i 的平方，并指定字段宽度为8
    }

    return 0;
}