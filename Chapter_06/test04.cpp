#include "iostream"  // 标准输入输出库
using namespace std;

const int strsize = 40;  // 定义字符串最大长度
const int usersize = 4;  // 定义用户数量

/*
 * 知识点总结：
 * - 结构体定义与数组：使用 `struct` 定义数据结构，并创建结构体数组存储多个用户数据。
 * - 多重选择语句：通过 `switch` 语句实现菜单选择功能。
 * - 函数分离：将不同的显示功能分离到独立的函数中，提高代码的可读性和可维护性。
 *
 * 注意点：
 * - 输入处理：确保用户输入合法字符，并在非法输入时提示重新输入。
 * - `print_by_pref` 函数根据用户的 `preference` 显示相应的信息。
 */

void print_by_fullname();  // 按全名显示
void print_by_title();  // 按职称显示
void print_by_bopname();  // 按 BOP 名称显示
void print_by_pref();  // 按偏好显示

// 结构体定义
struct bop
{
    char fullname[strsize]; // 真实姓名
    char title[strsize];    // 职称
    char bopname[strsize];  // BOP 秘密名称
    int preference;    // 0 = fullname, 1 = title, 2 = bopname
};

// 结构体数组初始化
bop user[usersize] = {
        {"Rick", "Level_A", "RR", 0},
        {"Jack", "Level_B", "JJ", 1},
        {"Micheal", "Level_C", "MM", 2},
        {"Rose", "Level_D", "RR", 0},
};

void menu();  // 显示菜单的函数

int main()
{
    char input;
    menu();  // 显示菜单
    cin >> input;
    while ('q' != input)
    {
        switch (input)
        {
            case 'a': print_by_fullname(); break;  // 按全名显示
            case 'b': print_by_title(); break;  // 按职称显示
            case 'c': print_by_bopname(); break;  // 按 BOP 名称显示
            case 'd': print_by_pref(); break;  // 按偏好显示
            default:
                cout << "Please enter character a, b, c, d, q:" << endl;  // 提示非法输入
        }
        menu();  // 重新显示菜单
        cin >> input;  // 读取用户输入
    }
    cout << "Bye" << endl;
    return 0;  // 返回0表示程序成功执行
}

void menu()
{
    cout << "Benevolent Order of  Programmers Report" << endl;
    cout << "a. display by name\t\t\tb. display by title\n"
            "c. display by bopname\t\td. display by preference\n"
            "q. quit\n";  // 显示菜单选项
}

void print_by_fullname()
{
    for (int i = 0; i < usersize; ++i)  // 遍历用户数组
        cout << user[i].fullname << endl;  // 输出全名
}

void print_by_title()
{
    for (int i = 0; i < usersize; ++i)  // 遍历用户数组
        cout << user[i].title << endl;  // 输出职称
}

void print_by_bopname()
{
    for (int i = 0; i < usersize; ++i)  // 遍历用户数组
        cout << user[i].bopname << endl;  // 输出 BOP 名称
}

void print_by_pref()
{
    for (int i = 0; i < usersize; ++i)  // 遍历用户数组
    {
        switch (user[i].preference)  // 根据用户的 preference 显示相应的信息
        {
            case 0: cout << user[i].fullname << endl; break;  // 显示全名
            case 1: cout << user[i].title << endl; break;  // 显示职称
            case 2: cout << user[i].bopname << endl; break;  // 显示 BOP 名称
        }
    }
}
