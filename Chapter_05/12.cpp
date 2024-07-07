#include "iostream"
using namespace std;
/*
 * 1.cin >> char[] 读取字符串
 * cin在读取字符串时会跳过前导的空白字符（空格、制表符、换行符等）
 * 然后读取一系列字符，直到遇到下一个空白字符为止。
 * 空白字符本身不会被读取到字符串中，而是会被保留在输入缓冲区中，以便后续的读取操作。
 * 2.cin >> char 读取单个字符
 * cin在读取单个字符时会跳过所有空白字符，直接读取下一个非空白字符。
 * 3.cin.get()
 * 从输入流中读取一个字符，包括空白字符（如空格、制表符和换行符）。
 * 4.cin.getline()
 * 从输入流中读取一行字符，包括空白字符，直到遇到换行符或指定的最大字符数。换行符会被丢弃，但不会存储到目标数组中。
 * 5.std::getline()
 * 从输入流中读取一行字符，包括空白字符，直到遇到换行符。换行符会被丢弃，但不会存储到目标字符串中。
 * 6.cin.get(char* buffer, int size)
 * 从输入流中读取字符，包括空白字符，直到读取了 size - 1 个字符，遇到换行符或到达文件末尾。
 * 与 cin.getline 不同的是，换行符会保留在输入流中。
 * 7.cin.ignore()
 * 从输入流中忽略指定数量的字符，或者忽略直到指定的终止字符（默认为换行符）为止。
 */

int main()
{
    char ch;
    int count = 0;
    cout << "Enter characters, enter # to quit: " << endl;
    cin.get(ch);
    while (ch != '#')
    {
        cout << ch;
        count++;
        cin.get(ch);
    }
    cout << endl;
    cout << count << " characters read" << endl;
    return 0;
}