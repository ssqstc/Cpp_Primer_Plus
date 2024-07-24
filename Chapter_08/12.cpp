#include "iostream"
using namespace std;

/*
知识点：
1. 模板函数：通过模板实现通用的交换函数和数组交换函数。
2. 函数重载：同名的 Swap 函数，分别用于交换单个变量和数组元素。
3. 指针与引用：通过引用参数实现对变量的直接修改，通过指针实现数组元素的交换。
4. 数组操作：通过遍历数组实现元素交换和显示。

注意点：
1. 模板函数：理解模板函数的定义与使用方法，注意模板参数的传递。
2. 引用参数：使用引用参数时，注意避免传递常量或临时对象。
3. 数组边界：在处理数组时，注意数组的边界，避免越界访问。
*/

template <typename T>
void Swap(T &a, T &b); // 函数模板：交换两个变量的值

template <typename T>
void Swap(T a[], T b[], int n); // 函数模板：交换两个数组的元素

void show(int arr[], int n); // 显示数组内容

const int LIM = 8; // 定义常量数组大小

int main(){
    int i = 10, j = 20; // 定义两个整数
    cout << "i, j = " << i << ", " << j << "." << endl;
    Swap(i, j); // 交换两个整数的值
    cout << "After swap, now i, j = " << i << ", " << j << "." << endl;

    cout << "---------------------------------------------------" << endl;

    int d1[LIM] = {0, 7, 0, 4, 1, 7, 7, 6}; // 定义第一个数组
    int d2[LIM] = {0, 7, 2, 0, 1, 9, 6, 9}; // 定义第二个数组
    cout << "Original arrays: " << endl;
    show(d1, LIM); // 显示第一个数组的内容
    show(d2, LIM); // 显示第二个数组的内容
    Swap(d1, d2, LIM); // 交换两个数组的元素
    cout << "Swapped arrays: " << endl;
    show(d1, LIM); // 显示交换后的第一个数组
    show(d2, LIM); // 显示交换后的第二个数组
    return 0;
}

template <typename T>
void Swap(T &a, T &b){ // 交换两个变量的值
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void Swap(T a[], T b[], int n){ // 交换两个数组的元素
    T temp;
    for (int i = 0; i < n; ++i) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void show(int arr[], int n){ // 显示数组内容
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
