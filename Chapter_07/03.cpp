#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - while 循环：用于反复执行代码块，直到条件为假。
 * - 函数调用：如何在主函数中调用用户定义的函数。
 * - 基本输入输出：使用 cin 和 cout 进行输入输出操作。

 * 注意点：
 * - 确保循环条件正确，避免死循环。
 * - 注意变量的初始值和作用范围。
 * - 在使用输入流时，要确保输入的有效性。
 */

/*
 * n_chars 函数：输出指定次数的字符
 * - 参数：c（要输出的字符），n（输出的次数）
 */
void n_chars(char c, int n);

/*
 * 主函数：演示输入字符和次数，并调用 n_chars 函数输出字符
 * - 获取用户输入的字符和次数
 * - 使用 while 循环反复获取输入，直到用户输入 'q'
 */
int main() {
    char ch;
    int times;

    cout << "Enter a character: "; // 提示用户输入一个字符
    cin >> ch;

    while ('q' != ch) { // 循环直到用户输入 'q'
        cout << "Enter an integer:"; // 提示用户输入一个整数
        cin >> times;

        n_chars(ch, times); // 调用 n_chars 函数输出字符

        // cout << "\ntimes = " << times << endl; // 输出次数，调试用

        cout << endl;
        cout << "Enter another character or press 'q' to quit:" << endl; // 提示用户再次输入字符或退出
        cin >> ch;
    }

    return 0;
}

void n_chars(char c, int n) {
    while (--n >= 0) { // 循环输出指定次数的字符，确保至少输出一次
        cout << c;
    }
}
