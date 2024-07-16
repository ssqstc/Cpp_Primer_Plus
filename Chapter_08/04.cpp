#include "iostream"
using namespace std;
// 引用作为函数参数
void swapr(int &a, int &b); // 使用引用进行交换的函数声明
void swapp(int *pa, int *pb); // 使用指针进行交换的函数声明
void swapv(int a, int b); // 使用值传递进行交换的函数声明

int main() {
    int wallet1 = 300; // 定义并初始化变量 wallet1
    int wallet2 = 350; // 定义并初始化变量 wallet2

    // 输出初始值
    cout << "wallet1 = " << wallet1 << endl; // wallet1 = 300
    cout << "wallet2 = " << wallet2 << endl; // wallet2 = 350

    cout << "Using reference to swap contents:" << endl; // 使用引用交换变量内容
    swapr(wallet1, wallet2); // 调用引用交换函数
    cout << "wallet1 = " << wallet1 << endl; // wallet1 = 350
    cout << "wallet2 = " << wallet2 << endl; // wallet2 = 300

    cout << "Using pointers to swap contents:" << endl; // 使用指针交换变量内容
    swapp(&wallet1, &wallet2); // 调用指针交换函数
    cout << "wallet1 = " << wallet1 << endl; // wallet1 = 300
    cout << "wallet2 = " << wallet2 << endl; // wallet2 = 350

    cout << "Trying to use passing by value:" << endl; // 使用值传递交换变量内容
    swapv(wallet1, wallet2); // 调用值传递交换函数
    cout << "wallet1 = " << wallet1 << endl; // wallet1 = 300
    cout << "wallet2 = " << wallet2 << endl; // wallet2 = 350

    return 0;
}

// 使用引用交换变量内容的函数定义
void swapr(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 使用指针交换变量内容的函数定义
void swapp(int *pa, int *pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

// 使用值传递交换变量内容的函数定义
void swapv(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
