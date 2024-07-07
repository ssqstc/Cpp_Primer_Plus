#include "iostream"
using namespace std;

int main()
{
    double num, sum = 0;
    do {
        cout << "输入一个数字：";
        cin >> num;
        sum += num;
        cout << "目前为止累计和：" << sum << endl;
    } while (num != 0);
    return 0 ;
}