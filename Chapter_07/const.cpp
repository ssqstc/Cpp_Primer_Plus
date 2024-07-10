#include "iostream"
using namespace std;

// const int *pt; == int const *pt;
// int *const pt;
//const int *const pt;

int main(){
    int n = 10;
    int *pt = &n;

    cout << "1):n = " << n << endl;     // 1):n = 10
    *pt = 20;                           // 通过指针修改值
    cout << "2):n = " << n << endl;     // 2):n = 20

    cout << "****************************" << endl;

    int n2 = 20;
    const int *pt2 = &n2;
    cout << "1):n2 = " << n2 << endl;     // 1):n2 = 20
//    *pt2 = 30;                          // 指针被const修饰 无法通过指针修改值
    n2 = 30;
    cout << "2):n2 = " << n2 << endl;     // 2):n2 = 30

    int m = 100;
    pt2 = &m;                           // 可以修改指针指向
    cout << "*pt2 = " << *pt2 << endl;  // *pt2 = 100
    cout << "m = " << m << endl;        // m = 100

    cout << "****************************" << endl;

    int a = 10;
    int b = 200;
    int *const pt3 = &a;
    cout << "1):a = " << a << endl;     // 1):a = 10
    *pt3 = 50;                          // 可以修改数值
//    pt3 = &b;                         // 无法修改指向
    cout << "2):a = " << a << endl;     // 2):a = 50

    return 0;
}