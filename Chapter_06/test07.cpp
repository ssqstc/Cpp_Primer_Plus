#include "iostream"
#include "cctype"
using namespace std;

/*
 * 知识点总结：
 * - 使用 `string` 类处理字符串输入。
 * - 使用 `isalpha` 函数判断字符是否为字母。
 * - 使用 `switch` 语句处理多个条件判断。
 * - 统计字符串的不同类别（以元音字母开头的单词、以辅音字母开头的单词、其他情况）。

 * 注意点：
 * - 输入验证：确保读取的字符串是否为字母开头。
 * - 循环控制：正确处理用户输入的多个单词，并在遇到 'q' 时退出。
 */

int main()
{
    string word;  // 存储用户输入的单词
    int vowels_count = 0, consonants_count = 0, count = 0;  // 统计元音字母、辅音字母和其他单词数量

    cout << "Enter words (q to quit):";  // 提示用户输入单词
    while (cin >> word && word != "q")  // 循环读取用户输入，直到遇到 "q"
    {
        ++count;  // 总单词数增加
        if (isalpha(word[0]))  // 判断单词的第一个字符是否为字母
        {
            switch (word[0]) {  // 根据单词的第一个字母进行分类
                case 'a': case 'e':
                case 'i': case 'o':
                case 'u': case 'A':
                case 'E': case 'I':
                case 'O': case 'U':
                    ++vowels_count;  // 如果是元音字母，增加元音字母计数
                    break;
                default:
                    ++consonants_count;  // 否则增加辅音字母计数
            }
        }
    }
    cout << vowels_count << " words beginning with vowels\n";  // 输出以元音字母开头的单词数量
    cout << consonants_count << " words beginning with consonants\n";  // 输出以辅音字母开头的单词数量
    cout << count - vowels_count - consonants_count << " others";  // 输出其他情况的单词数量

    return 0;  // 程序结束
}
