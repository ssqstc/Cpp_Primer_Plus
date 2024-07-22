#include "iostream"
using namespace std;
#include "fstream"
#include "cstdlib"

/*
 * 知识点总结：
 * - 使用 `ifstream` 类打开和读取文件。
 * - 文件读取可以通过 `inFile.get(ch)` 实现逐字符读取。
 * - 使用 `eof()` 检测文件结束，但 `while (inFile.get(ch))` 是更好的选择。
 * - 文件打开失败时，使用 `exit(EXIT_FAILURE)` 处理错误。
 *
 * 注意点：
 * - 检查文件是否成功打开并处理错误。
 * - 使用 `while (inFile.get(ch))` 读取字符，避免 `while (!inFile.eof())` 的潜在问题。
 */

int main()
{
    char ch;
    int count = 0;

    ifstream inFile;
    inFile.open("test08.txt");  // 打开文件

    if (!inFile.is_open())  // 检查文件是否成功打开
    {
        cout << "文件未能正常打开" << endl;
        exit(EXIT_FAILURE);
    }

    // 使用 inFile.get(ch) 读取每个字符，直到文件结束
    while (inFile.get(ch))
    {
        ++count;
    }

    cout << "文件包含" << count << "个字符" << endl;  // 输出字符总数

    inFile.close();  // 关闭文件

    return 0;
}
