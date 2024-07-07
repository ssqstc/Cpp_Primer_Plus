#include "iostream"
using namespace std;
#include "cctype"
int main()
{
    char ch;
    cout << "Please enter a character: ";
    while (cin.get(ch) && ch != '@')
    {
        if (isdigit(ch))
            continue;       // 判断数字 跳过循环
        else if (islower(ch))
            cout << (char)toupper(ch);  // 大写字母转小写并输出
        else if (isupper(ch))
            cout << (char)tolower(ch);  // 小写字母转大写并输出
        else
            cout << ch;     // 输出其他字符
    }

    return 0;
}