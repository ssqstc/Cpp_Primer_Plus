#include "iostream"
using namespace std;

/*
这个程序展示了模板函数的重载和指针数组的使用。
主要知识点和注意事项：
1. 模板函数的定义和重载。
2. 指针数组和结构体数组的使用。
3. 函数调用时模板匹配的优先级。

注意：
1. 模板函数可以被重载以处理不同类型的参数。
2. 使用指针数组时要注意指针的正确引用和解引用。
3. 理解函数调用时模板的匹配规则，可以帮助避免错误调用。
*/

// 定义结构体 debts，用于存储债务信息
struct debts{
    char name[50];
    double amount;
};

// 模板函数的定义，用于显示数组元素，适用于基本类型数组
template <typename T>
void ShowArray(T arr[], int n);

// 模板函数的重载，用于显示指针数组元素，适用于指针类型数组
template <typename T>
void ShowArray(T *arr[], int n);

int main(){
    int things[6] = {13, 31, 103, 301, 310, 130}; // 定义并初始化一个整型数组

    // 定义并初始化一个结构体数组，存储债务信息
    struct debts mr_E[3] = {
            {"Rick", 2400.0},
            {"Jack", 1300.0},
            {"Rose", 1800.0}
    };

    double *pd[3]; // 定义一个指向 double 类型的指针数组
    for (int i = 0; i < 3; ++i) {
        pd[i] = &mr_E[i].amount; // 将每个结构体的 amount 成员的地址存储在指针数组中
    }

    ShowArray(things, 6); // 调用模板函数，显示整型数组
    ShowArray(pd, 3); // 调用模板函数重载，显示指针数组指向的值

    return 0;
}

// 模板函数的定义，用于显示基本类型数组元素
template <typename T>
void ShowArray(T arr[], int n){
    cout << "template A:" << endl; // 输出模板 A 的提示信息
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ' ; // 显示数组元素
    }
    cout << endl;
}

// 模板函数的重载，用于显示指针数组指向的值
template <typename T>
void ShowArray(T *arr[], int n){
    cout << "template B:" << endl; // 输出模板 B 的提示信息
    for (int i = 0; i < n; ++i) {
        cout << *arr[i] << ' '; // 显示指针数组指向的值
    }
    cout << endl;
}
