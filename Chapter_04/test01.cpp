#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 输入输出操作：
   - 使用cin.getline()读取字符串，防止读取到空格前就结束的问题。
   - 使用cin读取单个字符和浮点数。

2. 字符处理：
   - 提升字符的ASCII值以改变其字母顺序，例如grade++将当前的字母提升到下一个字母。

3. 字符串操作：
   - 通过字符数组存储名字，并通过getline()读取包含空格的输入。

注意点：
- 使用cin.getline()时要注意缓冲区大小，防止缓冲区溢出。
- 提升字符的ASCII值时，要确保不会超出字符范围。
- 输出时注意格式，保证输出的易读性。
*/

int main()
{
    const int Size = 20;  // 定义常量Size用于数组大小
    char first_name[Size], last_name[Size];  // 定义字符数组存储名字
    char grade;  // 定义字符变量存储等级
    float age;  // 定义浮点变量存储年龄

    // 获取用户的名字和其他信息
    cout << "What is your first name? ";
    cin.getline(first_name, Size);  // 获取用户的名字，包括空格

    cout << "What is your last name? ";
    cin.getline(last_name, Size);  // 获取用户的姓氏，包括空格

    cout << "What letter grade do you deserve? ";
    cin >> grade;  // 获取用户的等级
    grade++;  // 提升等级字母

    cout << "What is your age? ";
    cin >> age;  // 获取用户的年龄

    // 输出用户的信息
    cout << "Name: " << last_name << ", " << first_name << "\nGrade: " << grade << "\nAge: " << age;
    return 0;  // 返回0表示程序正常结束
}
