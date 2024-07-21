#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 使用C风格字符串操作函数：
   - `cin.getline()`用于读取整行输入，支持空格。
   - `strcat()`用于拼接C风格字符串。

2. 字符串操作：
   - `strcat()`会修改目标字符串，所以确保目标字符串有足够的空间。
   - 在拼接字符串之前，应确认目标数组的大小足以容纳最终字符串。

注意点：
- `strcat()`拼接字符串时，确保目标字符串有足够的空间以避免溢出。
- 使用`cin.getline()`读取字符串时，指定的长度包括了结束符 `'\0'`，所以要考虑数组的实际大小。
*/

int main()
{
    char first_name[80], last_name[80];  // 定义字符数组用于存储名字

    // 提示用户输入名字
    cout << "Enter your first name: ";
    cin.getline(first_name, 80);  // 读取用户输入的名字，包括空格

    // 提示用户输入姓氏
    cout << "Enter your last name: ";
    cin.getline(last_name, 80);  // 读取用户输入的姓氏，包括空格

    // 拼接名字和姓氏
    strcat(first_name, ", ");  // 在first_name后添加逗号和空格
    strcat(first_name, last_name);  // 在first_name后添加last_name

    // 输出拼接后的结果
    cout << "Here's the information in a single string: " << first_name << endl;

    return 0;  // 返回0表示程序正常结束
}
