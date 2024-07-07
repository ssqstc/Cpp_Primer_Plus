#include "iostream"
using namespace std;
// cin输入类型不匹配处置方式
int main()
{
    int num1, num2;

    cout << "First number: " ;
    cin >> num1;        // 应输入整形数，若输入字符，cin将报错并返回0值，此时，cin输入捕获功能被禁用。

    cin.clear();        // reset(重置) cin功能，同时也重置文件为EOF。
    while (cin.get() != '\n');  // 清楚残留错误字符。

    cout << "Last number:" ;
    cin >> num2;

    cout << "num1 = " << num1 << " , num2 = " << num2 << endl;


    return 0;
}