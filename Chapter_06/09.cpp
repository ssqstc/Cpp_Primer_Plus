#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 输入验证：通过循环和流状态检测确保用户输入有效的数值。
 * - 数组操作：存储和处理多个数值输入。
 * - 计算平均值：累加数组中的数值并计算平均值。
 *
 * 注意点：
 * - 使用 `cin.clear()` 清除错误状态。
 * - 使用 `cin.get()` 读取并丢弃无效输入。
 * - 保证用户输入的都是数值，避免因无效输入导致程序崩溃。
 */

const int Max = 5;

int main()
{
    int golf[Max]; // 存储高尔夫成绩的数组
    cout << "Please enter your golf scores: " << endl; // 提示输入高尔夫成绩
    cout << "You must enter " << Max << " rounds." << endl; // 提示需要输入的轮数

    int i;
    for (i = 0; i < Max; i++) // 循环读取用户输入
    {
        cout << "Round #" << i + 1 << ": "  << endl; // 提示输入第几轮的成绩
        while (!(cin >> golf[i])) // 检查输入是否为有效数字
        {
            cin.clear(); // 清除错误状态
            while (cin.get() != '\n') continue; // 丢弃无效输入
            cout << "Please enter a number: "; // 提示重新输入数字
        }
    }

    double total = 0.0; // 初始化总成绩为0
    for (int j = 0; j < Max; ++j) // 遍历数组
        total += golf[j]; // 计算总成绩

    cout << "Average score: " << total / Max; // 计算并输出平均成绩

    return 0; // 程序结束
}
