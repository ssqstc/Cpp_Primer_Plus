#include "iostream"
using namespace std;
#include "cctype"       // 判断字符类型的头文件
// 判断字符类型函数
int main()
{
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    char ch;

    cout << "Enter text for analysis, and type @ to terminate the input." << endl;
    cin.get(ch);

    while (ch != '@')
    {
        if (isalpha(ch))        // 判断输入是否为字符
            chars++;                // 字符输入chars++
        else if (isspace(ch))       // 判断输入是否为空格
            whitespace++;               // 空格输入whitespace++
        else if (isdigit(ch))       // 判断输入是否为数字
            digits++;                   // 数字输入digits++
        else if (ispunct(ch))           // 判断输入是否为标点符号
            punct++;                    // 标点输入punct++
        else
            others++;                   // 什么都不是others++
        cin.get(ch);
    }
    cout << chars << " letters, " << whitespace << " whitespace, " << digits << " digits, " << punct << " punct, " << others << " others." << endl;
    return 0;
}