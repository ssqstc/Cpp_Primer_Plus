#include "iostream"
using namespace std;

int main()
{
    int x;
    cout << "The expression x = 100 has the value: ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;
    cout << "The expression x < 3 has the value: ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value: ";
    cout << (x > 3) << endl;
    cout << "------------------------------------\n";
    cout.setf(ios_base::boolalpha);     // cout显示bool值之前将他们转化为int，使用cout.setf(ios_base::boolalpha)函数，显示true和flase。
    cout << "The expression x < 3 has the value: ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value: ";
    cout << (x > 3) << endl;

    return 0;
}