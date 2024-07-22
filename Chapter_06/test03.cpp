#include "iostream"  // 标准输入输出库
using namespace std;

/*
 * 知识点总结：
 * - 函数定义与调用：定义多个函数并在 `main` 函数中调用。
 * - `switch` 语句：根据用户输入调用相应的函数。
 * - 输入处理：提示用户输入并根据输入执行不同操作。
 *
 * 注意点：
 * - 确保用户输入合法字符，并在非法输入时提示重新输入。
 * - 在 `do-while` 循环中处理用户输入，直到输入合法字符为止。
 */

void menu();  // 显示菜单的函数
void carnivore();  // 处理 carnivore 选项的函数
void pianist();  // 处理 pianist 选项的函数
void tree();  // 处理 tree 选项的函数
void game();  // 处理 game 选项的函数

int main()
{
    char ch;
    menu();  // 显示菜单
    do {
        cin >> ch;  // 读取用户输入
        switch (ch) {
            case 'c': carnivore();  break;  // 处理 'c' 选项
            case 'p': pianist();    break;  // 处理 'p' 选项
            case 't': tree();       break;  // 处理 't' 选项
            case 'g': game();       break;  // 处理 'g' 选项
            default: cout << "Please enter a c, p, t, g: ";  // 提示非法输入
        }
    } while ('c' != ch && 'p' != ch && 't' != ch && 'g' != ch);  // 循环直到输入合法字符

    return 0;  // 返回0表示程序成功执行
}

void menu()
{
    cout << "Please enter one of the following choices:\n";
    cout << "c)\tcarnivore\t\t\tp)\tpianist\n";
    cout << "t)\ttree\t\t\t\tg)\tgame" << endl;  // 显示菜单选项
}

void carnivore()
{
    cout << "A maple is a carnivore." << endl;  // 输出 carnivore 选项信息
}

void pianist()
{
    cout << "A maple is a pianist." << endl;  // 输出 pianist 选项信息
}

void tree()
{
    cout << "A maple is a tree." << endl;  // 输出 tree 选项信息
}

void game()
{
    cout << "A maple is a game." << endl;  // 输出 game 选项信息
}
