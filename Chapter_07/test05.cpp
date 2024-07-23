#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 递归函数：递归调用自身实现阶乘计算。
 * 2. 基本情况：处理递归基条件以终止递归。
 * 3. 大整数处理：使用 `long long` 类型处理较大的阶乘结果。
 *
 * 注意点：
 * 1. 输入验证：确保用户输入有效的非负整数。
 * 2. 递归深度：递归调用的深度有限制，应注意避免栈溢出。
 */

long long factorial(unsigned int n); // 声明一个计算阶乘的函数

int main(){
    int n;
    cout << "Enter a number for factorial: ";   // 提示用户输入一个数字计算阶乘
    while (cin >> n){   // 不断读取用户输入的数字
        cout << n << "! = " << factorial(n) << endl;  // 调用 factorial 函数计算阶乘并输出结果
        cout << "Enter next number for factorial: ";  // 提示用户输入下一个数字
    }
    return 0;
}

long long factorial(unsigned int n){  // 定义计算阶乘的递归函数
    if (0 == n){   // 递归基条件：当 n 为 0 时，返回 1
        return 1;
    } else{   // 递归调用：n * (n-1) 的阶乘
        return n * factorial(n - 1);  // 调用自身来计算 n 的阶乘
    }
}
