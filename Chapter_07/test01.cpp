#include "iostream"
using namespace std;

double harmonic_mean(double num1, double num2);
int main(){
    double number1, number2;        // 定义两个变量
    cout << "Enter two number, until one if the them is zero:" << endl;     // 提示信息
    while (cin >> number1 >> number2 && number1 != 0 && number2!= 0){       // 输入值为0退出
        cout << "harmonic mean = " << harmonic_mean(number1, number2) << endl;      // 打印输出
    }


    return 0;
}
double harmonic_mean(double num1, double num2){     // 定义函数 返回调和平均数
    return 2.0 * num1 * num2 / (num1 + num2);
}