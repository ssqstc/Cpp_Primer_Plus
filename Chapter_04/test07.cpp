#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 动态内存分配：
   - 使用 `new` 运算符为结构体变量分配内存，使用完毕后需使用 `delete` 释放内存。
2. 结构体指针访问：
   - 通过箭头操作符 `->` 访问结构体指针的成员。
3. 输入处理：
   - 使用 `cin.get()` 读取并丢弃前一个输入留下的换行符，以便正确读取后续字符串。
*/

struct William_Wingate
{
    char name[50];    // 披萨公司名称
    double diameter;  // 披萨直径
    double weight;    // 披萨重量
};

int main()
{
    William_Wingate *information = new William_Wingate;  // 动态分配内存

    cout << "Enter pizza diameter: ";  // 输出提示信息：输入披萨直径
    cin >> information->diameter;  // 输入披萨直径

    cout << "Enter pizza company name: ";  // 输出提示信息：输入披萨公司名称
    cin.get();  // 读取并丢弃前一个输入留下的换行符
    cin.getline(information->name, 50);  // 输入公司名称

    cout << "Enter pizza weight: ";  // 输出提示信息：输入披萨重量
    cin >> information->weight;  // 输入披萨重量

    // 输出输入的信息
    cout << "Pizza company name: " << information->name
         << " ,pizza diameter: " << information->diameter
         << " ,pizza weight: " << information->weight;

    delete information;  // 释放动态分配的内存
    return 0;  // 程序结束
}
