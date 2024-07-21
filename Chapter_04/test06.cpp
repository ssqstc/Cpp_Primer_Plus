#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 结构体定义和使用：
   - 定义包含多个数据成员的结构体，并通过结构体变量访问这些成员。
   - 使用 cin.getline() 输入字符串数据，避免读取到多余的换行符。
   - 注意输入输出格式，特别是 double 类型数据的输入输出。
*/

struct William_Wingate
{
    char name[50];    // 披萨公司名称
    double diameter;  // 披萨直径
    double weight;    // 披萨重量
};

int main()
{
    William_Wingate information;  // 定义结构体变量

    cout << "Enter pizza company name: ";  // 输出提示信息：输入披萨公司名称
    cin.getline(information.name, 50);  // 输入公司名称

    cout << "Enter pizza diameter: ";  // 输出提示信息：输入披萨直径
    cin >> information.diameter;  // 输入披萨直径

    cout << "Enter pizza weight: ";  // 输出提示信息：输入披萨重量
    cin >> information.weight;  // 输入披萨重量

    // 输出输入的信息
    cout << "Pizza company name: " << information.name
         << " , pizza diameter: " << information.diameter
         << " , pizza weight: " << information.weight;
    return 0;  // 程序结束
}
