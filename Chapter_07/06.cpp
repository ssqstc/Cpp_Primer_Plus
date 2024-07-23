#include "iostream"
using namespace std;

/*
 * 本代码主要学习指针和数组的关系
 * - 知识点：
 *   - 函数参数传递数组，实际上是传递指向数组首元素的指针
 *   - 使用指针进行数组元素的访问和操作
 * - 注意点：
 *   - sizeof操作符在不同上下文中对数组和指针的作用不同
 *   - 传递给函数的数组参数实际上是指针，因此sizeof操作符在函数中返回指针的大小，而不是数组的大小
 */

int sum_arr(int arr[], int n);    // 函数声明，计算数组元素的总和
const int ArSize = 8;             // 定义常量数组大小

int main(){
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};    // 初始化数组
    cout << "cookies address:" << cookies << endl;          // 输出数组地址
    cout << "size of cookies:" << sizeof cookies << endl;   // 输出数组大小

    int sum = sum_arr(cookies, ArSize);                     // 计算并输出数组所有元素的总和
    cout << "Total cookies eaten: " << sum << endl;         // 输出总和

    sum = sum_arr(cookies, 3);                              // 计算并输出数组前三个元素的总和
    cout << "First three eater ate: " << sum << endl;       // 输出总和

    sum = sum_arr(cookies + 4, 4);                          // 计算并输出数组后四个元素的总和
    cout << "Last four eater ate: " << sum << endl;         // 输出总和
    return 0;
}

int sum_arr(int arr[], int n){  // 计算数组元素的总和
    int total = 0;
    cout << "arr address:" << arr << endl;    // 输出数组地址
    cout << "size of arr:" << sizeof arr << endl;   // 输出指针大小

    for (int i = 0; i < n; ++i) {
        total += arr[i];  // 累加数组元素
    }
    return total;  // 返回总和
}
