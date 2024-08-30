#include <iostream>
#include <string>
#include <algorithm> // 包含 reverse 函数的头文件

using namespace std;

/*
 * 知识点总结：
 * 1. 字符串操作：通过`reverse`函数可以将字符串倒置，常用于对比字符串的正序和倒序。
 * 2. 常量引用（const reference）：在函数参数中使用常量引用可以避免不必要的拷贝，提高效率。
 * 3. 条件运算符（?:）：简化条件判断的输出操作，将条件判断结果直接用于输出。
 *
 * 注意点：
 * 1. `reverse` 函数直接在原字符串上进行反转操作，因此需要先创建副本以避免修改原字符串。
 * 2. 在 `cin` 读取字符串时，只会读取第一个空格前的内容。如果要读取包含空格的字符串，应使用 `getline`。
 * 3. 条件运算符用于输出时，应注意运算结果是布尔值，避免逻辑错误。
 */

bool isPalindrome(const string& str) {
    string temp = str; // 创建字符串副本，以避免修改原字符串
    reverse(temp.begin(), temp.end()); // 倒置字符串
    return temp == str; // 比较倒置后的字符串与原字符串是否相等
}

int main() {
    string words;
    cout << "Enter a word: "; // 提示用户输入单词
    cin >> words; // 读取输入字符串
    isPalindrome(words) ? cout << "Palindrome" : cout << "Not palindrome"; // 输出是否为回文
    return 0;
}