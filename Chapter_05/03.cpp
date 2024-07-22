#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 数组的定义和初始化：
   - 数组用于存储一组相同类型的元素，声明时需指定数组的大小。
   - 数组初始化可以逐个赋值，也可以使用循环批量赋值。
2. 阶乘的计算：
   - 阶乘是从1到n的所有整数的乘积，0!和1!都定义为1。
   - 通过递归关系n! = n * (n-1)!可以用循环来计算数组中每个位置的阶乘值。

注意点：
- 确保数组大小足够存储计算结果，避免数组越界。
- long long类型用于处理较大的整数，适合阶乘这种容易产生大数的运算。
*/

const int ArSize = 20;  // 常量，定义数组大小

int main()
{
    long long factorials[ArSize];  // 定义数组用于存储阶乘值
    factorials[0] = factorials[1] = 1;  // 初始化0!和1!为1

    for (int i = 2; i < ArSize; ++i) {
        factorials[i] = i * factorials[i-1];  // 递归计算i的阶乘
    }

    for (int i = 0; i < ArSize; ++i) {
        cout << i << "! = " << factorials[i] << endl;  // 输出每个阶乘值
    }

    return 0;
}
