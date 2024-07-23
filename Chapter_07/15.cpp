#include "iostream"
#include "array"
using namespace std;

/*
 * 知识点：
 * 1. 标准库array：使用std::array容器处理固定大小的数组。
 * 2. 指针：通过指针传递数组到函数并修改其内容。
 * 3. 输入输出：使用cin和cout处理用户输入和输出结果。
 *
 * 注意点：
 * 1. 数组大小：std::array的大小在编译时确定，适用于固定大小数组。
 * 2. 指针解引用：在函数中使用指针解引用访问和修改数组内容。
 * 3. 数组传递：传递指针确保函数可以修改数组内容。
 */

const int Seasons = 4;  // 季节数目
const array<string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};  // 季节名称数组

void fill(array<double, Seasons> *pa);  // 填充数组的函数声明
void show(const array<double, Seasons> *da);  // 显示数组内容的函数声明

int main() {
    array<double, Seasons> expenses{};  // 季节费用数组

    fill(&expenses);  // 调用函数填充费用数组
    show(&expenses);  // 调用函数显示费用数组
    return 0;
}

void fill(array<double, Seasons> *pa) {  // 填充费用数组的函数定义 array可以像使用数组一样使用 array对象的指针并不能像数组一样操作
    for (int i = 0; i < Seasons; ++i) {  // 此时pa是array对象的指针 但pa并不是array对象
        cout << "Enter " << Snames[i] << " expenses: ";  // 提示输入对应季节的费用
        cin >> (*pa)[i];  // 使用指针解引用存储输入的费用 pa是array对象的指针 指针里面的值就是array对象 (*pa)取值 取出array对象
    }                       // ！！！ *pa[i]是错的 方括号[]结合的优先级比*高
}

void show(const array<double, Seasons> *da) {  // 显示费用数组内容的函数定义
    double total = 0.0;  // 初始化总费用为0
    cout << "EXPENSES:" << endl;  // 输出标题
    for (int i = 0; i < Seasons; ++i) {
        cout << Snames[i] << " expenses: $" << (*da)[i] << endl;  // 输出对应季节的费用
        total += (*da)[i];  // 累加总费用
    }
    cout << "Total expenses: $" << total << endl;  // 输出总费用
}
