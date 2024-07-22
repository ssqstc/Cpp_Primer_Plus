#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 结构体使用：
   - 定义一个 `car` 结构体，包含 `manufacturer`（制造商） 和 `year`（年份）两个成员。
   - 使用动态数组存储多个 `car` 结构体实例。

2. 动态内存分配：
   - 使用 `new` 操作符分配存储 `num` 个 `car` 结构体的数组。
   - 使用 `delete[]` 释放动态分配的内存，防止内存泄漏。

3. 输入和输出：
   - 使用 `cin` 和 `getline` 分别读取年份和制造商。
   - 注意在使用 `getline` 之前调用 `cin.get()` 来消耗掉前一个输入留下的换行符。

注意点：
- 动态内存管理需要确保在程序结束前释放内存。
- 输入和输出操作的顺序和方法要一致，以避免混乱。
*/

struct car
{
    string manufacturer; // 制造商
    float year;          // 年份
};

int main()
{
    int num = 0;
    cout << "How many cars do you wish to catalog? "; // 提示用户输入需要记录的汽车数量
    cin >> num;

    car* p_car = new car[num]; // 动态分配存储num个car结构体的数组

    for (int i = 0; i < num; ++i) {
        cin.get(); // 清除输入缓冲区
        cout << "Car #" << i + 1 << ":\n"; // 提示输入第i+1辆车的信息
        cout << "Please enter the make: "; // 提示输入制造商
        getline(cin, p_car[i].manufacturer); // 使用getline读取制造商名称
        cout << "Please enter the year made: "; // 提示输入年份
        cin >> p_car[i].year; // 读取年份
    }

    for (int i = 0; i < num; ++i) {
        cout << p_car[i].year << " " << p_car[i].manufacturer << endl; // 输出每辆车的信息
    }

    delete[] p_car; // 释放动态分配的内存
    return 0; // 返回0表示程序正常结束
}
