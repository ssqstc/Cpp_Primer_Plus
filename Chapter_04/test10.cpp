#include "iostream"
using namespace std;
#include "array"

/*
知识点总结和注意点：
1. 使用`std::array`：
   - `std::array`是C++11引入的标准库容器，提供了固定大小的数组。
   - `std::array`具有与普通数组相似的性能，但提供了更多的功能和安全性。
2. 输入和输出操作：
   - 使用`cin`读取用户输入并存储到数组中。
   - 使用`cout`输出数组中的值和计算结果。
3. 常量定义：
   - 使用`const`定义常量，可以提高代码的可读性和维护性。
*/

int main()
{
    const int count = 3;  // 定义常量，表示成绩的数量
    array<float, count> score;  // 创建一个包含3个float元素的数组

    // 输入成绩
    cout << "Enter 40m score:";  // 提示用户输入第1次成绩
    cin >> score[0];  // 读取并存储第1次成绩

    cout << "Enter 40m score:";  // 提示用户输入第2次成绩
    cin >> score[1];  // 读取并存储第2次成绩

    cout << "Enter 40m score:";  // 提示用户输入第3次成绩
    cin >> score[2];  // 读取并存储第3次成绩

    // 输出每次成绩
    cout << "1st:" << score[0] << endl;  // 输出第1次成绩
    cout << "2nd:" << score[1] << endl;  // 输出第2次成绩
    cout << "3rd:" << score[2] << endl;  // 输出第3次成绩

    // 计算并输出平均成绩
    cout << count << "次平均成绩：" << (score[0] + score[1] + score[2]) / count;  // 计算并输出平均成绩

    return 0;  // 程序结束
}
