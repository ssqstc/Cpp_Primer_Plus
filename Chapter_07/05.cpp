#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 数组传递：函数接收数组参数，并对数组进行操作。
 * - 数组遍历：通过循环遍历数组元素并进行累加计算。
 * - 常量声明：使用 const 关键字定义数组大小常量。
 * - int sum_arr(int * arr, int n); 正规写法  int arr[]是指针 只有在函数头或者函数原型中才可以这样书写

 * 注意点：
 * - 数组作为参数传递时，实际上传递的是指针。
 * - 确保数组大小正确传递，避免数组越界访问。
 */
int sum_arr(int arr[], int n);
/*
 * 主函数：演示数组传递和累加计算
 * - 定义并初始化数组
 * - 调用函数计算数组元素的和
 * - 输出结果
 */
int main(){
    const int ArSize = 8; // 数组大小常量
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128}; // 初始化数组

    int sum = sum_arr(cookies, ArSize); // 计算数组元素的和
    cout << "Total cookies eaten: " << sum << endl; // 输出总和

    return 0;
}

/*
 * 计算数组元素的和
 * arr - 数组
 * n - 数组大小
 * 返回数组元素的和
 */
int sum_arr(int arr[], int n){
    int total = 0; // 初始化总和
    for (int i = 0; i < n; ++i) { // 遍历数组
        total += arr[i]; // 累加数组元素
    }
    return total; // 返回总和
}
