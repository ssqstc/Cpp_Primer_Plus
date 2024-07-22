#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - `cin` 输入流清理：使用 `cin.clear()` 清理输入流的错误状态，并通过 `cin.get()` 跳过多余的输入。
 * - 输入操作：通过 `cin` 接收用户输入，并确保每次输入后处理多余的输入数据。
 *
 * 注意点：
 * - `cin.clear()` 用于清除输入流的错误状态。
 * - `while (cin.get() != '\n');` 用于跳过输入缓冲区中的所有字符，直到遇到换行符。
 * - 处理多余输入是为了防止因上一次输入产生的多余字符影响后续输入。
 */

int main()
{
    int num1, num2;

    cout << "First number: ";
    cin >> num1;  // 输入第一个数字

    cin.clear();  // 清理输入流错误状态
    while (cin.get() != '\n');  // 跳过输入缓冲区中的所有字符，直到遇到换行符

    cout << "Last number: ";
    cin >> num2;  // 输入第二个数字

    cout << "num1 = " << num1 << " , num2 = " << num2 << endl;  // 输出输入的两个数字

    return 0;
}
