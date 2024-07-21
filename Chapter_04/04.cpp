#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - `cin`的使用：从标准输入中读取数据。
 * - `cin.get()`：读取并丢弃一个字符，用于清除换行符。
 * - `cin.getline()`：从输入流中读取一行字符，直到换行符或达到指定字符数为止。
 * - 字符数组：用于存储字符串输入。
 *
 * 注意点：
 * - 在读取整型数据后，使用`cin.get()`清除缓冲区中的换行符，防止影响后续字符串输入。
 */

/*
 * 主函数：处理用户输入的房屋建造年份和地址，并进行相关输出
 */
int main()
{
    // 提示用户输入房屋建造年份
    cout << "What year was your house built?\n";
    int year;
    cin >> year; // 读取用户输入的年份

    // 提示用户输入房屋地址
    cout << "What is its street address?\n";
    char address[80]; // 用于存储用户输入的地址
    cin.get();  // 清除缓冲区中的换行符
    cin.getline(address, 80); // 读取用户输入的地址

    // 输出用户输入的信息
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done\n";

    return 0;
}
