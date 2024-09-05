/*
知识点：
1. `cin.get()` 和 `cin.peek()` 是C++标准输入流中的成员函数，分别用于从输入流中读取字符和窥视下一个字符。
2. `cin.putback()` 可以将字符放回输入流，从而使得下次读取时重新读取该字符。
3. `cin.eof()` 用于检查是否到达输入流的末尾 (EOF)。
4. `exit(0)` 用来立即终止程序，通常用于异常情况下的程序退出。

注意点：
1. `cin.get(ch)` 的返回值可以用于判断输入是否成功，并处理输入流中的单个字符。
2. 当使用 `cin.peek()` 或 `cin.putback()` 时，要确保输入流的状态良好，否则可能导致意外行为。
3. 注意 `cin.eof()` 的使用，在到达输入流末尾时需要正确处理以避免程序崩溃。
*/

#include <iostream> // 包含标准输入输出库
using namespace std; // 使用标准命名空间

int main() {
    char ch; // 定义字符变量用于存储输入字符
    // 通过 cin.get(ch) 不断读取输入的字符，直到遇到 '#' 字符
    while (cin.get(ch)) { // 读取输入流中的字符并存入 ch
        if (ch != '#') { // 判断字符是否为 '#'，如果不是则输出字符
            cout << ch; // 输出读取到的字符
        } else { // 如果遇到 '#' 字符
            cin.putback(ch); // 将 '#' 放回输入流中
            break; // 终止循环
        }
    }
    cout << endl; // 输出换行符

    // 检查是否已到达输入的末尾
    if (!cin.eof()) { // 如果未到达输入流末尾
        cin.get(ch); // 再次读取一个字符
        cout << ch << " is next input character." << endl; // 输出接下来的字符
    } else { // 如果到达了输入流末尾
        cout << "End of input reached. " << endl; // 输出结束信息
        exit(0); // 终止程序
    }

    // 使用 peek 函数查看下一个字符，直到遇到 '#' 为止
    while (cin.peek() != '#') { // 当下一个字符不是 '#' 时
        cin.get(ch); // 读取字符
        cout << ch; // 输出字符
    }
    cout << endl; // 输出换行符

    // 再次检查是否已到达输入末尾
    if (!cin.eof()) { // 如果未到达输入流末尾
        cin.get(ch); // 再次读取一个字符
        cout << ch << " is next input character." << endl; // 输出接下来的字符
    } else { // 如果到达了输入流末尾
        cout << "End of input reached. " << endl; // 输出结束信息
        exit(0); // 终止程序
    }

    return 0; // 程序正常结束
}