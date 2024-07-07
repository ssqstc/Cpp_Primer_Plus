#include "iostream"
using namespace std;

const int ArSize = 20;
int main()
{
    long long factorials[ArSize];
    factorials[0] = factorials[1] = 1;
    for (int i = 2; i < ArSize; ++i) {
        factorials[i] = i * factorials[i-1];
    }
    for (int i = 0; i < ArSize; ++i) {
        cout << i << "! = " << factorials[i] << endl;
    }

    return 0;
}