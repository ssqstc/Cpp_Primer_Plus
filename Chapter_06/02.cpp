#include "iostream"
using namespace std;
// 对子母进行加密修改输入文本
int main()
{
    char ch;
    cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')     // 输入字符是回车，输出不变
            cout << ch;
        else
            cout << ++ch;       // 输入其他字符，ASCII + 1
        cin.get(ch);        // cout << ch + 1; 输出的是整数，因为 ch + 1 结果被提升为 int 类型
    }
    cout << endl;

    return 0;
}