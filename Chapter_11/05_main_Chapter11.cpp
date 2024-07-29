#include "iostream"
#include "05_head_Chapter11.h"
#include "cstdlib"
#include "ctime"

using namespace std;
using namespace VECTOR;

/*
知识点：
1. 类与对象：使用 `Vector` 类实现向量的基本操作。
2. 枚举类型：定义 `Mode` 枚举用于表示坐标模式（RECT 和 POL）。
3. 运算符重载：重载加、减、负号和乘法运算符以支持向量操作。
4. 随机数：使用 `rand` 函数生成随机角度。
5. 模板与类的组合：定义模板类并在主程序中使用。
6. 流输入输出：使用 `cin` 和 `cout` 进行输入输出操作。
7. 动态内存分配：使用 `new` 和 `delete` 进行动态内存分配和释放。

注意点：
1. 在重载运算符时，确保操作的正确性和返回值类型。
2. 使用 `srand` 初始化随机数种子以确保随机数的多样性。
3. 注意在对象间进行赋值操作时是否需要深拷贝。
4. 在使用 `delete` 释放内存时，避免重复释放和内存泄漏。

主要流程：
1. 输入目标距离和步长。
2. 随机生成角度，计算并累加每一步的位移。
3. 输出最终位置和角度。
4. 重置相关参数，等待下次输入。
*/

int main() {
    double target; // 目标距离
    double dstep; // 步长
    double direction; // 随机角度
    unsigned long steps = 0; // 步数计数器
    srand(time(NULL)); // 初始化随机数种子

    Vector result(0.0, 0.0); // 初始位置向量
    Vector step; // 每一步的向量

    cout << "Enter target distance(q to quit): "; // 输入目标距离(输入q退出)
    while (cin >> target) { // 检查输入是否为数字
        cout << "Enter the step length: "; // 输入步长
        if (!(cin >> dstep)) {break;} // 检查步长输入是否合法
        while (result.mag_val() < target) { // 当当前位置小于目标距离时
            direction = rand() % 360; // 生成随机角度
            step.reset(dstep, direction, Vector::POL); // 根据步长和角度生成向量
            result = result + step; // 更新当前位置
            steps++; // 计数器增加
        }
        cout << "After " << steps << " steps, the subject has the following location:\n"; // 输出当前步数和位置
        cout << result; // 输出当前位置
        result.polar_mode(); // 切换到极坐标模式
        cout << result; // 输出当前极坐标位置

        cout << endl;

        steps = 0; // 重置计数器
        result.reset(0.0, 0.0); // 重置当前位置
        cout << "Enter target distance(q to quit): "; // 提示用户再次输入目标距离
    }
    cout << "Bye!" << endl; // 退出程序
    return 0;
}
