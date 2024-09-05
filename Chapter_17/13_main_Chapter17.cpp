#include <iostream>
using namespace std;

/*
  知识点总结：
  1. `cin.get(ch)`：用于读取输入流中的字符，包括空白字符（如空格、换行符）。
  2. `cin >> ch2`：跳过空白字符，仅读取非空白字符。此操作对于处理文本输入时，常用于忽略空格和换行符。
  3. 使用 `while` 循环进行字符输入和计数，是处理逐字符输入的一种常见方法。

  注意点：
  1. 当使用 `cin >> ch2` 时，换行符等空白字符不会被捕获，因此 `while` 循环不会捕获换行符，可能导致不期望的结果。
  2. `cin.get()` 会捕获每一个输入字符，包括空格和换行符，适合处理逐字符输入。
*/

int main() {
    // 使用 cin.get() 捕获任何字符
    char ch;
    int ct = 0;
    cin.get(ch); // 捕获第一个字符
    while (ch != '\n') {  // 当字符不是换行符时，继续捕获
        cout << ch;  // 输出捕获的字符
        ct++;        // 计数
        cin.get(ch); // 继续捕获下一个字符
    }
    cout << endl << ct << endl; // 输出字符数

    cout << "----------------Dividing----------------" << endl;

    // 使用 cin >> ch2 跳过空白字符
    char ch2;
    int ct2 = 0;
    cin >> ch2;  // 捕获第一个非空白字符
    while (ch2 != '\n') {  // 跳过空白字符并捕获
        cout << ch2;   // 输出非空白字符
        ct2++;         // 计数
        cin >> ch2;    // 捕获下一个非空白字符
    }
    cout << endl << ct2 << endl; // 输出非空白字符的数量

    return 0;
}