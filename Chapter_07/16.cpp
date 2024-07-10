#include "iostream"
using namespace std;
// 递归
void countdown(int n);

int main(){
    countdown(4);

    return 0;
}
void countdown(int n){
    cout << "Counting down...." << n << " , n at address = " << &n << endl;   // statement1
    if (n > 0){
        countdown(n - 1);       // 每次递归的n都是独立的 地址均不同
    }
    cout << n << ": Kadoom" << " , n at address = " << &n << endl;        // statement2
}