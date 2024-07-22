#include "iostream"
using namespace std;
#include "fstream"
#include "cstdlib"

const int SIZE = 20;

/*
 * 知识点总结：
 * - 文件输入：使用 `ifstream` 类进行文件输入操作。
 * - 错误处理：检查文件是否成功打开，处理文件读取中的各种错误情况。
 * - 基本输入输出：使用 `cin.getline` 获取文件名，通过 `while` 循环读取文件中的数据。
 *
 * 注意点：
 * - 确保文件能够正确打开和关闭。
 * - 使用 `exit(EXIT_FAILURE)` 在文件打开失败时终止程序。
 * - 处理不同类型的文件读取错误（如数据类型不匹配）。
 */

int main()
{
    char filename[SIZE];  // 存储文件名的字符数组
    ifstream inFile;  // 输入文件流对象

    cout << "Enter name of data file: ";  // 提示用户输入文件名
    cin.getline(filename, SIZE);  // 获取文件名

    inFile.open(filename);  // 打开文件
    if (!inFile.is_open())  // 检查文件是否成功打开
    {
        cout << "Could not open the file " << filename << endl;  // 打印错误信息
        cout << "Program terminating!" << endl;  // 打印程序终止信息
        exit(EXIT_FAILURE);  // 终止程序
    }

    double value, sum = 0.0;  // 用于存储读取的值和总和
    int count = 0;  // 用于记录读取的数量

    while (inFile >> value)  // 逐个读取文件中的数值
    {
        ++count;  // 计数器递增
        sum += value;  // 累加总和
    }

    if (inFile.eof())  // 检查是否到达文件末尾
        cout << "End of file reached." << endl;  // 打印文件结束信息
    else if (inFile.fail())  // 检查读取是否失败
        cout << "Input terminated by data mismatch." << endl;  // 打印数据类型不匹配错误信息
    else
        cout << "Input terminated for unknown reason." << endl;  // 打印未知错误信息

    if (0 == count)  // 检查是否读取到数据
        cout << "No data processed." << endl;  // 打印无数据信息
    else
    {
        cout << "Items read: " << count << endl;  // 打印读取的项目数量
        cout << "Sum: " << sum << endl;  // 打印总和
        cout << "Average: " << sum / count << endl;  // 打印平均值
    }

    inFile.close();  // 关闭文件
    return 0;  // 返回0表示程序成功执行
}
