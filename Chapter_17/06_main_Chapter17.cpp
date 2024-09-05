#include <iostream>  // 标准输入输出流库

/*
  知识点总结：
  1. `cout.setf(ios_base::showpoint)`：确保浮点数以小数点形式显示，即使没有小数部分也会显示 `.0`。
  2. `cout.precision()`：设置浮点数的有效位数。当指定小数点后两位时，数字的显示格式将根据设定显示。

  注意点：
  1. `setf()` 设置的是浮点数的显示方式，确保输出始终包含小数点。
  2. `precision()` 设置的是显示的有效位数，不是直接设置小数位数。在设置了小数点显示后，`precision(2)` 使浮点数以保留小数点后两位的形式输出。

  代码结构：
  - 输出两次商品价格，第一次使用默认精度，第二次使用两位小数精度显示价格。
*/

using namespace std;

int main() {
    float price1 = 20.40;  // 商品1的价格
    float price2 = 1.9 + 8.0 / 9.0;  // 商品2的价格，包含浮点运算

    // 设置浮点数显示格式，确保显示小数点
    cout.setf(ios_base::showpoint);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";  // 输出商品1价格
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";  // 输出商品2价格

    // 设置浮点数精度为2位小数
    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";  // 输出商品1价格，保留2位小数
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";  // 输出商品2价格，保留2位小数

    return 0;
}