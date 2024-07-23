#include "iostream"
#include "array"
using namespace std;

/*
 * 知识点：
 * 1. 指针与数组：通过指针操作数组。
 * 2. 输入输出：使用 `cin` 和 `cout` 进行用户交互。
 * 3. 常量指针：使用 `const char *` 指向字符串常量。
 * 4. 函数传参：通过指针传递数组并操作。
 *
 * 注意点：
 * 1. 输入验证：应确保用户输入有效数值。
 * 2. 数组边界：操作数组时注意边界，防止越界访问。
 * 3. 指针操作：避免指针操作错误，确保指针在有效范围内。
 */

const int Seasons = 4;  // 季节数量
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"}; // 季节名称

// 函数声明
void fill(double *arr, int len); // 填充数组
void show(const double *arr, int len); // 显示数组内容

int main(){
    double expenses[Seasons]{};  // 定义并初始化一个数组存储每个季节的花费

    fill(expenses, Seasons); // 填充数组
    show(expenses,Seasons); // 显示数组内容
    return 0;
}

void fill(double *arr, int len){ // 填充数组函数
    for (int i = 0; i < len; ++i) {
        cout << "Enter " << Snames[i] << " expenses: "; // 提示输入每个季节的花费
        cin >> arr[i]; // 存储用户输入到数组中
    }
}

void show(const double *arr, int len){ // 显示数组内容函数
    double total = 0.0; // 初始化总花费
    cout << "EXPENSES:" << endl;
    for (int i = 0; i < len; ++i) {
        cout << Snames[i] << " expenses: $" << arr[i] << endl; // 输出每个季节的花费
        total += arr[i]; // 累加每个季节的花费
    }
    cout << "Total expenses: $" << total << endl; // 输出总花费
}
