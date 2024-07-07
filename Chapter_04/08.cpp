#include "iostream"
using namespace std;

int main()
{
    char charr[20];
    string str;
    cout << "charr数组字符串长度：" << strlen(charr) << endl;   // 数组内容未定义，里面都是脏数据，测算的字符串长度不可预测。
    cout << "str数组字符串长度：" << str.size() << endl;   // 未初始化的string对象长度自动为0

    cout << "输入字符至charr：" << endl;
    cin.getline(charr,20);      // istream成员函数
    cout << "输入charr内容是；" << charr << endl;

    cout << "输入字符至str：" << endl;
//    cin >> str;       // cin 程序初始化时，垮过前面空白字符串（空格、制表符和换行符），从非空白字符开始读取， 直到读取空白（空格、制表符和换行符）来确定字符串的结束位置。
    getline(cin,str);       // 单纯的函数
    cout << "输入str内容是：" << str << endl;

    cout << "输入数据后，charr数组字符串长度：" << strlen(charr) << endl;   // 数组内容未定义，里面都是脏数据，测算的字符串长度不可预测。
    cout << "输入数据后，str数组字符串长度：" << str.size() << endl;   // 未初始化的string对象长度自动为0
    return 0;
}