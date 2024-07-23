#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 数组操作：包括数组的输入、输出和修改操作。
 * 2. 函数参数：通过传递数组和数组长度，实现对数组的操作。
 * 3. 输入验证：通过输入验证确保输入的有效性。
 *
 * 注意点：
 * 1. 输入验证：需要处理非数值和负值输入，确保输入过程的正确性。
 * 2. 数组边界：在操作数组时，确保不越界访问数组元素。
 * 3. 函数设计：函数应该具有明确的功能，避免副作用。
 */

const int Max = 5; // 数组最大长度

void show_array(const double arr[], int n); // 显示数组内容的函数声明

void revalue(double r, double arr[], int n); // 调整数组值的函数声明

int fill_array(double arr[], int Max); // 填充数组的函数声明

int main() {
    double properties[Max]; // 定义数组

    int size = fill_array(properties, Max); // 填充数组并返回实际长度
    show_array(properties, size); // 显示数组内容

    if (size > 0) { // 检查数组是否有元素
        cout << "Enter revaluation factor: "; // 输入重新估值因子
        double factor;
        while (!(cin >> factor)) { // 检查输入是否有效
            cin.clear(); // 清除错误状态
            while (cin.get() != '\n') { // 丢弃无效输入
                continue;
            }
            cout << "Bad input: input process terminated." << endl; // 无效输入提示
        }
        revalue(factor, properties, size); // 重新估值
        show_array(properties, size); // 显示更新后的数组内容
    }
    return 0;
}

int fill_array(double arr[], int Max) { // 填充数组的函数定义
    double temp;
    int i;
    for (i = 0; i < Max; ++i) {
        cout << "Enter value # " << i + 1 << " : "; // 输入数组元素值
        if (!(cin >> temp)) { // 检查输入是否有效
            cin.clear(); // 清除错误状态
            while (cin.get() != '\n') { // 丢弃无效输入
                continue;
            }
            cout << "Bad input: input process terminated." << endl; // 无效输入提示
            break; // 退出循环
        } else if (temp < 0) { // 负值输入终止
            break; // 退出循环
        } else
            arr[i] = temp; // 将有效输入存入数组
    }
    return i; // 返回实际输入的元素个数
}

void show_array(const double arr[], int n) { // 显示数组内容的函数定义
    for (int i = 0; i < n; ++i) {
        cout << "Property # " << i + 1 << " :$ "; // 显示元素索引
        cout << arr[i] << endl; // 显示元素值
    }
}

void revalue(double r, double arr[], int n) { // 调整数组值的函数定义
    for (int i = 0; i < n; ++i) {
        arr[i] *= r; // 按因子重新估值
    }
}
