#include "iostream"
using namespace std;
#include "cstring" // 包含C字符串处理函数库

/*
 * 知识点总结：
 * - C风格字符串的使用：包括字符串输入输出和字符串函数（如`strlen`和`sizeof`）。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 字符数组：定义字符数组并使用其存储和操作字符串。
 *
 * 注意点：
 * - `cin`读取字符串时，遇到空格会停止读取，可以使用`cin.getline`读取整行输入。
 * - `sizeof`用于获取数组占用的字节数，而`strlen`用于获取字符串的长度（不包括终止符`'\0'`）。
 */

/*
 * 主函数：处理用户输入的姓名并进行相关操作
 */
int main()
{
    const int Size = 15; // 字符数组大小常量
    char name1[Size]; // 用于存储用户输入的姓名
    char name2[Size] = "ssqstc"; // 初始化字符数组

    // 输出初始问候
    cout << "Hello I'm " << name2; // 输出name2
    cout << " What's your name?\n"; // 提示用户输入姓名

    // 读取用户输入的姓名
    cin >> name1;

    // 输出用户姓名的相关信息
    cout << "Well, " << name1 << " , your name has " << strlen(name1) << " letters and is stored \n"; // 输出姓名长度
    cout << "And your name is stored in an array of " << sizeof name1 << " bytes" << endl; // 输出字符数组大小

    return 0;
}
