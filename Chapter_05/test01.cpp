#include "iostream"
using namespace std;

int main()
{
    int num1, num2, sum = 0;
    cout << "输入两个整数\n";
    cout << "第一个较小的整数：";
    cin >> num1;
    cout << "第二个较大的整数：";
    cin >> num2;
    for (int i = num1; i <= num2; ++i) {
        sum += i;
    }
    cout << num1 << "~" << num2 << "所有整数和为：" << sum;
    return 0;
}