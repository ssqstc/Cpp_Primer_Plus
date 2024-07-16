#include "iostream"
using namespace std;

/*
这个程序展示了模板函数的使用以及模板特化，通过模板函数 maxn 找出数组中的最大值，
并通过特化模板实现了对字符串数组的处理。
主要知识点和注意事项：
1. 模板函数的定义与使用。
2. 模板特化。
3. 数组作为函数参数的传递。
4. 循环与条件判断。

注意：
1. 确保模板函数和模板特化的参数类型正确匹配。
2. 字符串数组的特化处理需要使用 strlen 函数计算字符串长度。
*/

// 模板函数声明，返回数组中最大值
template <typename T>
T maxn(T arr[], int n);

// 模板特化声明，返回字符串数组中最长字符串
template <>
const char *maxn(const char *arr[], int n);

int main() {
    int arr_int[6] = {1, 2, 3, 4, 5, 6}; // 整型数组
    double arr_double[4] = {1.1, 2.2, 3.3, 4.4}; // 双精度浮点型数组
    const char *arr_char[5] = {"ssqstc", "dadada", "lalala", "tiancai", "woaini"}; // 字符串数组

    // 输出整型数组中的最大值
    cout << "The max value of int arr: " << maxn(arr_int, 6) << endl; // "The max value of int arr:"（整型数组的最大值）

    // 输出双精度浮点型数组中的最大值
    cout << "The max value of double arr: " << maxn(arr_double, 4) << endl; // "The max value of double arr:"（双精度浮点数组的最大值）

    // 输出字符串数组中最长的字符串
    cout << "The max value of char arr: " << maxn(arr_char, 5) << endl; // "The max value of char arr:"（字符串数组中最长的字符串）

    return 0;
}

// 模板函数定义，返回数组中最大值
template < typename T>
T maxn(T arr[], int n) {
    T max = arr[0]; // 假设第一个元素为最大值
    for (int i = 1; i < n; ++i) { // 从第二个元素开始遍历数组
        if (arr[i] > max) { // 如果当前元素大于当前最大值
            max = arr[i]; // 更新最大值
        }
    }
    return max; // 返回最大值
}

// 模板特化定义，返回字符串数组中最长字符串
template <>
const char *maxn(const char *arr[], int n) {
    int count = 0; // 记录最长字符串的索引
    for (int i = 1; i < n; ++i) { // 从第二个字符串开始遍历数组
        if (strlen(arr[i]) > strlen(arr[count])) { // 如果当前字符串长度大于当前最长字符串长度
            count = i; // 更新最长字符串的索引
        }
    }
    return arr[count]; // 返回最长的字符串
}
