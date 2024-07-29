#include "iostream"
#include "test02_head_Chapter11.h"
#include "cstdlib"
#include "ctime"

using namespace std;
using namespace VECTOR;

/**
 * 知识点总结:
 * 1. 随机数生成：使用 `srand(time(NULL))` 初始化随机数种子，用于生成随机方向。
 * 2. 类与对象：定义 `Vector` 类，使用对象进行向量操作。
 * 3. 枚举类型：定义 `Vector` 类中的 `Mode` 枚举类型，用于区分直角坐标和极坐标。
 * 4. 运算符重载：重载了向量的加法、减法、取负、数乘以及输出运算符。
 * 5. 标准库：使用 `cmath` 进行数学运算，使用 `ctime` 获取当前时间。

 * 注意点:
 * 1. 使用 `rand() % 360` 生成随机方向，范围为0到359度。
 * 2. `Vector` 类中 `mag_val()` 和 `ang_val()` 的计算需要注意数值的精度问题。
 * 3. 操作符重载函数需要确保不修改操作数本身。
 * 4. 输出运算符的重载需要区分当前模式（RECT 或 POL）并进行相应的输出。
 */

int main() {
    double target;  // 目标距离
    double dstep;  // 步长
    double direction;  // 方向
    unsigned long steps = 0;  // 步数
    srand(time(NULL));  // 随机数种子

    Vector result(0.0, 0.0);  // 初始位置向量
    Vector step;  // 步长向量

    cout << "Enter target distance(q to quit): ";
    while (cin >> target) {  // 输入目标距离
        cout << "Enter the step length: ";
        if (!(cin >> dstep)) { break; }  // 输入步长
        while (result.mag_val() < target) {  // 当结果向量的模小于目标距离时
            direction = rand() % 360;  // 随机生成方向
            step.reset(dstep, direction, Vector::POL);  // 根据步长和方向重置步长向量
            result = result + step;  // 更新结果向量
            steps++;  // 步数加1
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result;  // 输出当前结果向量的直角坐标
        result.polar_mode();  // 切换到极坐标模式
        cout << result;  // 输出当前结果向量的极坐标

        cout << endl;

        steps = 0;  // 重置步数
        result.reset(0.0, 0.0);  // 重置结果向量
        cout << "Enter target distance(q to quit): ";
    }
    cout << "Bye!" << endl;
    return 0;
}
