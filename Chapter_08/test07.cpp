#include "iostream"
using namespace std;

struct debts {
    char name[50];
    double amount;
};

/*
该程序通过模板函数 SumArray 计算不同类型数组元素的总和。
主要知识点和注意事项：
1. 模板函数的定义与使用。
2. 模板函数的重载。
3. 数组与指针数组的处理。

注意：
1. 区分模板函数的不同参数类型，确保匹配正确的函数。
2. 在指针数组的处理时，注意正确解引用指针。
*/

// 模板函数声明，计算数组元素的总和
template <typename T>
T SumArray(T arr[], int n);

// 模板函数重载声明，计算指针数组元素的总和
template <typename T>
T SumArray(T *arr[], int n);

int main() {
    int things[6] = {13, 31, 103, 301, 310, 130}; // 整型数组

    struct debts mr_E[3] = { // debts 结构体数组
            {"Rick", 2400.0},
            {"Jack", 1300.0},
            {"Rose", 1800.0}
    };

    double *pd[3];
    for (int i = 0; i < 3; ++i) {
        pd[i] = &mr_E[i].amount; // 将结构体数组的 amount 成员的地址存入指针数组
    }

    // 输出整型数组元素的总和
    cout << SumArray(things, 6) << endl; // "13, 31, 103, 301, 310, 130" 整型数组元素的总和

    // 输出指针数组元素的总和
    cout << SumArray(pd, 3) << endl; // "2400.0, 1300.0, 1800.0" 指针数组元素的总和

    return 0;
}

// 模板函数定义，计算数组元素的总和
template <typename T>
T SumArray(T arr[], int n) {
    T temp = 0;
    for (int i = 0; i < n; ++i) {
        temp += arr[i]; // 累加数组元素的值
    }
    return temp;
}

// 模板函数重载定义，计算指针数组元素的总和
template <typename T>
T SumArray(T *arr[], int n) {
    T temp = 0;
    for (int i = 0; i < n; ++i) {
        temp += *arr[i]; // 累加解引用后的指针数组元素的值
    }
    return temp;
}
