#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 数组：用于存储字符序列，处理输入的文本行。
 * - 循环与条件判断：遍历字符数组，统计空格数量，处理特定字符。
 * - cin.get()：读取整行文本，包括空格。
 * - 字符串处理：识别并处理特殊字符，如空格和句号。
 *
 * 注意点：
 * - 使用 const 关键字定义常量数组大小。
 * - cin.get() 函数读取包含空格的整行输入。
 * - for 循环遍历字符数组，处理到字符串结束符 '\0'。
 */

const int ArSize = 80; // 定义常量数组大小

int main()
{
    char line[ArSize]; // 定义字符数组
    int space_count = 0; // 初始化空格计数器
    cout << "Enter a line of text:" << endl; // 提示用户输入文本行
    cin.get(line, ArSize); // 读取整行文本
    cout << "Complete line: " << line << endl; // 输出完整的输入行

    // 遍历字符数组，处理每个字符
    for (int i = 0; line[i] != '\0'; ++i) {
        if ('.' == line[i]) // 如果遇到句号，停止处理
            break;
        cout << line[i]; // 输出当前字符
        if (' ' != line[i]) // 如果当前字符不是空格，跳过计数
            continue;
        space_count++; // 计数空格
    }

    cout << "spaces = " << space_count << endl; // 输出空格总数
    return 0;
}
