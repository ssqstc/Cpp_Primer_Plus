/**
 * 知识点总结：
 * 1. **文件操作**：使用 fstream 对象进行文件的读写操作。
 * 2. **随机数生成**：使用 srand() 和 rand() 生成随机数，并指定种子以确保随机数序列的随机性。
 * 3. **向量类**：实现向量的基本操作和运算，包括加法、减法、标量乘法等。
 * 4. **输入输出**：通过标准输入输出流和文件流进行数据交互。
 * 5. **常量成员函数**：定义不修改对象状态的成员函数。
 * 6. **重载运算符**：实现运算符重载，如 +、-、* 等。

 * 注意点：
 * 1. **文件打开检查**：检查文件是否成功打开，并处理可能的错误。
 * 2. **随机数范围**：注意 rand() 生成的随机数范围以及转换为角度的过程。
 * 3. **向量模式**：区分 RECT（直角坐标系）和 POL（极坐标系）两种模式，并确保在不同模式下计算和输出正确。
 * 4. **浮点数精度**：处理浮点数运算时注意精度问题。
 * 5. **输入验证**：检查用户输入的有效性，防止程序异常退出。
 */

#include "iostream"  // 包含输入输出流库
#include "test01_head_Chapter11.h"  // 包含头文件
#include "cstdlib"  // 包含 C 标准库
#include "ctime"  // 包含时间库
#include "fstream"  // 包含文件流库

using namespace std;
using namespace VECTOR;

int main() {
    double target;  // 目标距离
    double dstep;  // 每步距离
    double direction;  // 随机方向
    unsigned long steps = 0;  // 步数计数器
    string file_name;  // 文件名

    srand(time(NULL));  // 用当前时间设置随机数种子

    fstream fout;  // 文件流对象
    cout << "Enter filename:";  // 提示输入文件名
    cin >> file_name;  // 从标准输入读取文件名
    fout.open(file_name);  // 打开文件
    if (!fout.is_open()) {  // 检查文件是否成功打开
        cout << file_name << " open error" << endl;  // 文件打开失败提示
        exit(EXIT_FAILURE);  // 退出程序
    }

    Vector result(0.0, 0.0);  // 初始化结果向量
    Vector step;  // 步长向量

    cout << "Enter target distance(q to quit): ";  // 提示输入目标距离
    while (cin >> target) {  // 循环读取目标距离
        cout << "Enter the step length: ";  // 提示输入步长
        if (!(cin >> dstep)) {break;}  // 读取步长，如果失败则退出循环
        fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;  // 将目标距离和步长写入文件
        while (result.mag_val() < target) {  // 当结果向量的模小于目标距离时循环
            direction = rand() % 360;  // 生成随机方向
            fout << steps << ": (x,y) = " << result << endl;  // 将当前步数和位置写入文件
            step.reset(dstep, direction, Vector::POL);  // 重置步长向量为极坐标模式
            result = result + step;  // 更新结果向量
            steps++;  // 步数加一
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";  // 输出步数和当前位置
        fout << "After " << steps << " steps, the subject has the following location:\n";  // 将步数和当前位置写入文件
        fout << "x,y = " << result << "or\n";  // 将结果向量（直角坐标）写入文件
        cout << result;  // 输出结果向量（直角坐标）
        result.polar_mode();  // 切换结果向量为极坐标模式
        fout << "m,a = " << result;  // 将结果向量（极坐标）写入文件
        fout << "Average outward distance per step = " << result.mag_val() / steps << endl;  // 计算并写入平均每步的外向距离
        cout << result;  // 输出结果向量（极坐标）

        cout << endl;

        steps = 0;  // 重置步数计数器
        result.reset(0.0, 0.0);  // 重置结果向量
        cout << "Enter target distance(q to quit): ";  // 提示输入新的目标距离
    }
    cout << "Bye!" << endl;  // 输出再见信息
    return 0;
}
