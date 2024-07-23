#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 指针运算：使用指针遍历数组。
 * 2. 输入输出：通过 `cin` 和 `cout` 进行用户输入和输出。
 * 3. 数组处理：定义和操作数组。
 * 4. 函数：定义和调用处理数组的函数。
 *
 * 注意点：
 * 1. 输入验证：确保用户输入有效，处理无效输入。
 * 2. 指针操作：确保指针操作不越界。
 * 3. 数组边界：操作数组时要注意起始和结束的边界。
 */

const int Max = 5;  // 数组最大长度

// 函数声明
void show_array(const double arr_begin[], const double arr_end[]); // 显示数组内容
void revalue(double r, double arr_begin[], const double arr_end[]); // 调整数组值
double *fill_array(double arr_begin[], double arr_end[]); // 填充数组

int main(){
    double properties[Max];  // 定义一个长度为 Max 的数组
    double *pa = fill_array(properties, properties + Max);   // 填充数组，并返回填充结束的位置

    show_array(properties, pa);  // 显示数组内容

    if (pa > properties){  // 检查是否有有效输入
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)){  // 验证输入
            cin.clear();  // 清除错误状态
            while (cin.get() != '\n'){  // 丢弃无效输入
                continue;
            }
            cout << "Bad input: input process terminated." << endl;
        }
        revalue(factor, properties, pa);  // 调整数组值
        show_array(properties, pa);  // 显示调整后的数组内容
    }
    return 0;
}

double *fill_array(double arr_begin[], double arr_end[]){
    double temp;
    double *pt;
    for (pt = arr_begin; pt != arr_end; ++pt) {
        cout << "Enter value # " << pt - arr_begin + 1 << " : ";
        if (!(cin >> temp)){    // 验证输入是否有效
            cin.clear();      // 清除错误状态
            while (cin.get() != '\n'){    // 丢弃无效输入
                continue;
            }
            cout << "Bad input: input process terminated." << endl;
            break;  // 退出循环
        } else if (temp < 0){  // 检查输入是否为负数
            break;  // 负数则退出
        } else {
            *pt = temp;  // 有效输入则存入数组
        }
    }
    return pt;  // 返回数组填充结束的位置
}

void show_array(const double arr_begin[], const double arr_end[]){
    for (const double *pt = arr_begin; pt != arr_end; ++pt) {  // 使用指针遍历数组
        cout << "Property #" << pt - arr_begin + 1 << ": $";  // 输出每个元素的索引和值
        cout << *pt << endl;
    }
}

void revalue(double r, double arr_begin[], const double arr_end[]){
    double *temp;
    for (temp = arr_begin; temp != arr_end; ++temp) {  // 使用指针遍历数组
        *temp *= r;  // 调整数组值
    }
}
