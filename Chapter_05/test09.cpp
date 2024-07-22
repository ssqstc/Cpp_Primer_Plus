#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 使用 `string` 类型存储单词：
   - 相较于 `char` 数组，`string` 类型更为方便且安全。

2. 使用 `==` 比较字符串：
   - 直接使用 `==` 运算符比较两个 `string` 对象，返回 true 表示相等。
   - 循环中判断用户输入的单词是否为 "done"，如果是，则结束循环。

3. 输入和计数：
   - 使用 `cin` 输入单词。
   - 使用一个计数器 `count` 记录输入的单词数。

注意点：
- 输入和计数的顺序要正确，确保在输入完一个单词后再进行计数。
*/

int main()
{
    string word; // 存储用户输入的单词
    int count = 0; // 记录输入的单词数
    cout << "Enter words (to stop, type the word done):"; // 提示用户输入单词，输入done停止
    cin >> word; // 读取第一个单词
    while (word != "done") // 比较输入的单词是否为done
    {
        cin >> word; // 读取下一个单词
        count++; // 计数器加1
    }
    cout << "You entered a total of " << count << " words."; // 输出总共输入的单词数

    return 0; // 返回0表示程序正常结束
}
