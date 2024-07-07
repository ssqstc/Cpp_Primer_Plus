#include "iostream"
using namespace std;

// 主函数，程序的入口点
// string类字符串与char数组字符串
int main()
{
    // 定义一个字符数组charr1，用于存储用户输入的猫的种类
    char charr1[20];
    // 定义一个字符数组charr2，并初始化为"jaguar"，表示一种猫的种类
    char charr2[20] = "jaguar";
    // 定义一个字符串对象str1，用于存储用户输入的猫的种类
    string str1;
    // 定义一个字符串对象str2，并初始化为"panther"，表示另一种猫的种类
    string str2 = "panther";

    // 请求用户输入一种猫的种类，并将其存储到charr1中
    cout << "Enter a kind of feline:";
    cin >> charr1;
    // 请求用户输入另一种猫的种类，并将其存储到str1中
    cout << "Enter another kind of feline:";
    cin >> str1;

    // 输出所有输入的猫的种类
    cout << "Here are some feline:\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

    // 输出charr2中第三個字符（字母序的第三位）
    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
    // 输出str2中第三個字符（字母序的第三位）
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;    // 都可以下标取值
    return 0;
}
