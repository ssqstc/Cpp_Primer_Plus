#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 使用 `string` 处理字符串：`string` 是 C++ 标准库中的字符串类，提供了丰富的字符串操作功能。
 * - 静态变量：`static` 关键字可以在函数内声明静态变量，静态变量在函数调用之间保持其值。
 * - `getline` 函数：用于从输入流中读取一行字符串，直到换行符。
 *
 * 注意点：
 * - 使用 `string::size()` 获取字符串的长度。
 * - `while` 循环用于不断读取用户输入，直到用户输入空行。
 * - 静态变量 `total` 用于累积字符总数。
 */

void strcount(const string str); // 函数声明：统计字符串字符数

int main(){
    string input; // 定义输入字符串
    cout << "Enter a line: " << endl; // 提示输入一行字符串
    getline(cin, input); // 读取输入的整行字符串
    while (input != ""){ // 当输入不为空时，继续处理
        strcount(input); // 统计并显示字符数
        cout << "Enter next line (empty space to quit): " << endl; // 提示输入下一行字符串
        getline(cin, input); // 读取下一行输入
    }
    cout << "ByeBye" << endl; // 输出结束信息

    return 0;
}

void strcount(const string str){ // 定义统计字符串字符数的函数
    static int total = 0; // 静态变量，用于累计所有输入的总字符数
    int count = 0; // 局部变量，用于存储当前输入字符串的字符数
    count = str.size(); // 获取当前字符串的字符数
    total += count; // 累加到总字符数
    cout << count << " characters" << endl; // 输出当前字符串的字符数
    cout << total << " characters total" << endl; // 输出累计的总字符数
}
