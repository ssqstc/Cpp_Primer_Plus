#include "iostream"
using namespace std;
#include "cctype"  // 包含cctype库以使用字符处理函数

/*
 * 知识点总结和注意点：
 *
 * 1. 读取和分析字符：
 *    - 使用 `cin.get(ch)` 逐个读取字符，包括空格和特殊字符。
 *    - 使用 `isalpha(ch)` 判断是否为字母字符。
 *    - 使用 `isspace(ch)` 判断是否为空白字符（空格、换行等）。
 *    - 使用 `isdigit(ch)` 判断是否为数字字符。
 *    - 使用 `ispunct(ch)` 判断是否为标点符号。
 *
 * 2. 循环结束条件：
 *    - 当遇到字符 `@` 时结束循环。
 *
 * 3. 统计不同类型的字符：
 *    - 对不同类型的字符进行计数，并输出结果。
 *
 * 注意点：
 *
 * - 初始读取：
 *   - 在循环外先读取第一个字符，确保进入循环时 `ch` 已经初始化。
 *
 * - 循环条件：
 *   - 循环条件是 `ch != '@'`，确保遇到 `@` 时结束读取。
 *
 * - 使用 `cctype` 库：
 *   - 包含 `cctype` 头文件以使用字符分类函数。
 */

int main()
{
    int whitespace = 0; // 空白字符计数
    int digits = 0;     // 数字字符计数
    int chars = 0;      // 字母字符计数
    int punct = 0;      // 标点符号计数
    int others = 0;     // 其他字符计数

    char ch;

    cout << "Enter text for analysis, and type @ to terminate the input." << endl;
    cin.get(ch); // 读取第一个字符

    while (ch != '@') // 判断是否为'@'，如果是则结束循环
    {
        if (isalpha(ch)) // 判断是否为字母字符
            chars++; // 统计字母字符
        else if (isspace(ch)) // 判断是否为空白字符
            whitespace++; // 统计空白字符
        else if (isdigit(ch)) // 判断是否为数字字符
            digits++; // 统计数字字符
        else if (ispunct(ch)) // 判断是否为标点符号
            punct++; // 统计标点符号
        else
            others++; // 统计其他字符
        cin.get(ch); // 读取下一个字符
    }
    cout << chars << " letters, " << whitespace << " whitespace, " << digits << " digits, " << punct << " punct, " << others << " others." << endl; // 输出统计结果
    return 0;
}
