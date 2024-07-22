#include "iostream"  // 标准输入输出库
using namespace std;
#include "cctype"    // 字符处理库

/*
 * 知识点总结：
 * - 字符处理：使用 `cctype` 库中的函数处理字符大小写转换和数字检测。
 * - 控制流：使用 `while` 循环和 `if-else` 条件语句控制字符处理逻辑。
 *
 * 注意点：
 * - 使用 `cin.get(ch)` 获取单个字符输入。
 * - 检查输入字符是否为数字，跳过数字字符的处理。
 * - 将小写字母转换为大写，将大写字母转换为小写。
 * - 处理其他非字母字符，直接输出。
 */

int main()
{
    char ch;  // 存储用户输入的字符
    cout << "Please enter a character: ";  // 提示用户输入字符
    while (cin.get(ch) && ch != '@')  // 获取字符，遇到'@'终止循环
    {
        if (isdigit(ch))  // 判断字符是否为数字
            continue;  // 如果是数字，跳过此次循环
        else if (islower(ch))  // 判断字符是否为小写字母
            cout << (char)toupper(ch);  // 将小写字母转换为大写并输出
        else if (isupper(ch))  // 判断字符是否为大写字母
            cout << (char)tolower(ch);  // 将大写字母转换为小写并输出
        else
            cout << ch;  // 对于其他字符，直接输出
    }

    return 0;  // 返回0表示程序成功执行
}
