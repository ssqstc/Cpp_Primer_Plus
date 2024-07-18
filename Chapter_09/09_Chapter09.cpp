#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 静态局部变量：在函数中定义的静态局部变量在函数多次调用之间保持其值。
 * - 字符串处理：通过字符数组和指针进行字符串处理。
 * - 流操作：使用 `cin.get` 读取输入行。
 *
 * 注意点：
 * - 静态局部变量的生命周期和作用域。
 * - 字符数组的输入和处理方式。
 * - 循环和条件控制流的使用。
 * - 当输入流读取到一个空行（只有一个回车键，即\n），输入流状态将变为false
 */

const int ArSize = 10; // 定义常量 ArSize，表示字符数组的大小
void strcount(const char str[]); // 函数声明

int main(){
    char input[ArSize]; // 定义字符数组 input，用于存储输入行
    char next; // 定义字符变量 next，用于读取每个字符
    cout << "Enter a line: " << endl; // 提示输入一行字符
    cin.get(input, ArSize); // 读取输入行，最多读取 ArSize-1 个字符
    while (cin){ // 如果读取成功，进入循环 当输入流读取到一个空行（只有一个回车键，即\n），输入流状态将变为false
        cin.get(next); // 读取下一个字符
        while (next != '\n'){ // 如果不是换行符
            cin.get(next); // 继续读取字符，直到遇到换行符
        }
        strcount(input); // 调用 strcount 函数，统计并输出字符数
        cout << "Enter next line (empty line to quit): " << endl; // 提示输入下一行
        cin.get(input, ArSize); // 读取下一行输入
    }
    cout << "ByeBye" << endl; // 输出结束信息

    return 0;
}

void strcount(const char str[]){
    static int total = 0; // 静态局部变量 total，用于累积字符总数
    int count = 0; // 定义局部变量 count，用于统计当前输入行的字符数

    while (*str){ // 遍历字符串，直到遇到空字符
        count++; // 统计字符数
        str++; // 移动指针到下一个字符
    }
    total += count; // 累加到总字符数
    cout << count << " characters" << endl; // 输出当前输入行的字符数
    cout << total << " characters total" << endl; // 输出总字符数
}
