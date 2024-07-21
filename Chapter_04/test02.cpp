#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 使用`string`类处理字符串：
   - `string`类可以简化字符串操作，包括读取和拼接。
   - `getline()`用于读取包括空格的整行输入。

2. 字符串输出：
   - 使用`<<`运算符进行字符串拼接，构建输出信息。

注意点：
- `getline()`用来读取整行输入，确保包括空格的字符串能够被完整读取。
- 在输出时，字符串拼接通过`<<`操作符实现，不需要手动处理字符串连接。
*/

int main()
{
    // 提示用户输入名字
    cout << "Enter your name:\n";
    string name;  // 定义字符串变量存储名字
    getline(cin, name);  // 读取用户输入的名字，包括空格

    // 提示用户输入喜欢的甜点
    cout << "Enter your favorite dessert:\n";
    string dessert;  // 定义字符串变量存储甜点
    getline(cin, dessert);  // 读取用户输入的甜点，包括空格

    // 输出结果
    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
    return 0;  // 返回0表示程序正常结束
}
