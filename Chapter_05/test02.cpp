#include "iostream"
#include "array"

using namespace std;

const int ArSize = 100; // 定义数组大小常量

/*
知识点总结和注意点：
1. 使用 C++11 标准库的 `std::array`:
   - 使用 `std::array` 进行数组定义，确保数组大小在编译时确定。
   - `std::array` 提供了标准数组操作的封装。

2. 计算阶乘:
   - 使用 `for` 循环计算从 0 到 ArSize 的所有整数的阶乘。
   - 阶乘的计算需要考虑数据类型的选择，这里使用 `long double` 以存储大数值。

3. 输入和输出:
   - 使用 `cout` 输出每个数的阶乘。

注意点：
- 阶乘的数值增长非常快，因此需要使用 `long double` 来存储较大的数值。
- 循环边界条件的设置要正确，以避免数组越界。
*/

int main()
{
    array<long double, ArSize + 1> factorials; // 定义存储阶乘值的数组，并考虑 0 的情况
    factorials[0] = factorials[1] = 1.0; // 初始化 0! 和 1! 为 1

    // 计算阶乘
    for (int i = 2; i <= ArSize; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }

    // 输出阶乘结果
    for (int i = 0; i <= ArSize; ++i)
    {
        cout << i << "! = " << factorials[i] << endl;
    }

    return 0; // 返回0表示程序正常结束
}
