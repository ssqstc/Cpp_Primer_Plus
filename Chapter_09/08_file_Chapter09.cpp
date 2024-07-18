#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 变量作用域和链接类型：了解全局变量、静态变量和外部变量的作用域和链接属性。
 * - `extern`关键字：用于声明外部变量，使得多个文件可以共享同一个全局变量。
 * - `static`关键字：用于定义静态变量，使得变量在文件内部具有内部链接属性。
 *
 * 注意点：
 * - 全局变量和静态变量的初始化和使用。
 * - `extern`和`static`关键字的正确使用。
 */

extern int tom; // 声明外部变量 tom
static int dick = 10; // 定义具有内部链接的静态变量 dick
int harry = 200; // 定义全局变量 harry

void remote_access(){
    cout << "remote_access() reports the following addresses: " << endl; // remote_access() 报告以下地址：
    cout << "&tom = " << &tom << ", &dick = " << &dick << ", &harry = " << &harry << endl; // 输出变量 tom、dick 和 harry 的地址
}