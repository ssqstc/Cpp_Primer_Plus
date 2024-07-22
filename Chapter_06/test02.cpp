#include "iostream"  // 标准输入输出库
using namespace std;
#include "array"  // 标准数组库

const int SIZE = 10;  // 常量定义数组大小

/*
 * 知识点总结：
 * - 使用 `array` 容器处理固定大小的数组。
 * - 输入处理和有效性检查：通过循环和条件语句确保正确处理用户输入。
 * - 统计和计算：求和、计算平均值以及统计大于平均值的数量。
 *
 * 注意点：
 * - 使用 `array<double, SIZE>` 定义固定大小的数组。
 * - 处理输入时，确保在输入有效数字后继续处理。
 * - 计算和比较时确保正确性，防止除零错误。
 */

int main()
{
    array<double, SIZE> donation {};  // 定义一个存储捐款的数组，初始值为0
    double input, sum = 0;  // 定义输入变量和总和变量
    int count = 0, average_count = 0;  // 计数变量和大于平均值的计数变量

    cout << "Enter number:";  // 提示用户输入数字
    while (count < SIZE && cin >> input)  // 循环读取用户输入，直到达到数组大小
    {
        donation[count++] = input;  // 将输入存入数组并增加计数
        sum += input;  // 累加输入到总和
        if (count < SIZE)  // 如果还没有达到数组大小，继续提示用户输入
            cout << "Enter next number:";
    }

    if (count == 0)  // 如果没有有效输入，输出提示信息
        cout << "No valid enter" << endl;
    else
    {
        cout << "average = " << sum / count;  // 输出平均值
        for (int i = 0; i < count; ++i)  // 遍历数组，统计大于平均值的数量
        {
            if ((sum / count) < donation[i])
                ++average_count;
        }
        cout << ", " << average_count << " more than the average." << endl;  // 输出结果
    }

    return 0;  // 返回0表示程序成功执行
}
