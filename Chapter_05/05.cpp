#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. `string`类的使用：
   - `string`类是C++标准库中的字符串类，可以方便地进行字符串操作。
2. 反向遍历字符串：
   - 通过`string`类的`size()`方法获取字符串长度，然后从末尾向前遍历。

注意点：
- 字符串输入：确保输入的字符串有效且没有空格，因为`cin`在遇到空格时会停止读取。
- 反向索引：从字符串末尾开始，索引从`size() - 1`到`0`。

*/

int main()
{
    cout << "Enter a word: ";  // 提示用户输入一个单词
    string word;
    cin >> word;  // 读取用户输入的单词

    // 反向遍历并输出单词
    for (int i = word.size() - 1; i >= 0; i--) {
        cout << word[i];  // 输出单词的每个字符，从后向前
    }

    return 0;
}
