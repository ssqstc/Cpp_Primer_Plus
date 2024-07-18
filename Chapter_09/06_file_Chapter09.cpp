#include "06_head_Chapter09.h"
using namespace std;

/*
 * 知识点总结：
 * - 使用外部变量：可以在函数中修改全局变量的值。
 * - 局部变量：在函数内部定义的变量，作用域仅限于该函数。
 * - 作用域解析运算符：用于访问全局变量。
 */

void update(double dt){
    warming += dt;
    cout << "Updating global warming to " << warming << " degrees." << endl; // 将全球变暖更新到 0.4 度。
}

void local(){
    double warming = 0.8;
    cout << "Local warming = " << warming << " degrees." << endl; // 局部变暖 = 0.8 度。
    cout << "But global warming = " << ::warming << " degrees." << endl; // 但全球变暖 = 0.4 度。
    // 作用域解析运算符 放在变量名前 该运算符表示使用变量的全局版本
}
