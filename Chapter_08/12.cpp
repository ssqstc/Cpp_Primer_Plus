#include "iostream"
using namespace std;
// 函数模版重载
template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T a[], T b[], int n);

void show(int arr[], int n);

const int LIM = 8;

int main(){
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    Swap(i, j); // 交换整数变量 i 和 j 的值
    cout << "After swap, now i, j = " << i << ", " << j << "." << endl;

    cout << "---------------------------------------------------" << endl;

    int d1[LIM] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[LIM] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays: " << endl;
    show(d1, LIM);
    show(d2, LIM);
    Swap(d1, d2, LIM);
    cout << "Swapped arrays: " << endl;
    show(d1, LIM);
    show(d2, LIM);
    return 0;
}

// 模板函数的定义，用于交换两个同类型变量的值
template <typename T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void Swap(T a[], T b[], int n){
    T temp;
    for (int i = 0; i < n; ++i) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void show(int arr[], int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
