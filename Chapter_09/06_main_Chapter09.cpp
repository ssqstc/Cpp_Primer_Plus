#include <iostream>
#include "06_head_Chapter09.h"
using namespace std;

/*
 * 知识点总结：
 * - 外部链接：定义具有外部链接的全局变量，可以在多个文件中访问。
 * - 作用域解析运算符：使用`::`来访问全局变量，即使局部变量同名。
 * - 头文件保护符：防止头文件被重复包含。
 *
 * 注意点：
 * - 全局变量在不同文件中的声明和定义。
 * - 头文件保护符的使用方法和必要性。
 */

double warming = 0.3; // 定义具有外部链接能力的全局变量

int main(){
    cout << "Global warming is " << warming << " degrees." << endl; // 全球变暖是 0.3 度。
    update(0.1);
    cout << "Global warming is " << warming << " degrees." << endl; // 全球变暖是 0.4 度。
    local();
    cout << "Global warming is " << warming << " degrees." << endl; // 全球变暖是 0.4 度。

    return 0;
}