#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 循环输入：使用 `while` 循环接收用户输入并存储在数组中。
 * - 输入终止条件：通过检测数组下标和输入流状态控制输入终止。
 * - 数组操作：遍历数组计算总和并求平均值。
 *
 * 注意点：
 * - 使用 `cin` 检查输入状态来判断是否继续读取输入。
 * - 当用户输入非数字字符时，`cin` 状态变为错误状态，循环终止。
 * - 注意数组访问边界，避免越界。
 */

const int Max = 5;

int main()
{
    double fish[Max]; // 存储鱼重量的数组
    cout << "Please enter the weight of your fish." << endl; // 提示输入鱼的重量
    cout << "You may enter up to " << Max << " fish <q> to terminate." << endl; // 提示最多可以输入的鱼数量以及终止输入的方法

    cout << "fish #1: "; // 提示输入第一条鱼的重量
    int i = 0; // 初始化计数器
    while (i < Max && cin >> fish[i]) // 循环读取鱼的重量，直到输入达到最大数量或者输入非数字字符
    {
        if (++i < Max) // 递增计数器，并检查是否仍然可以输入更多鱼的重量
            cout << "fish #" << i + 1 << ": "; // 提示输入下一条鱼的重量
    }

    double total = 0.0; // 总重量初始化为0
    for (int j = 0; j < i; ++j) // 遍历数组
        total += fish[j]; // 计算总重量

    if (0 == i) // 检查是否有输入
        cout << "No fish!" << endl; // 如果没有输入，输出提示
    else
    {
        cout << "fish total: " << total << endl; // 输出总重量
        cout << "Average weight of " << i << " fish: " << total / i << endl; // 计算并输出平均重量
    }

    return 0; // 程序结束
}
