#include <iostream>
#include <string>
#include <algorithm> // 包含 isalpha 和 tolower 函数的头文件

using namespace std;

/*
 * 知识点总结：
 * 1. 字符处理：`isalpha` 函数用于检查字符是否为字母，`tolower` 函数将字母转换为小写。
 * 2. 回文检测算法：通过双指针法同时从字符串两端向中间移动，逐一比较字符。
 * 3. 标准输入 `getline`：用于读取包含空格的整行字符串，而非只读到空格前的部分。
 *
 * 注意点：
 * 1. 字符串预处理：在判断回文之前，需要将字符串中的字母字符提取并转换为小写，以忽略大小写和非字母字符的影响。
 * 2. `getline` 读取字符串时要注意缓冲区问题，在连续读取多行输入时，需要处理可能残留的换行符。
 * 3. 在循环中使用索引时，要注意数组（字符串）边界，避免越界访问。
 */

bool isPalindrome(const string& str) {
    string temp;
    for (int i = 0; i < str.size(); ++i) {
        // 遍历字符串，将字母字符转换为小写并添加到临时字符串
        if (isalpha(str[i])) {
            temp += tolower(str[i]); // 转换为小写字母
        }
    }

    int first = 0; // 从左边开始的索引
    int last = temp.size() - 1; // 从右边开始的索引

    // 使用双指针法比较字符串两端的字符
    while (first < last) {
        if (temp[first] != temp[last]) {
            return false; // 如果任意一对字符不匹配，则不是回文
        }
        first++; // 移动左指针
        last--; // 移动右指针
    }
    return true; // 如果所有字符都匹配，则是回文
}

int main() {
    string words;
    cout << "Enter a words: ";
    getline(cin, words); // 使用getline读取整行输入
    if (isPalindrome(words)) {
        cout << "Palindrome"; // 输出回文信息
    } else {
        cout << "Not palindrome"; // 输出非回文信息
    }
    return 0;
}