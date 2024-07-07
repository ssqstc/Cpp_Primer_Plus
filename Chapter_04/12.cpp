#include "iostream"
using namespace std;

int main()
{
    // 初始化一个整型变量updates，并赋值为6
    int updates = 6;
    // 定义一个整型指针P_updates，用于指向变量updates
    int *P_updates;
    // 将指针P_updates指向变量updates的地址
    P_updates = &updates;

    // 输出变量updates的值
    cout << "update的值:" << updates << endl;
    // 输出变量updates的地址
    cout << "update地址:" << &updates << endl;
    // 输出指针P_updates的地址
    cout << "P_update地址:" << P_updates << endl;
    // 通过指针P_updates输出变量updates的值
    cout << "P_update的值:" << *P_updates << endl;

    // 通过指针P_updates对变量updates加1
    *P_updates += 1;
    // 输出加1后的变量updates的值
    cout << "P_updates自加一后，update的值:" << updates << endl;
    return 0;
}
