#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 函数定义与调用：理解如何定义和调用简单的函数。
 * - 函数声明：在使用函数之前先声明。
 * - 标准输出：使用 cout 进行控制台输出。

 * 注意点：
 * - 函数声明在 main 函数之前，定义在之后，确保 main 函数可以正确调用。
 * - 使用合适的输出语句来调试和理解程序的运行流程。
 */

/*
 * 主函数：演示简单函数调用
 * - 输出提示信息
 * - 调用 simple 函数
 */
void simple();

int main()
{
    cout << "main() will call the simple() function:" << endl; // main() 将调用 simple() 函数
    simple(); // 调用 simple 函数
    return 0;
}

/*
 * simple 函数：输出简单的信息
 * - 显示提示信息
 */
void simple()
{
    cout << "I'm but a simple function." << endl; // 我只是一个简单的函数
}
