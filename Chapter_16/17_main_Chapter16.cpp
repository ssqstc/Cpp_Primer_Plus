/*
知识点总结：
1. `sort` 和 `next_permutation`：`sort` 函数用于对字符串中的字符进行升序排序；`next_permutation` 函数用于生成字符串的下一个字典序排列。通过这两个函数，可以输出给定字符串的所有排列组合。
2. `string` 类：`string` 是 C++ 标准库中的一个类，用于处理字符串。它提供了丰富的成员函数用于字符串的操作。
3. `while` 循环和输入流控制：通过 `while` 循环和 `cin`，程序能够持续读取用户输入，直到用户输入 "quit" 为止。

注意点：
1. 在使用 `next_permutation` 前需要对字符串进行排序，以确保生成的排列组合是从字典序的第一个排列开始。
2. `next_permutation` 返回 `false` 时，表示已经生成了所有可能的排列组合。
3. 用户输入 "quit" 后，程序将结束执行。这是通过循环条件控制实现的。
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string letters;  // 用于存储用户输入的字母组合
    cout << "Enter the letter group (enter quit to quit): ";  // 提示用户输入字母组合

    // 持续读取用户输入，直到输入 "quit"
    while (cin >> letters && letters != "quit") {
        cout << "Permutation: " << endl;

        // 对输入的字母组合进行排序，以生成字典序的排列
        sort(letters.begin(), letters.end());
        cout << letters << endl;  // 输出初始排序后的字母组合

        // 使用 next_permutation 生成并输出下一个字典序排列
        while (next_permutation(letters.begin(), letters.end())) {
            cout << letters << endl;
        }

        // 提示用户输入下一个字母组合
        cout << "Enter the next letter group (enter quit to quit): ";
    }

    return 0;  // 程序结束，返回0
}