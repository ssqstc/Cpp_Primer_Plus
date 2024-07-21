#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 字符数组与字符串对象：`char[]`和`string`的区别及使用。
 * - 输入与输出：`cin`和`cout`的基本用法。
 * - 字符串下标访问：通过下标访问字符串中的字符。
 *
 * 注意点：
 * - `cin`读取字符串时，遇到空白字符会停止读取。
 */

/*
 * 主函数：处理用户输入的两种猫科动物，并输出相关信息
 */
int main()
{
    // 定义字符数组和字符串对象
    char charr1[20]; // 未初始化的字符数组
    char charr2[20] = "jaguar"; // 初始化为"jaguar"的字符数组
    string str1; // 未初始化的字符串对象
    string str2 = "panther"; // 初始化为"panther"的字符串对象

    // 提示用户输入一种猫科动物并读取输入
    cout << "Enter a kind of feline: ";
    cin >> charr1; // 读取用户输入的字符数组

    // 提示用户输入另一种猫科动物并读取输入
    cout << "Enter another kind of feline: ";
    cin >> str1; // 读取用户输入的字符串对象

    // 输出用户输入的猫科动物和预定义的猫科动物
    cout << "Here are some felines:\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

    // 输出字符数组和字符串对象中的第三个字符
    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;

    return 0;
}
