#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 枚举类型：定义了一组命名的整数常量，增强代码可读性。
 * - while循环：根据条件重复执行代码块。
 * - switch语句：用于多分支选择，根据不同的枚举值输出相应的字符串。
 *
 * 注意点：
 * - 枚举类型的值从0开始，依次递增。
 * - 确保用户输入在有效范围内（0~6），否则退出循环。
 * - 使用适当的提示信息引导用户输入。
 */

// 定义枚举类型
enum {red, orange, yellow, green, violet, indigo};

int main()
{
    int code;
    cout << "Enter color code (0~6):"; // 提示用户输入颜色代码
    cin >> code;

    // 判断输入是否在有效范围内
    while (code >= red && code <= indigo)
    {
        // 根据不同的代码输出对应的颜色
        switch (code)
        {
            case red: cout << "You choose red" << endl; break; // 红色
            case orange: cout << "You choose orange" << endl; break; // 橙色
            case yellow: cout << "You choose yellow" << endl; break; // 黄色
            case green: cout << "You choose green" << endl; break; // 绿色
            case violet: cout << "You choose violet" << endl; break; // 紫色
            case indigo: cout << "You choose indigo" << endl; break; // 靛蓝色
        }
        cout << "Enter color code (0~6):"; // 提示用户再次输入颜色代码
        cin >> code;
    }
    cout << "Bye!" << endl; // 用户输入无效范围时输出再见信息
    return 0;
}
