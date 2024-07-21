#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 使用 `string` 类：
   - `string` 类在 C++ 标准库中，用于处理和操作字符串，支持丰富的字符串操作方法。
2. 输入处理：
   - 使用 `getline(cin, variable)` 从标准输入读取一整行字符串并存入 `variable` 中。
3. 字符串拼接：
   - 使用 `+` 操作符连接两个字符串。
*/

int main()
{
    string first_name, last_name;

    cout << "Enter your first name: ";  // 输出提示信息：输入名字
    getline(cin, first_name);  // 读取用户输入的名字

    cout << "Enter your last name: ";  // 输出提示信息：输入姓氏
    getline(cin, last_name);  // 读取用户输入的姓氏

    first_name = first_name + ", " + last_name;  // 拼接字符串：名字 + 逗号 + 空格 + 姓氏

    cout << "Here's the information in a single string: " << first_name << endl;  // 输出拼接后的字符串

    return 0;  // 程序结束
}
