#include "iostream"
using namespace std;
#include "ctime"

/*
知识点总结和注意点：
1. 使用`clock()`函数实现延时：
   - `clock()`函数返回程序开始执行后所用的系统时间。
   - `clock_t`是`clock()`返回类型的别名。
   - `CLOCKS_PER_SEC`常量表示每秒包含的系统时间单位数。

2. 类型别名的定义：
   - `typedef`用于定义类型别名，提高代码可读性。
   - 例如，`typedef typeName aliasName;` 或 `#define aliasName typeName`。
   - 推荐使用`typedef`定义别名。

注意点：
- 延时循环中使用`clock()`和`clock_t`计算延时时间。
- 注意时间单位转换，将秒数转换为时钟节拍。
*/

int main()
{
    cout << "Enter the delay time, in seconds: "; // 提示输入延时时间
    float secs;
    cin >> secs; // 获取输入的延时时间（秒）

    clock_t delay = secs * CLOCKS_PER_SEC; // 将秒数转换为时钟节拍
    clock_t start = clock(); // 获取当前时钟节拍

    while (clock() - start < delay); // 进行延时循环

    cout << "Done\n"; // 延时结束后输出完成信息
    return 0;
}
