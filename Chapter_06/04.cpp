#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 函数声明和定义：避免在main函数中代码冗长。
 * - switch语句：用于多分支选择。
 * - do-while循环：用于实现菜单驱动的程序结构。
 *
 * 注意点：
 * - 确保用户输入的有效性，避免无效输入导致的程序异常。
 * - 函数的返回类型、参数列表必须与声明匹配。
 * - 避免魔法值：使用明确的常量表示退出条件等。
 */

// 函数声明
void show_menu(void);
void report(void);
void comfort(void);

int main()
{
    int choice;
    do {
        show_menu(); // 显示菜单
        cin >> choice; // 获取用户选择

        // 根据用户选择执行相应的操作
        switch (choice)
        {
            case 1: cout << "Warning!" << endl; // 输出警告信息
                break;
            case 2: report();
                break;
            case 3: cout << "The boss was in all day" << endl; // 输出老板全天在
                break;
            case 4: comfort();
                break;
            default: cout << "That is not a choice." << endl; // 输出无效选择信息
        }

        cout << "------------分割线------------" << endl; // 输出分割线
    } while (choice != 5); // 选择5退出循环

    return 0;
}

// 显示菜单选项
void show_menu(void)
{
    cout << "Please enter 1, 2, 3, 4, or 5 as your choice:" << endl; // 提示用户输入选择
    cout << "1) alarm    2) report" << endl; // 菜单选项1和2
    cout << "3) alibi    4) comfort" << endl; // 菜单选项3和4
    cout << "5) quit" << endl; // 菜单选项5
}

// 报告函数
void report(void)
{
    cout << "Sales are up 120%. Expenses are down 35%." << endl; // 输出销售和支出报告
}

// 安慰函数
void comfort(void)
{
    cout << "You are the best CEO!" << endl; // 输出安慰信息
}
