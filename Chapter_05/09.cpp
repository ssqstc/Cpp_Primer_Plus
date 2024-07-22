#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. `for`循环和`while`循环的使用场景：
   - `for`循环适用于确定循环次数的情况。
   - `while`循环更适用于基于条件表达式的循环。

2. 字符串处理：
   - C风格字符串以空字符(`\0`)结束。
   - 使用`while`循环遍历字符串时，通过检查字符是否为`\0`来判断是否到达字符串末尾。

注意点：
- 确保字符数组足够大以容纳输入的字符串。
- 在遍历C风格字符串时，记得检查每个字符是否为`\0`，以避免越界访问。
*/

const int ArSize = 20; // 字符数组的大小
int main()
{
    char name[ArSize]; // 定义字符数组
    cout << "Your first name please: "; // 提示输入名字
    cin >> name; // 获取输入的名字

    cout << "Here is your name: " << endl; // 输出提示信息
    int i = 0;
    while (name[i] != '\0') // 当字符不是空字符时继续循环
    {
        cout << name[i] << ": " << (int)name[i] << endl; // 输出字符和对应的ASCII值
        i++;
    }
    return 0;
}
