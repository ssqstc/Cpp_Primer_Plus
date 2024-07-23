#include "iostream"
#include "array"
using namespace std;

/*
 * 知识点：
 * 1. 结构体：使用结构体组织相关数据。
 * 2. 指针与结构体：通过指针操作结构体成员。
 * 3. 输入输出：使用 `cin` 和 `cout` 进行用户交互。
 * 4. 函数传参：通过指针传递结构体并操作。
 *
 * 注意点：
 * 1. 输入验证：应确保用户输入有效数值。
 * 2. 数组边界：操作数组时注意边界，防止越界访问。
 * 3. 指针操作：避免指针操作错误，确保指针在有效范围内。
 */

const int Seasons = 4;  // 季节数量
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"}; // 季节名称

struct expenditure {
    double exp[Seasons]; // 存储每个季节花费的数组
};

// 函数声明
void fill2(expenditure *pa2, int len); // 填充结构体数组
void show2(const expenditure *da2, int len); // 显示结构体数组内容

int main(){
    expenditure expenses{};  // 定义并初始化一个结构体存储每个季节的花费

    fill2(&expenses, Seasons); // 填充结构体数组
    show2(&expenses,Seasons); // 显示结构体数组内容
    return 0;
}

void fill2(expenditure *pa2, int len){ // 填充结构体数组函数
    for (int i = 0; i < len; ++i) {
        cout << "Enter " << Snames[i] << " expenses: "; // 提示输入每个季节的花费
        cin >> pa2->exp[i]; // 存储用户输入到结构体数组中
    }
}

void show2(const expenditure *da2, int len){ // 显示结构体数组内容函数
    double total = 0.0; // 初始化总花费
    cout << "EXPENSES:" << endl;
    for (int i = 0; i < len; ++i) {
        cout << Snames[i] << " expenses: $" << da2->exp[i] << endl; // 输出每个季节的花费
        total += da2->exp[i]; // 累加每个季节的花费
    }
    cout << "Total expenses: $" << total << endl; // 输出总花费
}
