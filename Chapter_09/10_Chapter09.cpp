#include "iostream"
#include "new"
using namespace std;

/*
 * 知识点总结：
 * - `new` 运算符：用于在堆上动态分配内存。
 * - 定位 `new` 运算符：在预先分配的内存缓冲区中分配对象。
 * - 静态数组：用于存储固定大小的字符数组。
 *
 * 注意点：
 * - 定位 `new` 的使用需要预先分配足够的内存。
 * - 定位 `new` 不会调用 `delete`，需要手动处理内存管理。
 * - 注意指针的内存地址和缓冲区的对齐。
 */

const int BUF = 512; // 缓冲区大小
const int N = 5; // 数组大小
char buffer[BUF]; // 定义缓冲区
int main(){
    double *pd1, *pd2; // 定义双精度浮点型指针
    int i;
    cout << "Calling new and placement new: " << endl; // 调用 new 和定位 new
    pd1 = new double[N]; // 在堆上分配内存
    pd2 = new(buffer) double[N]; // 在缓冲区中分配内存
    for (i = 0; i < N; ++i) {
        pd2[i] = pd1[i] = 1000 + 20.0 * i; // 初始化数组元素
    }
    cout << "pd1 = " << pd1 << ", buffer = " << (void *)buffer << endl; // 输出指针地址
    for (i = 0; i < N; ++i) {
        cout << pd1[i] << " at " << &pd1[i] << "; "; // 输出 pd1 的值和地址
        cout << pd2[i] << " at " << &pd2[i] << endl; // 输出 pd2 的值和地址
    }

    cout << "\nCalling new and placement new a second time: " << endl; // 第二次调用 new 和定位 new
    double *pd3, *pd4; // 定义新的指针
    pd3 = new double[N]; // 在堆上分配内存
    pd4 = new(buffer) double[N]; // 在缓冲区中再次分配内存
    for (i = 0; i < N; ++i) {
        pd4[i] = pd3[i] = 1000 + 40.0 * i; // 初始化数组元素
    }
    for (i = 0; i < N; ++i) {
        cout << pd3[i] << " at " << &pd3[i] << "; "; // 输出 pd3 的值和地址
        cout << pd4[i] << " at " << &pd4[i] << endl; // 输出 pd4 的值和地址
    }

    cout << "\nCalling new and placement new a third time: " << endl; // 第三次调用 new 和定位 new
    delete []pd1; // 释放 pd1 的内存
    pd1 = new double[N]; // 在堆上重新分配内存
    pd2 = new(buffer + N * sizeof(double)) double[N]; // 在缓冲区的不同位置分配内存
    for (i = 0; i < N; ++i) {
        pd2[i] = pd1[i] = 1000 + 60.0 * i; // 初始化数组元素
    }
    for (i = 0; i < N; ++i) {
        cout << pd1[i] << " at " << &pd1[i] << "; "; // 输出 pd1 的值和地址
        cout << pd2[i] << " at " << &pd2[i] << endl; // 输出 pd2 的值和地址
    }

    delete[] pd1; // 释放 pd1 的内存
    delete[] pd3; // 释放 pd3 的内存
    return 0;
}
