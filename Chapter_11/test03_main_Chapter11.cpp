#include "iostream"
#include "cstdlib"
#include "ctime"
#include "test03_head_Chapter11.h"

using namespace std;
using namespace VECTOR;

/**
 * 知识点总结:
 * 1. 随机数生成：使用 `srand(time(NULL))` 初始化随机数种子，用于生成随机方向。
 * 2. 动态数组：动态分配 `Vector` 对象数组来存储多次实验的结果。
 * 3. 类与对象：定义 `Vector` 类，使用对象进行向量操作。
 * 4. 枚举类型：定义 `Vector` 类中的 `Mode` 枚举类型，用于区分直角坐标和极坐标。
 * 5. 运算符重载：重载了向量的加法、减法、取负、数乘以及输出运算符。
 * 6. 标准库：使用 `cmath` 进行数学运算，使用 `ctime` 获取当前时间。

 * 注意点:
 * 1. 使用 `rand() % 360` 生成随机方向，范围为0到359度。
 * 2. 动态数组的内存管理：使用完毕后需要手动释放内存。
 * 3. `Vector` 类中 `mag_val()` 和 `ang_val()` 的计算需要注意数值的精度问题。
 * 4. 操作符重载函数需要确保不修改操作数本身。
 * 5. 输出运算符的重载需要区分当前模式（RECT 或 POL）并进行相应的输出。
 */

int main() {
    double target;  // 目标距离
    double dstep;  // 步长
    double direction;  // 方向
    unsigned long steps = 0;  // 步数
    unsigned int end = 0;  // 试验次数
    srand(time(NULL));  // 随机数种子

    Vector result(0.0, 0.0);  // 初始位置向量
    Vector step;  // 步长向量

    cout << "How many times do you want to try:";
    cin >> end;
    Vector* result_arr = new Vector[end];  // 动态分配用于存储每次结果的向量数组
    long* dstep_arr = new long[end];  // 动态分配用于存储每次步数的数组
    long dstep_max = 0, dstep_min = 0, dstep_total = 0;  // 最大步数、最小步数和总步数

    cout << "Enter target distance: ";
    cin >> target;  // 输入目标距离
    cout << "Enter the step length: ";
    cin >> dstep;  // 输入步长
    for (int i = 0; i < end; ++i) {  // 循环试验
        while (result.mag_val() < target) {  // 当结果向量的模小于目标距离时
            direction = rand() % 360;  // 随机生成方向
            step.reset(dstep, direction, Vector::POL);  // 根据步长和方向重置步长向量
            result = result + step;  // 更新结果向量
            steps++;  // 步数加1
        }
        result_arr[i] = result;  // 保存结果向量
        dstep_arr[i] = steps;  // 保存步数

        steps = 0;  // 重置步数
        result.reset(0.0, 0.0);  // 重置结果向量
    }

    // 初始化最大和最小步数
    dstep_max = dstep_min = dstep_arr[0];
    for (int i = 0; i < end; ++i) {  // 遍历每次试验的步数
        dstep_max = (dstep_max > dstep_arr[i]) ? dstep_max : dstep_arr[i];  // 更新最大步数
        dstep_min = (dstep_min < dstep_arr[i]) ? dstep_min : dstep_arr[i];  // 更新最小步数
        cout << result_arr[i];  // 输出每次试验的结果向量
        dstep_total += dstep_arr[i];  // 累加总步数
    }

    // 输出最大、最小和平均步数
    cout << "Max = " << dstep_max << ", Min = " << dstep_min << ", val = " << dstep_total / end << endl;
    cout << "Bye!" << endl;  // 输出结束信息

    // 释放动态分配的内存
    delete[] result_arr;
    delete[] dstep_arr;
    return 0;
}
