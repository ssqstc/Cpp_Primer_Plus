#include "iostream"
using namespace std;

int sum_arr(int arr[], int n);      // int sum_arr(int * arr, int n); 正规写法  int arr[]是指针 只有在函数头或者函数原型中才可以这样书写
const int ArSize = 8;
int main(){
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    cout << "cookies address:" << cookies << endl;    // 0x16d1c76c0 打印cookies数组地址 arr地址与cookies地址相同 说明传递的是数组指针
    cout << "size of cookies:" << sizeof cookies << endl;   // 32 打印cookies数组大小

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;     // 全家吃了多少饼干

    sum = sum_arr(cookies, 3);
    cout << "First three eater ate: " << sum << endl;   // 前三人吃了多少饼干

    sum = sum_arr(cookies + 4, 4);
    cout << "Last four eater ate: " << sum << endl;     // 后四人吃了多少饼干
    return 0;
}

int sum_arr(int arr[], int n){  // int代表元素大小4个字节  arr代表数组起始地址  n代表数组个数
    int total = 0;
    cout << "arr address:" << arr << endl;    // 0x16d1c76c0 输出arr数组地址 arr地址与cookies地址相同 说明传递的是数组指针
    cout << "size of arr:" << sizeof arr << endl;   // 8 打印arr数组大小（实际输出的是指针在内存空间占用的大小）

    for (int i = 0; i < n; ++i) {
        total += arr[i];
    }
    return total;
}