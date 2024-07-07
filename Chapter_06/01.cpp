#include "iostream"
using namespace std;
// 读取字符串，识别空格以及字符总数。
int main()
{
    int spaces = 0;
    int total = 0;
    char ch;

    cin.get();
    while (ch != '.')       // 判断'.'结束循环
    {
        if (ch == ' ')
        {
            ++spaces;      // 采集空格字符
        }
        ++total;        // 采集字符
        cin.get(ch);
    }
    cout << "spaces = " << spaces << endl;
    cout << "total = " << total << endl;
    return 0;
}