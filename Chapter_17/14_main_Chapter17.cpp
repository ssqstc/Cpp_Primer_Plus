#include <iostream>
using namespace std;
/*
  知识点总结：
  1. `cin.getline()`：读取输入直到遇到指定的分界字符（默认为换行符，但可指定其他字符），并丢弃分界字符。
  2. `cin.get()`：读取输入直到遇到分界字符，但不会丢弃该字符，下一次读取会继续从分界字符后开始。
  3. `cin.ignore()`：忽略输入流中的指定数量字符或直到遇到指定的分界字符。

  注意点：
  1. `cin.getline()` 丢弃分界符后，输入流可以继续读取，而 `cin.get()` 保留分界符。
  2. `cin.ignore()` 用于清除输入流中的缓冲区，避免下次读取时读取到多余字符。
*/

// 使用 cin.getline() 处理输入
const int Limit = 255;
int main() {
    char input[Limit];
    cout << "Enter a string for getline() processing: " << endl;
    cin.getline(input, Limit, '#'); // 读取直到遇到 '#'，并丢弃 '#'
    cout << "Here is your input: " << endl;
    cout << input << endl;

    cout << "----------------Dividing----------------" << endl;

    // 使用 cin.get() 读取单个字符
    char ch;
    cin.get(ch);  // 读取下一个字符，不丢弃
    cout << "The next input character is: " << ch << endl;

    // 使用 cin.ignore() 忽略输入缓冲区中的字符
    cin.ignore(Limit, '\n');  // 忽略直到换行符

    cout << "----------------Dividing----------------" << endl;

    // 使用 cin.get() 处理输入
    cout << "Enter a string for get() processing " << endl;
    cin.get(input, Limit, '#'); // 读取直到遇到 '#'，不丢弃分界符
    cout << "Here is your input: " << endl;
    cout << input << endl;

    // 再次使用 cin.get() 读取下一个字符
    cin.get(ch);
    cout << "The next input character is: " << ch << endl;

    return 0;
}