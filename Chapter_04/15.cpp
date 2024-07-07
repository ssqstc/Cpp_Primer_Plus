#include "iostream"
using namespace std;

int main()
{
    double wages[] = { 10000.0, 20000.0, 30000.0 };
    short stacks[] = {3,2,1};

    double *pw = wages;
    short *ps = &stacks[0];

    cout << "pw = " << pw << ", * pw = " << *pw << endl;
    pw++;
    cout << "pw+1后，pw = " << pw << ", * pw = " << *pw << endl;

    cout << "ps = " << ps << ", * ps = " << *ps << endl;
    ps++;
    cout << "ps+1后，ps = " << ps << ", * ps = " << *ps << endl;

    cout << "stacks[0] = " << stacks[0] << " , stacks[1] = " << stacks[1] << endl;
    cout << "*stacks = " << *stacks << " , *(stacks + 1) = " << *(stacks + 1) << endl;

    cout << "size of wages array = " << sizeof(wages) << endl;// 24 ！在使用sizeof运算符的时候，C++不会将数组名解释为地址，而解释整个数组占用空间。
    cout << "size of pw pointer = " << sizeof(pw) << endl;

    return 0;
}