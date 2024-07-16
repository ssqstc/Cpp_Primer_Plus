#include "iostream"
using namespace std;

/*
这个程序展示了默认参数、静态局部变量以及函数重载的用法。
主要知识点和注意事项：
1. 默认参数的使用。
2. 静态局部变量的作用范围和生命周期。
3. 函数重载的规则和应用。

注意：
1. 默认参数在函数声明时设置，可以在调用时省略。
2. 静态局部变量在函数内声明，但在多次调用之间保持其值。
3. 函数重载需要注意参数的类型和顺序。
*/

// 函数声明，带有默认参数 n
void print(const char arr[], int n = 0);

int main(){
    char str[10] = "ssqstc"; // 定义并初始化一个字符数组
    print("dadada"); // 使用默认参数调用函数
    print(str, 5); // 显式指定参数调用函数

    return 0;
}

// 函数定义
void print(const char arr[], int n){
    static int number = 0; // 静态局部变量，在多次调用之间保持其值
    number++;
    if (0 == n){
        cout << arr << endl; // 如果 n 为 0，输出整个字符串
    } else {
        for (int i = 0; i < number; ++i) { // 根据静态变量 number 输出多次
            cout << arr << endl;
        }
    }
}
