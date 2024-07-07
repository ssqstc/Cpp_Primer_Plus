#include "iostream"
using namespace std;

// &取址运算符
int main()
{
    int dounts = 6;
    double cups = 4.5;
    cout << "dounts的值:" << dounts << "\t" << "dounts的地址:" << &dounts << endl;
    cout << "cups的值:" << cups << "\t" << "cups的地址:" << &cups << endl;
    return 0;
}