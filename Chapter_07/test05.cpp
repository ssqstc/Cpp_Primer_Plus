#include "iostream"
using namespace std;

long long factorial(unsigned int n);

int main(){
    int n;
    cout << "Enter a number for factorial: ";   // 输入一个阶乘数值
    while (cin >> n){
        cout << n << "! = " << factorial(n) << endl;
        cout << "Enter next number for factorial: ";
    }
    return 0;
}
long long factorial(unsigned int n){
    if (0 == n){
        return 1;
    } else{
        return n * factorial(n - 1);
    }
}