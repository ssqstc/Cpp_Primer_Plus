#include "iostream"
using namespace std;

const int SIZE = 5; // 数组大小常量

/*
这个程序展示了模板函数的使用，通过模板函数 max5 找出数组中的最大值。
主要知识点和注意事项：
1. 模板函数的定义与使用。
2. 数组作为函数参数的传递。
3. 循环与条件判断。

注意：
1. 确保模板函数的参数类型正确匹配。
2. 数组大小是常量，需要保证传入数组的大小与常量 SIZE 相同。
*/

// 模板函数声明，返回数组中最大值
template <typename T>
T max5(const T arr[SIZE]);

int main() {
    int arr_int[5] = {1, 2, 3, 4, 5}; // 整型数组
    double arr_double[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; // 双精度浮点型数组

    // 输出整型数组中的最大值
    cout << "The max value of int arr: " << max5(arr_int) << endl; // "The max value of int arr:"（整型数组的最大值）

    // 输出双精度浮点型数组中的最大值
    cout << "The max value of double arr: " << max5(arr_double) << endl; // "The max value of double arr:"（双精度浮点数组的最大值）

    return 0;
}

// 模板函数定义，返回数组中最大值
template <typename T>
T max5(const T arr[SIZE]) {
    T max = arr[0]; // 假设第一个元素为最大值
    for (int i = 1; i < SIZE; ++i) { // 从第二个元素开始遍历数组
        if (arr[i] > max) { // 如果当前元素大于当前最大值
            max = arr[i]; // 更新最大值
        }
    }
    return max; // 返回最大值
}
