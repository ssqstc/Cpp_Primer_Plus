#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 引用传递：通过引用传递参数，使得函数内部对参数的修改会影响到实参。
 * 2. 指针传递：通过指针传递参数，实现同引用类似的效果。
 * 3. 值传递：通过值传递参数，函数内部对参数的修改不会影响到实参。
 *
 * 注意点：
 * 1. 引用传递：引用必须初始化，且引用的变量不能改变其绑定的对象。
 * 2. 指针传递：需要传递变量的地址，函数内通过解引用操作访问实际变量。
 * 3. 值传递：函数内的参数修改仅限于函数内部，实际传递的是参数的副本。
 */

void swapr(int &a, int &b);  // 使用引用进行交换
void swapp(int *pa, int *pb); // 使用指针进行交换
void swapv(int a, int b);  // 使用值传递进行交换

int main() {
    int wallet1 = 300;  // 定义整数变量 wallet1 并初始化为 300
    int wallet2 = 350;  // 定义整数变量 wallet2 并初始化为 350

    cout << "wallet1 = " << wallet1 << endl;  // 输出 wallet1 的初始值
    cout << "wallet2 = " << wallet2 << endl;  // 输出 wallet2 的初始值

    cout << "Using reference to swap contents:" << endl;  // 使用引用交换
    swapr(wallet1, wallet2);  // 调用 swapr 函数
    cout << "wallet1 = " << wallet1 << endl;  // 输出交换后的 wallet1 值
    cout << "wallet2 = " << wallet2 << endl;  // 输出交换后的 wallet2 值

    cout << "Using pointers to swap contents:" << endl;  // 使用指针交换
    swapp(&wallet1, &wallet2);  // 调用 swapp 函数
    cout << "wallet1 = " << wallet1 << endl;  // 输出交换后的 wallet1 值
    cout << "wallet2 = " << wallet2 << endl;  // 输出交换后的 wallet2 值

    cout << "Trying to use passing by value:" << endl;  // 尝试使用值传递
    swapv(wallet1, wallet2);  // 调用 swapv 函数
    cout << "wallet1 = " << wallet1 << endl;  // 输出交换后的 wallet1 值
    cout << "wallet2 = " << wallet2 << endl;  // 输出交换后的 wallet2 值

    return 0;
}

// 使用引用进行交换
void swapr(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 使用指针进行交换
void swapp(int *pa, int *pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

// 使用值传递进行交换
void swapv(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
