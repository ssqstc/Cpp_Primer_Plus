#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 函数指针：如何定义和使用函数指针。
 * 2. 数组：函数指针数组的定义和使用。
 * 3. 函数调用：通过函数指针调用函数。
 *
 * 注意点：
 * 1. 输入验证：确保用户输入的数据是有效的。
 * 2. 函数指针：确保指针指向有效的函数。
 * 3. 数组边界：访问数组时注意边界，防止越界。
 * 4. 除法运算：除数不能为0，防止除零错误。
 */

// 函数声明
double calculate(double a, double b, double (*pa)(double, double));
double add(double x, double y);
double reduce(double x, double y);
double take(double x, double y);
double remove(double x, double y);

int main(){
    double num1, num2;
    // 定义一个函数指针数组
    double (*pf[4])(double, double) = {add, reduce, take, remove};

    cout << "Enter two number: \n";
    // 循环输入两个数字
    while (cin >> num1 >> num2){
        for (int i = 0; i < 4; ++i) {
            // 调用 calculate 函数并输出结果
            cout << calculate(num1, num2, pf[i]) << endl;
        }
        cout << "Next two number: \n";
    }
    return 0;
}

// 计算函数，使用函数指针调用对应的运算函数
double calculate(double a, double b, double (*pa)(double, double)){
    return pa(a, b);
}

// 四个运算函数
double add(double x, double y){
    return x + y;
}

double reduce(double x, double y){
    return x - y;
}

double take(double x, double y){
    return x * y;
}

double remove(double x, double y){
    if (y == 0) {
        cout << "Division by zero error!" << endl;
        return 0; // 防止除零错误
    }
    return x / y;
}
