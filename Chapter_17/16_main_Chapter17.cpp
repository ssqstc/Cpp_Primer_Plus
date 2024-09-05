/*
知识点：
1. `cin.get(char*, int)` 用于从输入流中读取指定长度的字符串，避免溢出。
2. `cin.peek()` 用来检查下一个字符，但不会从输入流中移除该字符。
3. `isspace()` 用来判断字符是否为空白字符，包括空格、换行符等。
4. 使用 `while(cin.get() != '\n')` 清空输入缓冲区中剩余的字符，确保输入流的状态正确。

注意点：
1. 使用 `cin.get()` 时，输入的字符串长度应小于指定的数组大小以防止溢出。
2. 如果输入的字符数超过限制，需要手动清空输入缓冲区，避免影响后续输入操作。
3. 使用 `isspace()` 来跳过多余的空白字符，避免用户输入不规范时程序行为异常。
*/

#include <iostream> // 包含标准输入输出库
using namespace std; // 使用标准命名空间

const int SLEN = 10; // 常量定义，用于限制输入字符的长度
int main() {
    char name[SLEN]; // 用于存储用户输入的名字
    char title[SLEN]; // 用于存储用户输入的头衔

    cout << "Enter your name: "; // 提示用户输入名字
    cin.get(name, SLEN); // 从输入中读取最多 SLEN-1 个字符存入 name 数组，留出 '\0' 结束符空间

    // 如果输入的字符数超过限制，缓冲区中会残留未读取的字符
    if (cin.peek() != '\n') { // 检查下一个字符是否为换行符
        cout << "Sorry, we don't have enough room for " << name << endl; // 如果不是，表示输入的名字过长
    }

    // 清除缓冲区中的多余字符直到空白字符（如换行符）
    while (!isspace(cin.get())); // 使用 isspace() 跳过空白字符

    // 提示用户输入头衔
    cout << "Dear " << name << ", enter your title: "; // 使用已输入的名字进行提示
    cin.get(title, SLEN); // 读取用户输入的头衔，最多 SLEN-1 个字符

    // 检查头衔输入是否超过限制
    if (cin.peek() != '\n') { // 如果输入的头衔超过了限制
        cout << "We were forced to truncate your title." << endl; // 提示用户头衔被截断
    }

    // 清空输入缓冲区中的剩余字符直到遇到换行符
    while (cin.get() != '\n'); // 丢弃直到遇到换行符的所有输入

    // 输出用户的名字和头衔
    cout << "Name: " << name << endl; // 输出用户的名字
    cout << "Title: " << title << endl; // 输出用户的头衔

    return 0; // 程序结束，返回 0 表示成功
}